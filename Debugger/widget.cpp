#include "widget.h"
#include "ui_widget.h"
#include "serial_port/serial_port_settings.h"
#include "ble_port/ble_port_settings.h"
#include "web/web_port_settings.h"
#include "Wave/wavepage.h"
#include "Buttons/buttons.h"

#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <QTimer>
#include <QStringList>
#include <QtCore/QDebug>
#include <QtCore/QByteArray>

/**
 * @brief Widget::Widget
 * @param parent
 * 构造函数，初始化窗口大小、标题、发送字节数、接收字节数、串口对象等
 */
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 设置窗口标题
    this->setWindowTitle(tr("Debugger助手"));
    // 隐藏Search_Display
    ui->Search_Display->hide();


    // 默认使能时间戳
    // Button_Switch(ui->Serial_Read_Time, true);
    // 默认使能HEX接收
    // Button_Switch(ui->Serial_Read_Text, true);
    // 默认使能HEX发送
    // Button_Switch(ui->Serial_Send_Text, true);

    // 最小宽度和最小高度
    this->setMinimumSize(700, 500);
    // // 默认宽度和默认高度
    // this->resize(800, 600);
    
    // 蓝牙
    // m_ble = new BLE(this);            // 创建蓝牙对象
    // 隐藏 ui->BleSettings
    ui->BleSettings->hide();
    // web
    // m_web_tcp = new web_tcp(this);    // 创建web对象
    // 隐藏 ui->WebSettings
    ui->WebSettings->hide();
    // 隐藏 ui->Search_Button_Refresh   // 功能有bug
    // ui->Search_Button_Refresh->hide();


    
    // 目录下查找配置文件，若不存在则创建
    QString path = QCoreApplication::applicationDirPath();  // 获取当前目录
    QDir dir(path); // 创建目录对象
    if (!dir.exists("Serial_Assistant_Cfg"))
    {
        if(!dir.mkdir("Serial_Assistant_Cfg"))
        {
            QMessageBox::warning(this, tr("警告"),
                        tr("配置文件夹创建失败,请手动在程序目录下创建Serial_Assistant_Cfg文件夹"));
        }
    }
    path = path + "/Serial_Assistant_Cfg";  // 获取配置文件夹路径
    // 创建QSettings对象
    settings = new QSettings(path + "/Serial_Assistant_Cfg.ini", QSettings::IniFormat);

    // 读取配置并设置按钮状态 启动时默认都是关闭状态
    if(settings->contains("Serial_Read_Text"))
        if(settings->value("Serial_Read_Text").toBool() == true) on_Serial_Read_Text_clicked();
    if(settings->contains("Serial_Read_Time"))
        if(settings->value("Serial_Read_Time").toBool() == true) on_Serial_Read_Time_clicked();
    if(settings->contains("Serial_Read_Line"))
        if(settings->value("Serial_Read_Line").toBool() == true) on_Serial_Read_Line_clicked();
    if(settings->contains("Serial_Send_Display"))
        if(settings->value("Serial_Send_Display").toBool() == true) on_Serial_Send_Display_clicked();
    if(settings->contains("Serial_Send_Text"))
        if(settings->value("Serial_Send_Text").toBool() == true) on_Serial_Send_Text_clicked();
    if(settings->contains("TX_textEdit"))
        if(settings->value("TX_textEdit").toString() != "") ui->TX_textEdit->setText(settings->value("TX_textEdit").toString());
    if(settings->contains("Search_Record"))
        if(settings->value("Search_Record").toString() != "") ui->textEdit_Search->setText(settings->value("Search_Record").toString());







    // 串口
    serialPort = new SerialPort;  // 串口对象
    // 绑定串口数据就绪信号到串口数据提取槽函数
    connect(serialPort, &SerialPort::dataReady, serialPort, &SerialPort::readDataFromCache);
    // 变量初始化
    SendByte_Display=0;
    ReceByte_Display=0;
    Send_Timer = new QTimer(this);  // 定时发送定时器
    // 绑定串口发送计数信号到串口发送计数显示函数
    connect(serialPort, &SerialPort::Serial_Send_Count, this, &Widget::SerialPort_Send_Count_Display);

    // 绑定串口接收计数信号到串口接收计数显示函数
    connect(serialPort, &SerialPort::Serial_Read_Count, this, &Widget::SerialPort_Rec_Count_Display);
    // 绑定蓝牙接收计数信号到串口接收计数显示函数
    // connect(m_ble, &BLE::signal_bleReadCount, this, &Widget::SerialPort_Rec_Count_Display);
    
    // 绑定串口发送信号到串口发送槽函数
    connect(this, &Widget::Send_Data, serialPort, &SerialPort::Serial_Send_Data);
    // 绑定输入框增加字符槽函数
    connect(ui->TX_textEdit, &QTextEdit::textChanged, this, &Widget::TX_textEdit_textChanged);
    
    // 绑定搜索框变化槽函数
    connect(ui->textEdit_Search, &QTextEdit::textChanged, this, &Widget::on_Search_Record_clicked);

    // 设置ui->Action_Widget标签可拖动
    // ui->Action_Widget->setMovable(true);

    // 将子页面wavepage.ui添加到tabWidget中
    WavePage = new wavepage(this, serialPort);
    WaveWindow = new NewWindow(this);
    WaveWindow->setWidget(WavePage);
    WaveWindow->setTabWidget(ui->Action_Widget, tr("波形显示"));
    // 设置WaveWindow的最小尺寸
    WaveWindow->setMinimumSize(QSize(650,400));

    // 将子页面buttons.ui添加到tabWidget中
    ButtonsUI = new Buttons(this, serialPort);
    ButtonsWindow = new NewWindow(this);
    ButtonsWindow->setWidget(ButtonsUI);
    ButtonsWindow->setTabWidget(ui->Action_Widget, tr("控件组"));
    // 设置ButtonsWindow的最小尺寸
    ButtonsWindow->setMinimumSize(QSize(300, 300));
    

    QTabBar *tabBar = ui->Action_Widget->tabBar(); // 获取tabBar

    lastProcessedLength = 0;    

    // 绑定tabBar的双击信号到槽函数
    connect(tabBar, &QTabBar::tabBarDoubleClicked, this, &Widget::TabBar_DoubleClicked);
}

