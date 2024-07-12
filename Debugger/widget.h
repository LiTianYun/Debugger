#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QThread>
#include <QtWidgets>
#include <string>
#include <QDebug>
#include <QSettings>
#include "serial_port/serialport.h"
#include "ble_port/ble.h"
#include "web/web_tcp.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class NewWindow;

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QSettings  *settings;                    // 保存配置文件
    
    QWidget    *WavePage;                   // 波形页面
    QWidget    *ButtonsUI;                  // 自定义按钮页面

    SerialPort *serialPort;                 // 串口类
    BLE * m_ble;                            // 蓝牙类
    web_tcp *m_web_tcp;                       // web端口类

    QString nowPort;                        // 当前接口类型 BLE/Serial
    
    void SerialPort_Status(QString status,const QString portName);         //  串口状态显示
    void SetStartButtonStatus(bool status);         //  设置启动按钮状态及启动状态

    void Delay_MS(int ms);                          //  延时函数

    void Button_Switch(QPushButton *button, bool status);   //  按钮开关
    bool Get_Button_Switch(QPushButton *button);    //  判断按钮状态
protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
private:
    Ui::Widget *ui;                         // UI界面
    
    NewWindow  *WaveWindow;                 // 波形窗口
    NewWindow  *ButtonsWindow;                 // 自定义按钮窗口

    int lastProcessedLength;                // 用于计算接受框中的数据长度
    quint64 SendByte_Display, ReceByte_Display;

    QTimer *Send_Timer;                     // 发送定时器
    

    void Save_Send_Display(bool autoSave);  // 保存发送区显示
signals:
    void Send_Data(QByteArray data);        // 发送数据信号
    void myKeyPressSignal(QKeyEvent *event);// 键盘按下信号
    void myKeyReleaseSignal(QKeyEvent *event);// 键盘释放信号
private slots:
    // My槽函数
    void TabBar_DoubleClicked(int index); // 双击tabBar
    void TX_textEdit_textChanged();             // 发送文本框改变
    void Search_Refresh();                      // 搜索刷新  
    void SerialPort_Send_Count_Display(int count);// 串口发送计数显示
    void SerialPort_Rec_Count_Display(int count);// 串口接收计数显示
    // 控件槽函数
    void on_Serial_Read_ON_clicked();           // 串口接收开关
    void on_Reset_Count_Button_clicked();       // 清除计数
    void on_Serial_Read_Save_clicked();         // 保存文件
    void on_Search_Record_clicked();            // 配置文件记录搜索框内容
    void on_Search_Button_clicked();            // 搜索接收区

    void on_SerialSettings_clicked();           // 串口设置按钮
    void on_Serial_Run_clicked();               // 串口运行按钮
    void on_Serial_Read_Clean_clicked();        // 串口接收清除
    void on_Serial_Read_Line_clicked();         // 串口接收换行
    void on_Serial_Read_Time_clicked();         // 串口接收时间戳
    void on_Serial_Read_Text_clicked();         // 串口接收文本/HEX
    void on_Serial_Send_Clean_clicked();        // 串口发送清除
    void on_Serial_Send_Text_clicked();         // 串口发送文本/HEX
    void on_Send_Button_clicked();              // 串口发送按钮
    void on_Send_Timed_clicked();               // 串口定时发送
    void on_Search_Button_Refresh_clicked();
    void on_Search_Button_Clean_clicked();
    void on_BleSettings_clicked();
    void on_Open_Save_clicked();
    void on_Serial_Send_Display_clicked();
    void on_WebSettings_clicked();
public slots:
    void SerialPort_Data_Ready();               // 串口数据准备
    void SerialPort_Read_Display(QByteArray data);   // 显示区显示数据
    void Send_Data_Slot(QByteArray data);            // 发送数据槽函数
};


//  新建独立窗口类
class NewWindow : public QWidget
{
    Q_OBJECT
public:
    NewWindow(QWidget *parent = nullptr) : QWidget(parent){};

    //  设置窗口内容
    void setWidget(QWidget *widget){
        this->widget = widget;
        //  新建布局并将widget添加到布局中
        QVBoxLayout *layout = new QVBoxLayout();
        layout->addWidget(widget);
        //  设置窗口布局
        this->setLayout(layout);
    };

    //  设置父标签
    void setTabWidget(QTabWidget *tabWidget, QString title){
        //  将该界面插入到tabWidget中
        tabWidget->addTab(this, title);
        this->tabWidget = tabWidget;
        this->index = tabWidget->indexOf(this);    //  获取tab索引
        this->title = title;
    };

    //  将窗口作为独立窗口显示
    void showWindow(){
        //  将该界面从tabWidget中移除
        tabWidget->removeTab(tabWidget->indexOf(this));
        //  设置窗口标题
        setWindowTitle(title);
        //  设置窗口最小大小为tab最小大小
        // setMinimumSize(tabWidget->size());
        //  设置窗口默认大小为tab默认大小
        // resize(tabWidget->size());
        //  设置窗口为独立窗口
        setWindowFlags(Qt::Window);
        //  显示窗口
        show();
    };

    //  析构函数 
    ~NewWindow(){}; // 析构函数
private:
    QWidget *widget;
    QTabWidget *tabWidget;
    QString title;
    int index;
    //  重写关闭事件
    void closeEvent(QCloseEvent *event){
        //  重新设置窗口为子窗口
        setWindowFlags(Qt::Widget); 
        //  重新将该界面插入到tabWidget中
        tabWidget->insertTab(index, this, title);
        //  调用父类关闭事件
        QWidget::closeEvent(event);
    };
};

//  重写QTabWidget类 
class MyTabWidget : public QTabWidget
{
    Q_OBJECT
public:
    MyTabWidget(QWidget *parent = nullptr) : QTabWidget(parent){};
    ~MyTabWidget(){};
protected:
    
};




#endif //  WIDGET_H
