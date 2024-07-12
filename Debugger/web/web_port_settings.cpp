#include "web_port_settings.h"
#include "ui_web_port_settings.h"
#include <QNetworkInterface>
#include <QHostInfo>

Web_Port_Settings::Web_Port_Settings(Widget *parent, web_tcp *web) :
    QDialog(parent),
    ui(new Ui::Web_Port_Settings)
{
    ui->setupUi(this);
    parentWidget = parent;  // 父窗口指针
    m_web_tcp = web;        // web_tcp对象指针

    // 设置界面大小自动适应
    this->setMinimumSize(this->width(),this->height());

    // 获取本地ip地址列表并更新ui选择框
    this->on_Update_Button_clicked(); 
    // ui->ip_comboBox更改时，更新ui->ip_Edit
    connect(ui->ip_comboBox, &QComboBox::currentTextChanged, [=](const QString& text){
        ui->ip_Edit->setText(text.split(" ").at(0));
    });
    // ui->ip_Edit默认为ip_comboBox选中的ip地址
    ui->ip_Edit->setText(ui->ip_comboBox->currentText().split(" ").at(0));
    // ui->port_Edit设置为默认端口8070
    ui->port_Edit->setText("8070");
    
    // 绑定model_comboBox更改时的槽函数
    connect(ui->model_comboBox, &QComboBox::currentTextChanged, [=](const QString& text){
        if(text == "TCP Server")
        {
            // 隐藏Connect_Server_Button
            ui->Connect_Server_Button->hide();
            // 显示Server_Create_Button
            ui->Server_Create_Button->show();
            // 显示Server_box
            ui->Server_box->show();
        }
        else if(text == "TCP Client")
        {
            // 显示Connect_Server_Button
            ui->Connect_Server_Button->show();
            // 隐藏Server_Create_Button
            ui->Server_Create_Button->hide();
            // 隐藏Server_box
            ui->Server_box->hide();
        }
    });
    if(m_web_tcp->getMode() == web_tcp::TCP_SERVER)
    {
        parentWidget->Button_Switch(ui->Server_Create_Button, true);
        ui->label_log->setText("正在监听");
        ui->Server_Create_Button->setText("停止监听");
    }
    if(m_web_tcp->getMode() == web_tcp::TCP_CLIENT)
    {   
        // 显示Connect_Server_Button
        ui->Connect_Server_Button->show();
        // 隐藏Server_Create_Button
        ui->Server_Create_Button->hide();
        // 隐藏Server_box
        ui->Server_box->hide();
    }else{
        ui->model_comboBox->setCurrentIndex(0);  // 默认选择TCP Server
        // 隐藏Connect_Server_Button
        ui->Connect_Server_Button->hide();
        // 显示Server_Create_Button
        ui->Server_Create_Button->show();
        // 显示Server_box
        ui->Server_box->show();
    }
    
}

Web_Port_Settings::~Web_Port_Settings()
{
    delete ui;
    // 清除绑定到当前对象的所有信号槽
    disconnect();
}


// 获取本地ip地址列表并更新ui选择框
void Web_Port_Settings::on_Update_Button_clicked()
{
    ui->ip_comboBox->clear();
    //本地主机名
    QString hostName = QHostInfo::localHostName();
    //本机IP地址
    QHostInfo hostInfo = QHostInfo::fromName(hostName);
    //IP地址列表
    QList<QHostAddress> addrList = hostInfo.addresses();
    for (int i = 0; i < addrList.count(); i++) 
    {
        QHostAddress host = addrList.at(i);

        if (QAbstractSocket::IPv4Protocol == host.protocol()) 
        {
            QString ip = host.toString();

            QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
            for (const QNetworkInterface& iface : interfaces) {
                QList<QNetworkAddressEntry> entries = iface.addressEntries();
                for (const QNetworkAddressEntry& entry : entries) 
                {
                    if (entry.ip() == host) 
                    {
                        QString name = iface.name();
                        // 将name里的"wireless"替换为"无线适配器"
                        // “ethernet”替换为"以太网适配器"
                        name.replace("wireless", "无线适配器");
                        name.replace("ethernet", "以太网适配器");
                        ui->ip_comboBox->addItem(ip + " [" + name + "]");
                        break;
                    }
                }
            }
        }
    }      
}


/**
 * @brief 服务器监听按钮
 * 
 */
void Web_Port_Settings::on_Server_Create_Button_clicked()
{
    // 获取ip地址
    QString ip = ui->ip_Edit->text();
    // 获取端口号
    qint16 port = ui->port_Edit->text().toInt();
    if(parentWidget->Get_Button_Switch(ui->Server_Create_Button) == true)
    {
        // 停止监听
        m_web_tcp->tcp_stop_listen();
        ui->label_log->setText("停止监听");
        parentWidget->Button_Switch(ui->Server_Create_Button, false);
        ui->Server_Create_Button->setText("监听端口");
    }else{
        // 开始监听
        m_web_tcp->tcp_listen(ip, port);
        ui->label_log->setText("开始监听");
        parentWidget->Button_Switch(ui->Server_Create_Button, true);
        ui->Server_Create_Button->setText("停止监听");
    }
}

void Web_Port_Settings::tcp_client_connected_slot()
{
    ui->label_log->setText("连接成功");
    parentWidget->Button_Switch(ui->Connect_Server_Button, true);
}

void Web_Port_Settings::tcp_client_disconnected_slot()
{
    ui->label_log->setText("断开连接");
    parentWidget->Button_Switch(ui->Connect_Server_Button, false);
}

/**
 * @brief 连接服务器按钮
 * 
 */
void Web_Port_Settings::on_Connect_Server_Button_clicked()
{
    // 获取ip地址
    QString ip = ui->ip_Edit->text();
    // 获取端口号
    qint16 port = ui->port_Edit->text().toInt();
    if(parentWidget->Get_Button_Switch(ui->Connect_Server_Button) == true)
    {
        // 断开连接
        m_web_tcp->tcp_disconnect();
        ui->label_log->setText("正在断开连接...");
    }else{
        // 连接服务器
        m_web_tcp->tcp_connect(ip, port);
        ui->label_log->setText("正在连接...");
    }
    disconnect(m_web_tcp, &web_tcp::tcp_client_connected, this, 
        &Web_Port_Settings::tcp_client_connected_slot);
    disconnect(m_web_tcp, &web_tcp::tcp_client_disconnected, this, 
        &Web_Port_Settings::tcp_client_disconnected_slot);
    connect(m_web_tcp, &web_tcp::tcp_client_connected, this, 
        &Web_Port_Settings::tcp_client_connected_slot);
    connect(m_web_tcp, &web_tcp::tcp_client_disconnected, this, 
        &Web_Port_Settings::tcp_client_disconnected_slot);
}