/**
 * @brief Widget::~Widget
 * 析构函数
 */
Widget::~Widget()
{
    delete ui;
}

void Widget::TabBar_DoubleClicked(int index)
{
    // 获取tabBar
    QTabBar *tabBar = ui->Action_Widget->tabBar();
    // 获取tabBar的tabRect
    QRect rect = tabBar->tabRect(index);
  
    // 判断双击位置是否在tabRect内
    if (rect.contains(tabBar->mapFromGlobal(QCursor::pos())))
    {
        if(index<=0) return; 
        // 将对应的widget设置为独立窗口
        NewWindow *window = qobject_cast<NewWindow*>(ui->Action_Widget->widget(index));
        window->showWindow();
    }
}

/**
 * @brief 按钮开关
 * 
 * @param button 按钮对象
 * @param status 按钮状态 true开启 false关闭
 */
void Widget::Button_Switch(QPushButton *button, bool status)
{
    if(status)
    {
        button->setStyleSheet("color: darkCyan");
    }else{
        button->setStyleSheet("color: black");
    }
}

/**
 * @brief 判断按钮状态
 * 
 * @param button 按钮对象
 * @return true  按钮开启
 * @return false 按钮关闭
 */
bool Widget::Get_Button_Switch(QPushButton *button)
{
    if(button->styleSheet() == "color: darkCyan")
    {
        return true;
    }else{
        return false;
    }
}

void Widget::Delay_MS(int ms)
{
    QEventLoop eventloop;
    QTimer::singleShot(ms, &eventloop, SLOT(quit()));   // 延时10ms
    eventloop.exec();
}

