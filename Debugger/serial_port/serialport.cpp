#include "serialport.h"



// 构造函数
SerialPort::SerialPort(QObject *parent) : QObject(parent)
{
    // 多线程配置
    Serial_Thread = new QThread();      // 多线程对象
    moveToThread(Serial_Thread);  // 将当前对象移动到多线程中
    Serial_Thread->start();             // 启动多线程



    // 在新线程启动后执行创建串口
    connect(Serial_Thread, &QThread::started, this, &SerialPort::New_SerialPort);

}

SerialPort::~SerialPort() {
    if (mappedData != nullptr) {
        file->unmap(mappedData);
    }
    if (file != nullptr) {
        file->close();
        delete file;
    }
}

// 清空并映射
void SerialPort::Clear_MappedData() {
    // 取消映射
    if (mappedData != nullptr) {
        file->unmap(mappedData);
    }
    // 清空文件
    file->resize(0);
    // 映射文件
    fileSize = file->size();
    mappedSize = fileSize + 10240;  // 预留10KB空间
    if (file->resize(mappedSize)) {
        mappedData = file->map(0, mappedSize);
        if (mappedData == nullptr) {
            qDebug() << "Memory mapping failed!";
        }
    } else {
        qDebug() << "Resizing file failed!";
    }
}   


/* ------------------------------------------ 文件锁定 ------------------------------------------ */
#ifdef Q_OS_WIN
#include <windows.h>
#elif defined(Q_OS_LINUX)
#include <sys/file.h>
#include <fcntl.h>
#include <unistd.h>
#endif

bool isFileLocked(const QString &filePath) {
#ifdef Q_OS_WIN
    HANDLE hFile = CreateFileW(
        reinterpret_cast<LPCWSTR>(filePath.utf16()), 
        GENERIC_READ | GENERIC_WRITE,
        0,
        NULL,
        OPEN_EXISTING,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        return true;
    } else {
        CloseHandle(hFile);
        return false;
    }
#elif defined(Q_OS_LINUX)
    int fd = open(filePath.toStdString().c_str(), O_RDWR);
    if (fd == -1) {
        return true; // 无法打开文件，可能被锁定
    }

    int result = flock(fd, LOCK_EX | LOCK_NB);
    close(fd);

    return result == -1; // 文件已被锁定
#endif
    return false; // 默认情况下未被锁定
}

/* ------------------------------------------ 文件锁定 END ------------------------------------------ */

// 缓存文件创建
void SerialPort::Cache_File_Create() {
    QString dirPath = QCoreApplication::applicationDirPath() + "/Serial_Assistant_Cfg/Serial_Data";
    QDir dir;
    if (!dir.mkpath(dirPath)) {
        qDebug() << "Failed to create path:" << dirPath;
        return;
    }
    // 尝试清空该目录下的所有文件
    dir.setPath(dirPath);
    dir.setFilter(QDir::Files | QDir::NoDotAndDotDot);
    for (const QFileInfo &info : dir.entryInfoList()) {
        QFile::remove(info.absoluteFilePath());
    }

    QString baseFilePath = dirPath + "/Cache";
    QString filePath;
    int fileIndex = 0;

    // 循环判断文件是否存在及是否被锁定
    while (true) {
        filePath = baseFilePath + (fileIndex == 0 ? ".bin" : QString("_%1.bin").arg(fileIndex));

        QFile testFile(filePath);
        if (testFile.exists()) {
            if (!isFileLocked(filePath)) {
                qDebug() << "File is not locked:" << filePath;
                break;
            } else {
                qDebug() << "File is locked:" << filePath;
            }
        } else {
            qDebug() << "File does not exist and will be created:" << filePath;
            break;
        }
        fileIndex++;
    }



    file = new QFile(filePath);
    if (!file->open(QIODevice::ReadWrite)) {
        qDebug() << "Open file failed!";
        return;
    }

    Clear_MappedData();
}



// 写入新数据到缓存
bool SerialPort::writeDataToCache(const QByteArray& data) {
    if (mappedData == nullptr || file == nullptr) {
        qDebug() << "File not mapped!";
        return false;
    }

    qint64 newSize = fileSize + data.size();
    if (newSize > mappedSize) {
        // 重新映射文件
        Clear_MappedData();
        newSize = fileSize + data.size();
    }

    // 将新数据写入映射的内存中
    memcpy(mappedData + fileSize, data.data(), data.size());
    fileSize = newSize;

    return true;
}

