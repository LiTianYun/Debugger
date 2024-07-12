#include "ble_port_settings.h"
#include "ui_ble_port_settings.h"



Ble_Port_Settings::Ble_Port_Settings(Widget *parent, BLE *ble) :
    QDialog(parent),
    ui(new Ui::Ble_Port_Settings)
{
    ui->setupUi(this);
    parentWidget = parent;  // 父窗口指针
    m_ble = ble;          // 蓝牙对象指针

    // 设置界面大小自动适应
    this->setMinimumSize(this->width(),this->height());

    connect(m_ble, &BLE::signal_disconnectDevice, 
        this, &Ble_Port_Settings::signal_disconnect_Device);
}   

Ble_Port_Settings::~Ble_Port_Settings()
{
    delete ui;
    // 清除绑定到当前对象的所有信号槽
    disconnect();
}

void Ble_Port_Settings::signal_disconnect_Device()
{
    ui->ble_label->setText("连接已断开");
    ble_connect_Device("",false);
}

/* ------------------------------------------ 蓝牙设备扫描 ------------------------------------------------ */
/**
 * @brief 添加设备列表项槽函数
 * 
 * @param info 
 */
void Ble_Port_Settings::listWidget_dev_addDevice(const QBluetoothDeviceInfo &info)
{
    // 若设备信息为空
    if(info.name().isEmpty() || info.address().toString().isEmpty())
        return;
    // 将设备中的信息添加到列表中
    // 创建设备列表项 name address
    QListWidgetItem *item = new QListWidgetItem(info.name() + "[" + info.address().toString() + "]");
    // 添加设备列表项
    ui->listWidget_dev->addItem(item);
}

/**
 * @brief 扫描完成槽函数
 * 
 */
void Ble_Port_Settings::onScanFinished()
{
    auto list = m_ble->getDevices();    // 获取设备列表
    // 若列表为空，则返回
    if(list.isEmpty()){
        ui->ble_label->setText("没有找到蓝牙设备...");
    }
    // 停止扫描
    ble_scan_device(false);
    ui->ble_label->setText("扫描完成");
}

/**
 * @brief 蓝牙扫描函数
 * 
 * @param scan 
 */
void Ble_Port_Settings::ble_scan_device(bool scan)
{
    if(scan){
        // 绑定搜索到新设备信号到添加设备列表项槽函数
        connect(m_ble, &BLE::signal_scanAddDevice, 
            this, &Ble_Port_Settings::listWidget_dev_addDevice);
        // 绑定扫描完成信号到扫描完成槽函数
        connect(m_ble, &BLE::signal_scanFinished,
            this, &Ble_Port_Settings::onScanFinished);
        // 若没有正在扫描，则开始扫描
        if(!m_ble->getScanning())
        {
            ui->listWidget_dev->clear();    // 清空设备列表
            m_ble->startScanDevices();
        }
        ui->scan_button->setText("停止扫描");
        parentWidget->Button_Switch(ui->scan_button, true);
    }else{
        disconnect(m_ble, &BLE::signal_scanAddDevice, 
            this, &Ble_Port_Settings::listWidget_dev_addDevice);
        disconnect(m_ble, &BLE::signal_scanFinished,
            this, &Ble_Port_Settings::onScanFinished);
        m_ble->stopScanDevices();
        ui->scan_button->setText("扫描");
        parentWidget->Button_Switch(ui->scan_button, false);
    }
}

/**
 * @brief 蓝牙扫描按钮槽函数
 * 
 */
void Ble_Port_Settings::on_scan_button_clicked()
{
    if(parentWidget->Get_Button_Switch(ui->scan_button) == true)
    {
        ui->ble_label->setText("中止扫描");
        ble_scan_device(false);
    }else{
        ui->ble_label->setText("正在扫描...");
        ble_scan_device(true);
    }

}


/* ---------------------------------------- 蓝牙设备扫描end ----------------------------------------------- */

/* ---------------------------------------- 蓝牙设备连接 ------------------------------------------------- */

/**
 * @brief 刷新服务列表槽函数
 * 
 */
void Ble_Port_Settings::on_findservicesFinished()
{
    auto list = m_ble->getServicesUUID();   // 获取服务列表
    if(list.isEmpty())      // 若列表为空，则返回
    {
        ui->ble_label->setText("没有找到服务...");
        return;
    }
    ui->ble_label->setText("请选择服务");
    for(auto s : list){
        ui->list_service->addItem(s.toString());
    }
}

/**
 * @brief 连接/断开设备
 * 
 * @param address 设备地址 sttring
 * @param conn true:连接 false:断开连接
 */
void Ble_Port_Settings::ble_connect_Device(QString address, bool conn)
{
    if(conn){
        parentWidget->Button_Switch(ui->connect_button, true);
        ui->connect_button->setText("断开连接");
        // 绑定连接完成信号到连接完成槽函数
        connect(m_ble,&BLE::signal_findservicesFinished,
            this,&Ble_Port_Settings::on_findservicesFinished);
        // 连接设备
        m_ble->connectDevice(address);
    }else{
        parentWidget->Button_Switch(ui->connect_button, false);
        // 文字变为连接
        ui->connect_button->setText("连接");
        // 断开当前连接
        m_ble->disconnectDevice();
        disconnect(m_ble,&BLE::signal_findservicesFinished,
            this,&Ble_Port_Settings::on_findservicesFinished);
        parentWidget->SerialPort_Status("未连接","BLE");
    }
}