// 保存发送框显示内容
void Widget::Save_Send_Display(bool autoSave)
{
    // 文件名为当前时间 年_月_日_时_分_秒
    QDateTime current_date_time = QDateTime::currentDateTime();
    QString current_date = current_date_time.toString("yyyy-MM-dd_hh-mm-ss");
    // 文件目录为当前目录下的Serial_Assistant_Cfg/user_Save/
    QString path = "/Serial_Assistant_Cfg/user_Save/";
    if(autoSave == true)    // 自动保存
    {
        // 文件目录为当前目录下的Serial_Assistant_Cfg/Auto_Save/
        path = "/Serial_Assistant_Cfg/Auto_Save/";
    }
    // 判断是否存在Serial_Assistant_Cfg/Auto_Save/文件夹
    QDir dir(QCoreApplication::applicationDirPath() + path); // 创建目录对象
    if(!dir.exists())
    {
        // 如果不存在,创建文件夹
        dir.mkpath(QCoreApplication::applicationDirPath() + path);
    }
    // 在文件夹里创建文件
    QFile file(QCoreApplication::applicationDirPath() + path + current_date + ".txt");  // 创建文件对象
    // 将ui->Read_Display_textEdit的内容保存到文件中
    if(file.open(QIODevice::WriteOnly | QIODevice::Text)) // 打开文件
    {
        QTextStream out(&file); // 创建文本流对象
        out << ui->Read_Display_textEdit->toPlainText(); // 将ui->Read_Display_textEdit的内容写入文件
        file.close();   // 关闭文件
    }
    if(autoSave == true)    // 自动保存
    {
        // 清空接收栏
        ui->Read_Display_textEdit->clear();
        // 自动保存提示
        // 显示保存成功 + 路径 + 文件名
        ui->Read_Display_textEdit->append(QStringLiteral("<font color = red>-----------------------------------</font>"));
        ui->Read_Display_textEdit->append(QStringLiteral("<font color = red>数据大于1M,已自动保存: %1%2.txt</font>").arg(path).arg(current_date));
        ui->Read_Display_textEdit->append(QStringLiteral("<font color = red>-----------------------------------</font>"));
    }else{
        // 手动保存提示
        // 显示保存成功 + 路径 + 文件名
        ui->Read_Display_textEdit->append(QStringLiteral("<font color = blue>-----------------------------------</font>"));
        ui->Read_Display_textEdit->append(QStringLiteral("<font color = blue>保存成功: %1%2.txt</font>").arg(path).arg(current_date));
        ui->Read_Display_textEdit->append(QStringLiteral("<font color = blue>-----------------------------------</font>"));
    }
}


void Widget::SerialPort_Data_Ready()
{
    // 触发SerialPort的槽函数readDataFromCache
    serialPort->readDataFromCache();
}

/**
 * @brief 数据打印槽函数
 * 
 * @param data 
 */
// 记录显示接收字节数
void Widget::SerialPort_Read_Display(QByteArray data)
{
    if(data.isEmpty()) return;
    QString Data_Str, Data_Show, time;
    QStringList strList;
    // Hex显示
    if(Get_Button_Switch(ui->Serial_Read_Text) == false)    // 文本接收状态
    {
        Data_Str = QString::fromLocal8Bit(data); // 转换为QString
    }else{
        Data_Str = data.toHex(' ').trimmed().toUpper();/*hex显示*/
    }    
    Data_Show = QStringLiteral("<font color = black>%1</font>").arg(Data_Str);
    // 如果触发信号是this的Send_Data则数据前加上">>"
    if(sender() == this) Data_Show = QStringLiteral("<font color = green>>>> </font>") + Data_Show;
    // 时间戳
    if(Get_Button_Switch(ui->Serial_Read_Time) == true)   // 时间戳显示
    {
        time = QStringLiteral("<font color = blue>[%1] </font>").arg(QTime::currentTime().toString("hh:mm:ss.zzz"));
        Data_Show = time + Data_Show;
    }
    // 显示到 Read_Display_textEdit
    ui->Read_Display_textEdit->append(Data_Show);
    // 若接收栏显示的字节数大于1m则自动保存并清空
    if(ui->Read_Display_textEdit->toPlainText().length() > 1024*1024)
    {
        qDebug() << "Save_Send_Display 1M";
        // 保存接收栏显示的内容
        this->Save_Send_Display(true);
    }

    // 自动滚屏到最后一行 有BUG 不可用光标点击文本框
    ui->Read_Display_textEdit->moveCursor(QTextCursor::End);
}

// 发送计数显示
void Widget::SerialPort_Send_Count_Display(int count)
{
    SendByte_Display += count;
    ui->label_9->setText(QString::number(SendByte_Display));
}

// 接收计数显示
void Widget::SerialPort_Rec_Count_Display(int count)
{
    ReceByte_Display += count;
    ui->label_10->setText(QString::number(ReceByte_Display));
}

