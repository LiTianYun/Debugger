#ifndef SERIAL_PORT_SETTINGS_H
#define SERIAL_PORT_SETTINGS_H

#include <QDialog>
#include "serialport.h"
#include "widget.h"

namespace Ui {
class Serial_Port_Settings;
}

class Serial_Port_Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Serial_Port_Settings(Widget *parent = nullptr, SerialPort *serialPort = nullptr);
    ~Serial_Port_Settings();

private slots:
    void on_Port_Scan_Button_clicked();

    void on_Port_Open_Button_clicked();

private:
    Ui::Serial_Port_Settings *ui;
    Widget *parentWidget;                        //父窗口
    // 串口
    SerialPort *serialPort;                 //串口端口
    QSettings  *settings;                   // 保存配置文件

    enum UI_Parity {
        None = 0,
        Even = 2,
        Odd = 3,
        Space = 4,
        Mark = 5,
        Unknown = -1
    };

    enum UI_StopBits {
        OneStop = 1,
        OneAndHalfStop = 3,
        TwoStop = 2,
        UnknownStopBits = -1
    };

    enum UI_FlowControl {
        NoFlowControl,
        HardwareControl,
        SoftwareControl,
        UnknownFlowControl = -1
    };


};

#endif // SERIAL_PORT_SETTINGS_H
