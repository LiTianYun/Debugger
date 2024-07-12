#include "buttons.h"
#include "ui_buttons.h"
#include "widget.h"

Buttons::Buttons(Widget *parent, SerialPort *Port) :
    QWidget(parent),
    ui(new Ui::Buttons)
{
    ui->setupUi(this);
    parentWidget = parent;  // 父窗口指针
    serialPort = Port;    // 串口指针
    settings = parentWidget->settings;  // 配置文件指针
    NowPath = "";

    // 若配置文件中存在Buttons/LastFilePath则加载该文件
    if(settings->contains("Buttons/LastFilePath"))
    {
        QString fileName = settings->value("Buttons/LastFilePath").toString();
        // 若文件名不为空且文件存在则加载文件
        if(!fileName.isEmpty() && QFile::exists(fileName))
        {
            this->Load_clicked(fileName);
        }
    }

    // 将on_Button_save_clicked绑定到ctrl+s
    QShortcut *shortcut = new QShortcut(QKeySequence("Ctrl+S"), this);
    connect(shortcut, &QShortcut::activated, this, &Buttons::on_Button_save_clicked);
    // 将on_Button_Load_clicked绑定到ctrl+o
    shortcut = new QShortcut(QKeySequence("Ctrl+O"), this);
    connect(shortcut, &QShortcut::activated, this, &Buttons::on_Button_Load_clicked);
    // 将on_Button_save_as_clicked绑定到ctrl+shift+s
    shortcut = new QShortcut(QKeySequence("Ctrl+Shift+S"), this);
    connect(shortcut, &QShortcut::activated, this, &Buttons::on_Button_save_as_clicked);
}


Buttons::~Buttons()
{
    delete ui;
}

// 鼠标坐标改变槽函数
void Buttons::mousePosChanged(QPoint pos)
{
    // 若MouseFollowButton不为空则使其跟随鼠标移动
    if(MouseFollowButton != nullptr)
    {
        MouseFollowButton->move(pos.x(), pos.y());
    }
}


// 按钮长按信号 槽函数
// 使按钮跟随鼠标移动
void Buttons::rightLongClicked(MyPushButton *button)
{
    MouseFollowButton = button;
    // 绑定MyFrame鼠标坐标改变信号到槽
    connect(ui->myFrame, &MyFrame::mousePosChanged, this, &Buttons::mousePosChanged);
}
// 按钮长按释放信号 槽函数
// 使按钮停止跟随鼠标移动
void Buttons::rightLongClickedRelease(MyPushButton *button)
{
    MouseFollowButton = nullptr;
    // 解绑MyFrame鼠标坐标改变信号
    disconnect(ui->myFrame, &MyFrame::mousePosChanged, this, &Buttons::mousePosChanged);
    // 保存当前坐标
    button->SaveButtonPos(button->pos().x(), button->pos().y());
}

// 新建按钮并绑定信号
MyPushButton *Buttons::CreateButton()
{
    MyPushButton *button = new MyPushButton(ui->myFrame, this, serialPort);
    // 设置按钮id为当前时间戳 毫秒级取后5位
    button->SetButtonID(QDateTime::currentDateTime().toString("mmsszzz").toInt());
    // 按钮的位置
    ui->myFrame->AddWidget(button);
    // 保存按钮坐标
    button->SaveButtonPos(button->pos().x(), button->pos().y());
    // 绑定按钮长按信号到槽
    connect(button, &MyPushButton::rightLongClicked, this, &Buttons::rightLongClicked);
    connect(button, &MyPushButton::rightLongClickedRelease, this, &Buttons::rightLongClickedRelease);
    return button;
}


// 在frame中添加按钮
void Buttons::on_Button_add_clicked()
{
    CreateButton();
}

// 自动排列frame中的按钮
void Buttons::on_Button_auto_clicked()
{
    ui->myFrame->AutoArrangeWidgets();
    // 遍历frame中所有控件 若为MyPushButton则保存坐标
    // 获取所有子控件
    QList<QWidget *> widgets = ui->myFrame->findChildren<QWidget *>();
    for(auto widget : widgets)
    {
        MyPushButton *button = qobject_cast<MyPushButton *>(widget);
        if(button != nullptr)
        {
            button->SaveButtonPos(button->pos().x(), button->pos().y());
        }
    }
}