// 设置接收按钮状态及接收状态
// 串口未连接则禁用接收按钮 并设置文字为“接收” 接收状态为false
// 串口已连接则启用接收按钮 则根据接收状态设置文字为“接收”或“停止”
void Widget::SetStartButtonStatus(bool status)
{
    // if (serialPort->isSerialPortOpen() || m_ble->getConnect())
    if (serialPort->isSerialPortOpen())
    {
        ui->Serial_Run->setEnabled(true);
        if (status)
        {
            ui->Serial_Run->setText(tr("暂停"));
        }
        else
        {
            ui->Serial_Run->setText(tr("接收"));
        }
    }
    else
    {
        ui->Serial_Run->setEnabled(false);
        ui->Serial_Run->setText(tr("接收"));
    }
}

/**
 * @brief 串口接收/暂停按钮槽函数
 * 
 */
void Widget::on_Serial_Run_clicked()
{
    if (ui->Serial_Run->text() == tr("接收"))
    {
        // 设置接收按钮状态
        SetStartButtonStatus(true);
        serialPort->Set_Read_ON(true);  // 接收串口接收
    }
    else
    {
        // 设置接收按钮状态
        SetStartButtonStatus(false);
        serialPort->Set_Read_ON(false); // 关闭串口接收
    }
}

/**
 * @brief 串口接收显示开关
 *
 */
void Widget::on_Serial_Read_ON_clicked()
{
    if(Get_Button_Switch(ui->Serial_Read_ON) == true)
    {
        Button_Switch(ui->Serial_Read_ON, false);       // 修改按钮状态

        if(nowPort == "Serial")
        {
            // 解绑槽SerialPort_Read_Display
            disconnect(serialPort, &SerialPort::dataRead, this, &Widget::SerialPort_Read_Display);
        }
        // 使能文本框
        ui->Read_Display_textEdit->setEnabled(true);
    }else
    {
        Button_Switch(ui->Serial_Read_ON, true);        // 修改按钮状态
        if(nowPort == "Serial")
        {
            // 将SerialPort的dataRead信号绑定到槽函数SerialPort_Read_Display
            connect(serialPort, &SerialPort::dataRead, this, &Widget::SerialPort_Read_Display);

        }
        // 禁用文本框
        ui->Read_Display_textEdit->setEnabled(false);
        ui->Search_Display->hide();
    }
}

/**
 * @brief 清除接收区按钮槽函数
 * 
 */
void Widget::on_Serial_Read_Clean_clicked()
{
    ui->Read_Display_textEdit->clear();
}

/**
 * @brief 添加时间戳按钮槽函数
 * 
 */
void Widget::on_Serial_Read_Time_clicked()
{
    if(Get_Button_Switch(ui->Serial_Read_Time) == true)
    {
        Button_Switch(ui->Serial_Read_Time, false);      // 修改按钮状态
        settings->setValue("Serial_Read_Time", false);   // 存储按键状态
    }else{
        Button_Switch(ui->Serial_Read_Time, true);      // 修改按钮状态
        settings->setValue("Serial_Read_Time", true);   // 存储按键状态
    }
}

/**
 * @brief 高速模式按钮槽函数
 * @note 高速模式下接收区自动保留最后100行数据
 * 
 */
void Widget::on_Serial_Read_Line_clicked()
{
    if(Get_Button_Switch(ui->Serial_Read_Line) == true)
    {
        Button_Switch(ui->Serial_Read_Line, false);      // 修改按钮状态
        settings->setValue("Serial_Read_Line", false);   // 存储按键状态
        // 取消限制
        ui->Read_Display_textEdit->document()->setMaximumBlockCount(0);
    }else{
        Button_Switch(ui->Serial_Read_Line, true);      // 修改按钮状态
        settings->setValue("Serial_Read_Line", true);   // 存储按键状态
        // 只保留最后1000行数据
        ui->Read_Display_textEdit->document()->setMaximumBlockCount(100);
    }
}

/**
 * @brief 文本接收/16进制接收
 * 
 */
void Widget::on_Serial_Read_Text_clicked()
{
    if(Get_Button_Switch(ui->Serial_Read_Text) == true)
    {
        Button_Switch(ui->Serial_Read_Text, false);     // 修改按钮状态
        settings->setValue("Serial_Read_Text", false);  // 存储按键状态
    }else{
        Button_Switch(ui->Serial_Read_Text, true);      // 修改按钮状态
        settings->setValue("Serial_Read_Text", true);   // 存储按键状态
    }
}