/**
 * @brief 蓝牙连接按钮槽函数
 * 
 */
void Ble_Port_Settings::on_connect_button_clicked()
{
    if(parentWidget->Get_Button_Switch(ui->connect_button) == true)
    {
        ui->ble_label->setText("连接已断开");
        ble_connect_Device("",false);
    }else{
        // 若当前未选中设备
        if(ui->listWidget_dev->currentItem() == nullptr)
        {
            ui->ble_label->setText("未选中设备");
            return;
        }
        // ui变化
        ui->ble_label->setText("正在连接...");
        ui->list_service->clear();          // 清空服务列表
        // 停止扫描
        ble_scan_device(false);
        // 获取当前选中设备的地址
        QString address = ui->listWidget_dev->currentItem()->text().split("[")[1].split("]")[0];
        qDebug()<<"connect address:"<<address;
        // 连接设备
        ble_connect_Device(address,true);
    }
}

/* --------------------------------------- 蓝牙设备连接end ----------------------------------------------- */

/* --------------------------------------- 蓝牙服务选择 ---------------------------------------------------- */
// 特征类型转字符串
QString  PropertyTypes_2_String(QLowEnergyCharacteristic::PropertyTypes property)
{
    QString str;
    if(property & QLowEnergyCharacteristic::Broadcasting)
        str += "Broadcasting, ";
    if(property & QLowEnergyCharacteristic::Read)
        str += "Read, ";
    if(property & QLowEnergyCharacteristic::WriteNoResponse)
        str += "WriteNoResponse, ";
    if(property & QLowEnergyCharacteristic::Write)
        str += "Write, ";
    if(property & QLowEnergyCharacteristic::Notify)
        str += "Notify, ";
    if(property & QLowEnergyCharacteristic::Indicate)
        str += "Indicate, ";
    if(property & QLowEnergyCharacteristic::WriteSigned)
        str += "WriteSigned, ";
    if(property & QLowEnergyCharacteristic::ExtendedProperty)
        str += "ExtendedProperty, ";
    return str;
}

/**
 * @brief 刷新特征列表槽函数
 * 
 */
void Ble_Port_Settings::on_findcharacterFinished()
{
    auto list = m_ble->getChars(); // 获取特征列表
    if(list.isEmpty())      // 若列表为空，则返回
    {
        ui->ble_label->setText("没有找到特征...");
        return;
    }
    ui->ble_label->setText("请选择特征");
    for(auto s : list){
        ui->list_character->addItem(s.name() + 
            "[" + s.uuid().toString() + "]" + 
            "Types: " + PropertyTypes_2_String(s.properties()));
    }
}

/**
 * @brief 选择服务槽函数
 * 
 */
void Ble_Port_Settings::on_service_button_clicked()
{
    // 若当前未选中服务
    if(ui->list_service->currentItem() == nullptr)
    {
        ui->ble_label->setText("未选中服务");
        return;
    }
    // 获取当前选中服务的UUID
    QString uuid = ui->list_service->currentItem()->text();
    // ui变化
    ui->ble_label->setText("请选择特征值");
    ui->list_character->clear();        // 清空特征列表
    // 绑定服务发现完成信号到刷新特征列表槽函数
    disconnect(m_ble,&BLE::signal_findcharsFinished, this, &Ble_Port_Settings::on_findcharacterFinished);
    connect(m_ble,&BLE::signal_findcharsFinished, this, &Ble_Port_Settings::on_findcharacterFinished);
    // 连接服务
    m_ble->connectService(uuid);
}
/* ------------------------------------- 蓝牙服务选择end --------------------------------------------------- */

/* ------------------------------------- 蓝牙特征绑定 ------------------------------------------------------ */


void Ble_Port_Settings::on_binding_character_clicked()
{
    bool ok;
    // 若当前未选中特征
    if(ui->list_character->currentItem() == nullptr)
    {
        ui->ble_label->setText("未选中特征");
        return;
    }
    // 获取当前选中特征的UUID
    QString uuid = ui->list_character->currentItem()->text().split("[")[1].split("]")[0];
    // 绑定特征
    ok = m_ble->bindCharacteristic(uuid);
    if(ok){
        ui->ble_label->setText("绑定成功");
        parentWidget->SerialPort_Status("BLE: " + m_ble->getNowDevice().name() +
            "[" + m_ble->getNowDevice().address().toString() + "]" +
            "特征绑定成功","BLE");
        // 指定特征item背景变为浅绿色
        ui->list_character->currentItem()->setBackground(QColor(0, 255, 0, 100));
    }else{
        ui->ble_label->setText("绑定失败");
    }
}