// 加载按钮组文件
void Buttons::Load_clicked(QString fileName)
{
    // 判断文件名是否为空
    if(fileName.isEmpty())
    {
        return;
    }
    // 打开文件
    QFile file(fileName);
    // 判断文件是否打开成功
    if(!file.open(QIODevice::ReadOnly))
    {
        ui->label->setText("File Open Failed!");
        ui->label->setStyleSheet("color: red");
        settings->setValue("Buttons/LastFilePath", "");
        NowPath = "";
        // 打开失败
        QMessageBox::warning(this, "Warning", "File Open Failed!");
        return;
    }
    // 读取文件
    QByteArray data = file.readAll();
    // 关闭文件
    file.close();
    // 将文件数据转化为json对象
    QJsonDocument doc = QJsonDocument::fromJson(data);
    QJsonObject json = doc.object();

    // 清空frame中所有控件
    ui->myFrame->ClearWidgets();


    // 遍历json对象 并添加按钮 
    for(auto key : json.keys())
    {
        // 获取json对象
        QJsonObject buttonJson = json.value(key).toObject();
        // 创建按钮
        MyPushButton *button = new MyPushButton(ui->myFrame, this, serialPort);
        // 设置按钮
        button->LoadButtonFromJson(buttonJson);
        // 添加按钮到frame中
        ui->myFrame->AddWidget(button);
        // 设置按钮坐标
        int x, y;
        button->GetButtonPos(x, y);
        ui->myFrame->SetWidgetPos(button, x, y);
        // 绑定按钮长按信号到槽
        connect(button, &MyPushButton::rightLongClicked, this, &Buttons::rightLongClicked);
        connect(button, &MyPushButton::rightLongClickedRelease, this, &Buttons::rightLongClickedRelease);
    }
    // 显示文件路径
    ui->label->setText(fileName);
    // 绿色
    ui->label->setStyleSheet("color: darkCyan");
    // 记录文件路径到配置文件
    settings->setValue("Buttons/LastFilePath", fileName);
    NowPath = fileName;
}
    

// 加载按钮组文件
void Buttons::on_Button_Load_clicked()
{
    // 打开文件选择界面
    QString path = "/Serial_Assistant_Cfg/Buttons_Save/";
    QString fileName = QFileDialog::getOpenFileName(this, "Open File", QCoreApplication::applicationDirPath() + path, "Json Files (*.json)");
    this->Load_clicked(fileName);
}

// 保存到当前按钮组文件
void Buttons::on_Button_save_clicked()
{
    QJsonObject json;
    // 获取所有子控件
    QList<QWidget *> widgets = ui->myFrame->findChildren<QWidget *>();
    // 遍历所有子控件 若为MyPushButton则将其添加到json对象中
    for(auto widget : widgets)
    {
        MyPushButton *button = qobject_cast<MyPushButton *>(widget);
        if(button != nullptr)
        {
            QJsonObject buttonJson = button->SaveButtonToJson();
            // 将buttonJson添加到json对象中 key为id
            json.insert(QString::number(button->GetButtonID()), buttonJson);
        }
    }
    // 保存json对象到文件
    // 文件为NowPath
    if(NowPath.isEmpty())
    {
        // 若NowPath为空则调用另存为按钮组文件
        on_Button_save_as_clicked();
        return;
    }
    // 打开文件
    QFile file(NowPath);
    // 判断文件是否打开成功
    if(!file.open(QIODevice::WriteOnly))
    {
        // 打开失败
        QMessageBox::warning(this, "Warning", "File Open Failed!");
        return;
    }
    // 将json对象转化为QJsonDocument
    QJsonDocument doc(json);
    // 将QJsonDocument写入文件
    file.write(doc.toJson());
    // 关闭文件
    file.close();
}



// 另存为按钮组文件
void Buttons::on_Button_save_as_clicked()
{
    QJsonObject json;
    // 获取所有子控件
    QList<QWidget *> widgets = ui->myFrame->findChildren<QWidget *>();
    // 遍历所有子控件 若为MyPushButton则将其添加到json对象中
    for(auto widget : widgets)
    {
        MyPushButton *button = qobject_cast<MyPushButton *>(widget);
        if(button != nullptr)
        {
            QJsonObject buttonJson = button->SaveButtonToJson();
            // 将buttonJson添加到json对象中 key为id
            json.insert(QString::number(button->GetButtonID()), buttonJson);
        }
    }
    // 保存json对象到文件
    // 文件目录为当前目录下的Serial_Assistant_Cfg/Buttons_Save/
    QString path = "/Serial_Assistant_Cfg/Buttons_Save/";
    // 判断是否存在Serial_Assistant_Cfg/Buttons_Save/文件夹
    QDir dir(QCoreApplication::applicationDirPath() + path); // 创建目录对象
    if(!dir.exists())
    {
        // 如果不存在,创建文件夹
        dir.mkpath(QCoreApplication::applicationDirPath() + path);
    }
    // 默认文件名为当前时间戳
    QString Time = QString("%1.json").arg(QDateTime::currentDateTime().toString("yyyyMMddhhmmss"));
    // 打开文件保存界面 限制文件格式为.json 文件名默认为Time 默认路径为path
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", QCoreApplication::applicationDirPath() + path + Time, "Json Files (*.json)");
    // 判断文件名是否为空
    if(fileName.isEmpty())
    {
        return;
    }
    // 打开文件
    QFile file(fileName);
    // 判断文件是否打开成功
    if(!file.open(QIODevice::WriteOnly))
    {
        // 打开失败
        QMessageBox::warning(this, "Warning", "File Open Failed!");
        return;
    }
    // 将json对象转化为QJsonDocument
    QJsonDocument doc(json);
    // 将QJsonDocument写入文件
    file.write(doc.toJson());
    // 关闭文件
    file.close();

    // 重新加载文件
    this->Load_clicked(fileName);
}

// 清空frame中的按钮
void Buttons::on_Button_clear_clicked()
{
    ui->myFrame->ClearWidgets();
}