/**
 * @brief 保存文件
 * 
 */
void Widget::on_Serial_Read_Save_clicked()
{
    this->Save_Send_Display(false);
}

// 打开保存目录
void Widget::on_Open_Save_clicked()
{
    // 打开文件夹 /Serial_Assistant_Cfg/
    QString path = QCoreApplication::applicationDirPath() + "/Serial_Assistant_Cfg/";
    // 判断是否存在Serial_Assistant_Cfg/文件夹
    QDir dir(path); // 创建目录对象
    if(!dir.exists())
    {
        // 如果不存在,创建文件夹
        dir.mkpath(path);
    }
    // 打开文件夹
    QDesktopServices::openUrl(QUrl::fromLocalFile(path));
}

// 记录搜索框内容
void Widget::on_Search_Record_clicked()
{
    // 获取搜索框内容
    QString searchStr = ui->textEdit_Search->toPlainText();
    settings->setValue("Search_Record", searchStr);
}

// 在接收区搜索字符串
void Widget::on_Search_Button_clicked()
{
    // 0. 清空Search_Display
    ui->Search_Display->clear();
    // 1. 判断textEdit_Search是否为空
    if(ui->textEdit_Search->toPlainText().isEmpty())
    {
        // 隐藏Search_Display
        ui->Search_Display->hide();
        return;
    }
    // 2. 显示Search_Display
    ui->Search_Display->show();
    // 3. 获取textEdit_Search的内容
    QString searchStr = ui->textEdit_Search->toPlainText();
    // 4. 将光标移动到Read_Display_textEdit的开头
    QTextCursor cursor = ui->Read_Display_textEdit->textCursor();
    cursor.movePosition(QTextCursor::Start);
    // 逐行在Read_Display_textEdit中搜索字符串，若该行包含str则显示到Search_Display中
    // 遍历查找
    while (!cursor.isNull() && !cursor.atEnd())
    {
        cursor = ui->Read_Display_textEdit->document()->find(searchStr, cursor);
        if (!cursor.isNull())
        {
            // 将光标移动到行首
            cursor.movePosition(QTextCursor::StartOfLine);
            // 获取该行的内容
            QString str = cursor.block().text();
            // 将该行中的searchStr高亮显示
            str.replace(searchStr, QStringLiteral("<font color = red>%1</font>").arg(searchStr));
            // 显示到Search_Display中
            ui->Search_Display->append(str);
            
            // 将光标移动到行尾
            cursor.movePosition(QTextCursor::EndOfLine);
            // 判断是否为最后一行
            if(cursor.atEnd()) return;

            // 将光标移动到下一行
            cursor.movePosition(QTextCursor::NextBlock);
            // 跳过空行
            while(cursor.block().text().isEmpty())
            {
                cursor.movePosition(QTextCursor::NextBlock);
            }
        }else return;
    }
}

// 清空搜索显示区
void Widget::on_Search_Button_Clean_clicked()
{
    ui->Search_Display->clear();
    ui->Search_Display->hide();
}

// 搜索实时刷新开关
void Widget::on_Search_Button_Refresh_clicked()
{
    if(Get_Button_Switch(ui->Search_Button_Refresh) == true)
    {
        Button_Switch(ui->Search_Button_Refresh, false);
        // 解绑
        disconnect(ui->Read_Display_textEdit, &QTextEdit::textChanged, this, &Widget::Search_Refresh);
        // 使能文本框
        ui->Search_Display->setEnabled(true);
        // 使能输入框
        ui->textEdit_Search->setEnabled(true);
    }else{
        Button_Switch(ui->Search_Button_Refresh, true);
        // 绑定 Read_Display_textEdit的textChanged信号到槽函数on_Search_Button_clicked
        connect(ui->Read_Display_textEdit, &QTextEdit::textChanged, this, &Widget::Search_Refresh);
        // 禁用文本框
        ui->Search_Display->setEnabled(false);
        // 禁用输入框
        ui->textEdit_Search->setEnabled(false);
    }
}

