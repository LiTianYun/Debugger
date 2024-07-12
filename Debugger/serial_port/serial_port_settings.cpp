#include "serial_port_settings.h"
#include "ui_serial_port_settings.h"

#include <QAbstractItemView>
#include <QMessageBox>

/**
 * @brief 构造函数
 *
 * @param parent
 */
Serial_Port_Settings::Serial_Port_Settings(Widget *parent, SerialPort *serialPort) :
    QDialog(parent),
    ui(new Ui::Serial_Port_Settings)
{
    ui->setupUi(this);
    parentWidget = parent;  // 父窗口
    settings = parentWidget->settings;  // 设置类
    // 串口类
    this->serialPort = serialPort;
    // 禁止拖动窗口大小
    // this->setFixedSize(this->width(), this->height());
    // 设置窗口标题
    this->setWindowTitle("串口设置");
    // 设置该窗口置顶
    // this->setWindowFlags(Qt::WindowStaysOnTopHint);
    // 设置该窗口为模态窗口 该窗口关闭后才能操作父窗口
    this->setWindowModality(Qt::ApplicationModal);

    // 扫描一次可用串口
    on_Port_Scan_Button_clicked();

    // 读取配置文件中的串口设置
    settings->beginGroup("SerialPort");
    if(settings->contains("PortName"))
        ui->Serial_Port_Num->setCurrentIndex(settings->value("PortName").toInt());
    else
        ui->Serial_Port_Num->setCurrentIndex(0);

    if(settings->contains("BaudRate"))
        ui->baudRate->setCurrentIndex(settings->value("BaudRate").toInt());
    else
        ui->baudRate->setCurrentIndex(11);  // 115200

    if(settings->contains("DataBits"))
        ui->dataBits->setCurrentIndex(settings->value("DataBits").toInt());
    else
        ui->dataBits->setCurrentIndex(3);   // 8

    if(settings->contains("Parity"))
        ui->parityBit->setCurrentIndex(settings->value("Parity").toInt());
    else
        ui->parityBit->setCurrentIndex(0);  // 无校验

    if(settings->contains("StopBits"))
        ui->stopBit->setCurrentIndex(settings->value("StopBits").toInt());
    else
        ui->stopBit->setCurrentIndex(0);    // 1
    settings->endGroup();


    // 根据串口状态设置按钮文字
    if (serialPort->isSerialPortOpen())
        ui->Port_Open_Button->setText("关闭串口");
    else
        ui->Port_Open_Button->setText("打开串口");


    // 判断当前串口是否已连接
    if(serialPort->isSerialPortOpen() == false)
    {
        // 未连接
        ui->Port_Open_Button->setText("打开串口");
        parentWidget->SerialPort_Status("未连接", "Serial");  // 主界面串口状态显示
    }
}

/**
 * @brief 析构函数
 *
 */
Serial_Port_Settings::~Serial_Port_Settings()
{
    delete ui;
    // 清除绑定到当前对象的所有信号槽
    disconnect();
}

/**
 * @brief com口扫描按钮槽函数
 *
 */
void Serial_Port_Settings::on_Port_Scan_Button_clicked()
{
    QList<QSerialPortInfo> ports = serialPort->Available_Ports();    // 获取可用串口列表
    ui->Serial_Port_Num->clear();       // 清空串口号下拉框
    // 显示可用串口及其描述信息 并按照状态设置文字颜色
    foreach (const QSerialPortInfo &info, ports) {
        // 显示串口号及其描述信息 例如：COM1(USB-SERIAL CH340)
        ui->Serial_Port_Num->addItem(info.portName() + "(" + info.description() + ")");
        // 根据串口状态设置文字颜色
        if (info.isBusy())
            ui->Serial_Port_Num->setItemData(ui->Serial_Port_Num->count() - 1, QBrush(Qt::magenta), Qt::TextColorRole);
        else
            ui->Serial_Port_Num->setItemData(ui->Serial_Port_Num->count() - 1, QBrush(Qt::darkCyan), Qt::TextColorRole);
    }
    // 根据文字长度动态调整下拉框宽度
    ui->Serial_Port_Num->view()->setMinimumWidth(ui->Serial_Port_Num->minimumSizeHint().width());
}

/**
 * @brief com口打开按钮槽函数
 *
 */
void Serial_Port_Settings::on_Port_Open_Button_clicked()
{
    QString status;
    // 获取串口号
    QString portName = ui->Serial_Port_Num->currentText().split("(").at(0);
    // 获取波特率
    int baudRate = ui->baudRate->currentText().toInt();
    // 获取数据位
    int dataBits = ui->dataBits->currentText().toInt();

    // 获取校验位 text转换为enum
    QString parityText = ui->parityBit->currentText();
    UI_Parity parity = None;
    if(parityText == "None")
        parity = None;
    else if(parityText == "Even")
        parity = Even;
    else if(parityText == "Odd")
        parity = Odd;
    else if(parityText == "Space")
        parity = Space;
    else if(parityText == "Mark")
        parity = Mark;

    QString stopBitText = ui->stopBit->currentText();
    UI_StopBits stopBits = OneStop;
    if(stopBitText == "OneStop")
        stopBits = OneStop;
    else if(stopBitText == "OneAndHalfStop")
        stopBits = OneAndHalfStop;
    else if(stopBitText == "TwoStop")
        stopBits = TwoStop;

    int flowControl = NoFlowControl;    // 默认无流控制
    if(ui->Port_Open_Button->text() == "关闭串口")
    {
        // 关闭串口
        serialPort->closeSerialPort();
        // 按钮设置为打开串口
        ui->Port_Open_Button->setText("打开串口");
        status = "未连接";
    }else{
        // 记录串口设置 记录下拉框索引
        settings->beginGroup("SerialPort");
        settings->setValue("PortName", ui->Serial_Port_Num->currentIndex());
        settings->setValue("BaudRate", ui->baudRate->currentIndex());
        settings->setValue("DataBits", ui->dataBits->currentIndex());
        settings->setValue("Parity", ui->parityBit->currentIndex());
        settings->setValue("StopBits", ui->stopBit->currentIndex());
        settings->endGroup();
        

        // 初始化并打开串口
        if(serialPort->initSerialPort(portName, baudRate, dataBits, (int)parity, (int)stopBits, flowControl) == true)
        {
            // 按钮设置为关闭串口
            ui->Port_Open_Button->setText("关闭串口");
            // 组合状态信息 已连接/未连接 + 串口信息
            status = serialPort->isSerialPortOpen()? "已连接" : "未连接";
            status += " " + serialPort->getSerialPortName();
        }else{
            // 警告对话框
            QMessageBox::warning(NULL, "警告", "串口打开失败！", QMessageBox::Yes);
            status = "未连接";
        }
    }
    parentWidget->SerialPort_Status(status,"Serial");  // 主界面串口状态显示
    if(serialPort->isSerialPortOpen())
        this->close();  // 关闭串口设置对话框
}