void SerialPort::readDataFromCache() {
    if (mappedData == nullptr) {
        qDebug() << "File not mapped!";
        emit dataRead(QByteArray()); // 发射空数据信号
        return;
    }
    // 读取数据的大小
    int sizeToRead = qMin(128, static_cast<int>(fileSize));

    // 从映射的内存中读取数据
    QByteArray data(reinterpret_cast<char*>(mappedData), sizeToRead);

    // 若读取的数据小于文件大小，则将未读取的数据前移
    if (sizeToRead < fileSize) {
        memmove(mappedData, mappedData + sizeToRead, fileSize - sizeToRead);
        // 重新计算文件大小
        fileSize -= sizeToRead;
    } else {
        fileSize = 0;
    }
    emit dataRead(data); // 发射包含读取数据的信号
}


void SerialPort::New_SerialPort()
{
    // 串口配置
    serialPort = new QSerialPort();   // 串口对象
    // 创建缓存文件并保存映射地址
    Cache_File_Create();

    // 绑定串口接收信号与槽函数
    connect(serialPort, &QSerialPort::readyRead, this, &SerialPort::read_Data);
}




// 串口发送
void SerialPort::Serial_Send_Data(QByteArray data)
{
    serialPort->write(data);            // 发送数据
    serialPort->flush();                // 清空缓存区
    serialPort->waitForBytesWritten(1); // 等待数据发送完毕 1ms
    // 串口发送计数
    emit Serial_Send_Count(data.length()); // 发送计数显示
}

    // 打开文件夹 /Serial_Assistant_Cfg/
    // QString path = QCoreApplication::applicationDirPath() + "/Serial_Assistant_Cfg/";
// 串口读取
void SerialPort::read_Data()
{
    QByteArray data = serialPort->readAll(); // 读取串口数据
    if(!Read_ON) return;
    if (!data.isEmpty()) {
        // 将串口数据写入缓存文件
        writeDataToCache(data);
        // 发送数据准备完成信号
        emit dataReady();


        // 串口接收计数
        emit Serial_Read_Count(data.length()); // 接收计数显示
    }
}

/**
 * @brief 扫描可用的串口
 *
 * @return QList<QSerialPortInfo> 可用串口列表
 */
QList<QSerialPortInfo> SerialPort::Available_Ports()
{
    QList<QSerialPortInfo> ports;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        // 输出串口名和描述信息到控制台
        qDebug() << "Name:" << info.portName();
        qDebug() << "Description:" << info.description();

        // 判断串口是否可用
        if (info.isBusy())
            qDebug() << "Status: busy";
        else
            qDebug() << "Status: available";

        ports << info;
    }
    return ports;
}

/**
 * @brief 初始化串口
 *
 * @param portName      串口号
 * @param baudRate      波特率
 * @param dataBits      数据位
 * @param parity        校验位
 * @param stopBits      停止位
 * @param flowControl   流控制
 *
 * @return true         true:初始化成功 false:初始化失败
 */
bool SerialPort::initSerialPort(QString portName, int baudRate, int dataBits, int parity, int stopBits, int flowControl)
{
    serialPort->setPortName(portName);  // 串口号
    serialPort->setBaudRate(baudRate);  // 波特率
    serialPort->setDataBits((QSerialPort::DataBits)dataBits);  // 数据位
    serialPort->setParity((QSerialPort::Parity)parity);  // 校验位
    serialPort->setStopBits((QSerialPort::StopBits)stopBits);  // 停止位
    serialPort->setFlowControl((QSerialPort::FlowControl)flowControl);  // 流控制
    // 打开串口
    if (serialPort->open(QIODevice::ReadWrite)) {
        qDebug() << "Open serial port success!";
        return true;
    } else {
        qDebug() << "Open serial port failed!";
    }
    return false;
}

/**
 * @brief 关闭串口
 *
 */
void SerialPort::closeSerialPort()
{
    serialPort->close();    // 关闭串口
}

// 设置接收开关
void SerialPort::Set_Read_ON(bool ON)
{
    Read_ON = ON;
}

/**
 * @brief 返回串口状态
 *
 * @return true
 * @return false
 */
bool SerialPort::isSerialPortOpen()
{
    return serialPort->isOpen();
}

/**
 * @brief 以字符串返回当前连接的串口名及其描述信息
 *
 * @return QString
 */
QString SerialPort::getSerialPortName()
{
    QString description;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts()) {
        if (info.portName() == serialPort->portName()) {
            description = info.portName() + "(" + info.description() + ")";
            break;
        }
    }
    return description;
}