// 搜索实时刷新槽函数
void Widget::Search_Refresh()
{
    // 1. 判断textEdit_Search是否为空
    if (ui->textEdit_Search->toPlainText().isEmpty())
    {
        // 隐藏Search_Display
        ui->Search_Display->hide();
        return;
    }
    // 2. 显示Search_Display
    ui->Search_Display->show();
    // 3. 获取textEdit_Search的内容
    QString searchStr = ui->textEdit_Search->toPlainText();
    // 4. 获取Read_Display_textEdit的全文本
    QString fullText = ui->Read_Display_textEdit->toPlainText();
    // 5. 获取上一次处理到的文本长度
    int currentLength = fullText.length();
    // 6. 获取新增的文本
    QString newContent = fullText.mid(lastProcessedLength);
    // 7. 更新上一次处理到的文本长度
    lastProcessedLength = currentLength;
    // 8. 在新增的文本中搜索searchStr
    QTextDocument *document = new QTextDocument(newContent);
    QTextCursor cursor(document);

    while (!cursor.isNull() && !cursor.atEnd())
    {
        cursor = document->find(searchStr, cursor);
        if (!cursor.isNull())
        {
            // 获取该行的内容
            QString str = cursor.block().text();
            // 将该行中的searchStr高亮显示
            str.replace(searchStr, QStringLiteral("<font color='red'>%1</font>").arg(searchStr));
            // 显示到Search_Display中
            ui->Search_Display->append(str);
        }
    }
}


/**
 * @brief Widget::on_Serial_Write_Clear_clicked
 * 清除发送区
 */
void Widget::on_Serial_Send_Clean_clicked()
{
    ui->TX_textEdit->clear();
}

// 发送区文本/16进制发送 切换
void Widget::on_Serial_Send_Text_clicked()
{
    // 获取输入框中的数据
    QByteArray data = ui->TX_textEdit->toPlainText().toUtf8();

    // 字符串发送状态
    if(Get_Button_Switch(ui->Serial_Send_Text) == true)
    {
        Button_Switch(ui->Serial_Send_Text, false);     //修改按钮状态
        settings->setValue("Serial_Send_Text", false);  //存储按键状态   
        // 将数据解析出16进制字符串并转化为Ascii码
        QString textData;
        // 舍弃所有空格
        data = data.replace(" ", "");
        // 两两分割并转换为Ascii码
        for(int i=0; i<data.length(); i+=2)
        {
            QString str = data.mid(i, 2);   // 截取两个字符
            // 判断是否为有效Ascii码 0～127
            if(str.toInt(NULL, 16) > 127) textData += "?";
            else textData += QChar(str.toInt(NULL, 16));
        }
        // 将转换后的数据显示到输入框中
        ui->TX_textEdit->setText(textData);
    }
    else    //16进制发送状态
    {
        Button_Switch(ui->Serial_Send_Text, true);      //修改按钮状态
        settings->setValue("Serial_Send_Text", true);   //存储按键状态
        // 将数据转化为16进制形式
        QString hexData = data.toHex(' ').toUpper();
        // 判断第一个字符是否为空格，若是则删除
        if(hexData.startsWith(' ')) hexData.remove(0, 1);
        // 将转换后的数据显示到输入框中
        ui->TX_textEdit->setText(hexData);
    }
}

// 显示发送
void Widget::on_Serial_Send_Display_clicked()
{
    if(Get_Button_Switch(ui->Serial_Send_Display) == true)
    {
        Button_Switch(ui->Serial_Send_Display, false);      // 修改按钮状态
        settings->setValue("Serial_Send_Display", false);   // 存储按键状态
        // 解绑发送按钮和SerialPort_Read_Display
        disconnect(this, &Widget::Send_Data, this, &Widget::SerialPort_Read_Display);
    }else{
        Button_Switch(ui->Serial_Send_Display, true);       // 修改按钮状态
        settings->setValue("Serial_Send_Display", true);    // 存储按键状态
        // 绑定发送按钮和SerialPort_Read_Display
        connect(this, &Widget::Send_Data, this, &Widget::SerialPort_Read_Display);
    }
}



/**
 * @brief 发送输入框槽函数
 * 
 */
