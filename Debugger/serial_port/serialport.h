#ifndef SERIALPORT_H
#define SERIALPORT_H

#include <QtSerialPort>
#include <QSerialPortInfo>
#include <QThread>

class SerialPort : public QObject
{
    Q_OBJECT
    public:         //公有函数
        SerialPort(QObject *parent = nullptr);
        ~SerialPort(); // 析构函数，用于清理资源
        // 串口扫描
        QList<QSerialPortInfo> Available_Ports();
        // 初始化串口参数
        bool initSerialPort(QString portName, int baudRate, int dataBits, int parity, int stopBits, int flowControl);
        // 关闭串口
        void closeSerialPort();
        // 串口接收开关
        void Set_Read_ON(bool ON);
        // 返回串口状态
        bool isSerialPortOpen();
        // 以字符串返回当前连接的串口名及其描述信息
        QString getSerialPortName();
    private:        // 私有函数
        bool Read_ON = true;            //串口接收开关
        QSerialPort *serialPort;        //串口端口
        QThread *Serial_Thread;         //串口收发线程
        
        uchar* mappedData = nullptr;    // 映射数据
        QFile* file = nullptr;          // 缓存文件
        qint64 fileSize = 0;            // 文件大小
        qint64 mappedSize = 0;          // 映射大小

        void Clear_MappedData();        // 清理映射数据
        void Cache_File_Create();                           // 创建缓存文件
        bool writeDataToCache(const QByteArray& data);      // 写入缓存文件

    signals:        //信号
        // void Serial_Read_Data(QByteArray data);
        void dataReady(); // 有数据可读
        // 发送计数信号 参数为新增的字节数
        void Serial_Send_Count(int count);
        // 接收计数信号 参数为新增的字节数
        void Serial_Read_Count(int count);
        void dataRead(QByteArray data); // 返回读取的数据

    public slots:   //槽函数
        void New_SerialPort();
        void Serial_Send_Data(QByteArray data);
        void readDataFromCache();   // 读取缓存文件
    private slots:
        void read_Data();
};

#endif // SERIALPORT_H