void Widget::TX_textEdit_textChanged()
{
    static QString Data_Last; // 保存上一次的内容
    QTextCursor cursor = ui->TX_textEdit->textCursor(); // 获取光标位置

    if(ui->TX_textEdit->toPlainText().isEmpty())
        ui->Send_Button->setEnabled(false); // 若输入框为空则禁用发送按钮
    else ui->Send_Button->setEnabled(true);

    if(Get_Button_Switch(ui->Serial_Send_Text) == true)     // 若为Hex发送状态
    {
        // 判断是输入还是删除
        if(ui->TX_textEdit->toPlainText().length() >= Data_Last.length())
        {
            QString hexData = ui->TX_textEdit->toPlainText().right(1); // 提取光标前一个字符
            if(hexData.contains(QRegExp("[^0-9a-fA-F]"))) // 包含非数字和字母
            {
                cursor.deletePreviousChar(); // 删除光标前一个字符
            }
            // 判断光标位置为3或者4的倍数时，在光标前插入空格
            if(cursor.position() == 3 || (cursor.position()-3)%3 == 0)
            {
                // 判断光标位置是否为最前面
                if(cursor.position() != 0)
                {
                    QSignalBlocker blocker(ui->TX_textEdit);    // 阻塞信号
                    //调整光标位置
                    cursor.setPosition(cursor.position() - 1);
                    // 插入空格
                    cursor.insertText(" ");
                    // 调整光标位置
                    cursor.setPosition(cursor.position() + 1);
                }
            }
        }
        // 判断当前有效字符长度是否为偶数
        QString str = ui->TX_textEdit->toPlainText().replace(QRegExp("\\s+"), ""); // 去除空格
        if(str.length() % 2 != 0) ui->Send_Button->setEnabled(false); // 若为奇数则禁用发送按钮
        // 保存当前内容
        Data_Last = ui->TX_textEdit->toPlainText();
    }
    // 配置文件记录发送框内容
    settings->setValue("TX_textEdit", ui->TX_textEdit->toPlainText());
}

/**
 * @brief 发送按钮槽函数
 * 
 */
void Widget::on_Send_Button_clicked()
{
    QByteArray data;
    QString str = ui->TX_textEdit->toPlainText();
    // // 若串口未连接则弹出警告框
    // if(!serialPort->isSerialPortOpen())
    // {
    //     QMessageBox::warning(this, tr("警告"),
    //                 tr("串口未连接"));
    //     return;
    // }

    if(Get_Button_Switch(ui->Serial_Send_Text) == false)    // 文本发送状态
    {
        data = str.toLocal8Bit(); // 转换为QByteArray
    }else{
        data = QByteArray::fromHex(str.toLatin1().data()); // 转换为16进制
    }
    // 发送数据
    emit Send_Data(data);
}

// 发送槽函数 外部调用
void Widget::Send_Data_Slot(QByteArray data)
{
    emit Send_Data(data);
}


/**
 * @brief 定时发送按钮槽函数
 * 
 */
void Widget::on_Send_Timed_clicked()
{
    // 获取Send_Timed_Edit的值
    quint16 time = ui->Send_Timed_Edit->text().toInt();
    // 若为空或小于10则弹出警告框
    if(time < 10)
    {
        QMessageBox::warning(this, tr("警告"),
                    tr("定时时间为空或小于10Ms"));
        return;
    }

    if(Get_Button_Switch(ui->Send_Timed) == true)
    {
        Button_Switch(ui->Send_Timed, false);   // 修改按钮状态
        // 恢复Send_Timed_Edit、Serial_Send_Clean、Serial_Send_Text、TX_textEdit
        ui->Send_Timed_Edit->setEnabled(true);
        ui->Serial_Send_Clean->setEnabled(true);
        ui->Serial_Send_Text->setEnabled(true);
        ui->TX_textEdit->setEnabled(true);
        // 若定时器已start则stop
        if(Send_Timer->isActive()) Send_Timer->stop();
        disconnect(Send_Timer, &QTimer::timeout, this, &Widget::on_Send_Button_clicked);
    }else{
        // 串口已连接 且Send_Button使能
        if(serialPort->isSerialPortOpen() && ui->Send_Button->isEnabled())
        {
            Button_Switch(ui->Send_Timed, true);    // 修改按钮状态
            // 禁用Send_Timed_Edit、Serial_Send_Clean、Serial_Send_Text、TX_textEdit
            ui->Send_Timed_Edit->setEnabled(false);
            ui->Serial_Send_Clean->setEnabled(false);
            ui->Serial_Send_Text->setEnabled(false);
            ui->TX_textEdit->setEnabled(false);
            
            // 启动定时器
            Send_Timer->start(time);
            // 绑定定时器槽函数
            connect(Send_Timer, &QTimer::timeout, this, &Widget::on_Send_Button_clicked);
        }else{
            QMessageBox::warning(this, tr("警告"),
                    tr("串口未连接或发送内容不合法"));
            ui->Send_Timed_Edit->setEnabled(true);
        
        }
    }
}


/**
 * @brief Widget::on_Reset_Count_Button_clicked
 * 清除计数按钮槽函数
 */
void Widget::on_Reset_Count_Button_clicked()
{
    SendByte_Display=0;
    ReceByte_Display=0;
    ui->label_9->setText(QString::number(SendByte_Display));
    ui->label_10->setText(QString::number(ReceByte_Display));
}



/**
 * @brief 串口设置按钮 - 槽函数
 *
 */
void Widget::on_SerialSettings_clicked()
{
    // 弹出串口设置对话框 serial_port_settings.ui
    Serial_Port_Settings Serial_Setting_ui(this, serialPort);   // 创建一个对话框对象
    Serial_Setting_ui.show();   // 显示对话框
    Serial_Setting_ui.exec();   // 阻塞等待对话框关闭
}

/**
 * @brief 蓝牙设置按钮 - 槽函数
 *
 */
void Widget::on_BleSettings_clicked()
{
    // 弹出蓝牙设置对话框 ble_port_settings.ui
    // Ble_Port_Settings Ble_Setting_ui(this, m_ble);   // 创建一个对话框对象
    // Ble_Setting_ui.show();   // 显示对话框
    // Ble_Setting_ui.exec();   // 阻塞等待对话框关闭
}

/**
 * @brief web 设置按钮 - 槽函数
 * 
 */
void Widget::on_WebSettings_clicked()
{
    // // 弹出web设置对话框 web_port_settings.ui
    // Web_Port_Settings Web_Setting_ui(this, m_web_tcp);   // 创建一个对话框对象
    // Web_Setting_ui.show();   // 显示对话框
    // Web_Setting_ui.exec();   // 阻塞等待对话框关闭
}


/**
 * @brief 接口状态变更
 * 
 * @param status 
 */
void Widget::SerialPort_Status(QString status,const QString portName)
{
    // 修改状态显示
    ui->Serial_State->setText(status);
    nowPort = portName;
    if(portName == "Serial")
    {
        // 根据串口状态设置文字颜色
        if (serialPort->isSerialPortOpen()) // 串口已连接
        {
            ui->Serial_State->setStyleSheet("color: darkCyan");
            SetStartButtonStatus(true); // 收发总开关
            // 断开蓝牙连接
            // if(m_ble->getConnect()) m_ble->disconnectDevice();
            Button_Switch(ui->SerialSettings, true);
            // Button_Switch(ui->BleSettings, false);
            // Button_Switch(ui->WebSettings, false);
        }else{
            ui->Serial_State->setStyleSheet("color: black");
            SetStartButtonStatus(false); // 收发总开关
        }
    }
    // else if(portName == "BLE")
    // {
    //     // 根据\蓝牙状态设置文字颜色
    //     if (m_ble->getConnect()) // 蓝牙已正确连接
    //     {
    //         ui->Serial_State->setStyleSheet("color: darkCyan");
    //         SetStartButtonStatus(true); // 收发总开关
    //         // 断开串口连接
    //         if(serialPort->isSerialPortOpen()) serialPort->closeSerialPort();
    //         Button_Switch(ui->SerialSettings, false);
    //         Button_Switch(ui->BleSettings, true);
    //         Button_Switch(ui->WebSettings, false);
    //     }else{
    //         ui->Serial_State->setStyleSheet("color: black");
    //         SetStartButtonStatus(false); // 收发总开关
    //     }
    // }
    
}


// 重载键盘按下事件 并触发信号
void Widget::keyPressEvent(QKeyEvent *event)
{
    emit myKeyPressSignal(event);
}

// 重载键盘释放事件
void Widget::keyReleaseEvent(QKeyEvent *event)
{
    emit myKeyReleaseSignal(event);
}

