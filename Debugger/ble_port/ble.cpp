#include "ble.h"

BLE::BLE(QObject *parent) : QObject(parent)
{
    ble_Thread = new QThread();      // 多线程对象
    this->moveToThread(ble_Thread);  // 将当前对象移动到多线程中
    ble_Thread->start();             // 启动多线程
    init();
}

BLE::~BLE()
{
    delete m_LowController;
    delete m_DiscoveryAgent;
    servicesList.clear();
    characterList.clear();
    bleDevicesList.clear();
    // 停止多线程
    ble_Thread->quit();
}

void BLE::init()
{
    // 创建蓝牙设备发现代理对象
    m_DiscoveryAgent = new QBluetoothDeviceDiscoveryAgent();
    // 设置低能耗设备发现超时时间为10000毫秒
    m_DiscoveryAgent->setLowEnergyDiscoveryTimeout(100000);
    // 当发现蓝牙设备时触发deviceDiscovered信号，将设备信息添加到bleDevicesList列表中
    connect(m_DiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered,
        [=](const QBluetoothDeviceInfo &info)
        {
            // 如果是BLE设备，则将其添加到设备列表中
            if (info.coreConfigurations() & QBluetoothDeviceInfo::LowEnergyCoreConfiguration){
                if(!bleDevicesList.contains(info)){
                    qDebug()<<"发现蓝牙设备:"<<info.name()<<info.address().toString();
                    emit signal_scanAddDevice(info);
                    bleDevicesList.append(info);
                }
            }
        }
    );
    // 当发生蓝牙设备发现代理错误时触发error信号，根据错误类型输出相应的错误信息
    connect(m_DiscoveryAgent, 
        // QBluetoothDeviceDiscoveryAgent中有两个error函数, 分别为公共函数:Error error() const;
        // 和信号函数: void error(QBluetoothDeviceDiscoveryAgent::Error error);
        // 此处使用QOverload确定为参数为QBluetoothDeviceDiscoveryAgent::Error类型的信号函数
        QOverload<QBluetoothDeviceDiscoveryAgent::Error>::of(&QBluetoothDeviceDiscoveryAgent::error),
        // [=]表示以值传递的方式捕获外部变量，此处为error
        [=](QBluetoothDeviceDiscoveryAgent::Error error)
        {
            if (error == QBluetoothDeviceDiscoveryAgent::PoweredOffError){
                emit signal_scanFinished(false);
                qDebug("蓝牙已关闭");
            }
            else if (error == QBluetoothDeviceDiscoveryAgent::InputOutputError){
                emit signal_scanFinished(false);
                qDebug("写入或读取设备导致错误");
            }
        }
    );
    // 当蓝牙设备发现代理完成扫描时触发finished信号，根据扫描结果输出相应的信息，并发出scanFinished信号
    connect(m_DiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished, 
    [=]{
        if (bleDevicesList.isEmpty())
        {
            qDebug("没有找到蓝牙设备...");
            emit signal_scanFinished(false);
        }else{
            qDebug("扫描完成");
            emit signal_scanFinished(true);
        }
        isScanning = false;
    });
}

//开始扫描设备
void BLE::startScanDevices()
{
    //清空设备列表
    bleDevicesList.clear();
    //开始扫描
    m_DiscoveryAgent->start();  // 开始扫描
    if(m_DiscoveryAgent->isActive()){   // 判断是否正在扫描
        qDebug("Scanning.\n");
        isScanning = true;
    }
}

//停止扫描设备
void BLE::stopScanDevices()
{
    m_DiscoveryAgent->stop();   // 停止扫描 
    if(!m_DiscoveryAgent->isActive()){
        qDebug("Stop scanning.\n");
        isScanning = false;
    }
}

//连接设备
void BLE::connectDevice(QString address)
{
    for(auto dev : bleDevicesList){
        if(dev.address().toString() == address){
            nowDevice = dev;
        }
    }
    if(!nowDevice.isValid()){
        qDebug("Not a valid device"); // 如果设备无效，则打印错误消息并返回
        return;
    }

    servicesList.clear(); // 清空服务列表
    characterList.clear(); // 清空特征列表

    if (m_LowController && previousAddress != nowDevice.address().toString()) {
        m_LowController->disconnectFromDevice(); // 如果之前已经连接了设备，则断开连接
        delete m_LowController; // 删除之前的控制器对象
        m_LowController = nullptr;
    }

    if (!m_LowController) {
        m_LowController = QLowEnergyController::createCentral(nowDevice); // 创建新的低功耗控制器对象
        connect(m_LowController, &QLowEnergyController::connected,[=](){
            qDebug("Device connect success."); // 设备连接成功时打印成功消息
            m_LowController->discoverServices(); // 发现设备的服务
        });
        connect(m_LowController, QOverload<QLowEnergyController::Error>::of(&QLowEnergyController::error),[=](QLowEnergyController::Error){
            qDebug()<<"Error : "+m_LowController->errorString(); // 打印错误消息
        });
        connect(m_LowController, &QLowEnergyController::disconnected,[=]{
            qDebug("Device disconnected."); // 设备断开连接时打印消息
            emit signal_disconnectDevice(); // 发送信号，表示设备断开连接
        });
        connect(m_LowController, &QLowEnergyController::serviceDiscovered,[=]{
            // 处理服务发现事件
        });
        connect(m_LowController, &QLowEnergyController::discoveryFinished,[=]{
            qDebug("Services scan finished."); // 服务扫描完成时打印消息

            servicesUUIDList = m_LowController->services(); // 获取发现的服务列表
            for(auto s : servicesUUIDList){
                qDebug()<<s.toString(); // 打印每个服务的UUID
            }
            emit signal_findservicesFinished(); // 发送信号，表示服务发现完成
        });
    }

    m_LowController->connectToDevice(); // 连接到设备
    previousAddress = nowDevice.address().toString(); // 更新之前连接的设备地址
}

// 断开当前连接
void BLE::disconnectDevice()
{
    if(m_LowController){
        m_LowController->disconnectFromDevice(); // 如果之前已经连接了设备，则断开连接
        delete m_LowController; // 删除之前的控制器对象
        m_LowController = nullptr;
    }
}

/**
 * @brief 连接服务
 * 
 * @param uuid 
 */
void BLE::connectService(QString uuid)
{
    QLowEnergyService *service = nullptr;

    for(int i = 0; i < servicesUUIDList.length(); i++)
    {
        // 检查服务UUID是否匹配
        if(servicesUUIDList.at(i).toString() == uuid){
            // 创建服务对象
            service = m_LowController->createServiceObject(servicesUUIDList.at(i), this);
            break; // 找到匹配的服务，跳出循环
        }
    }

    if (!service) return;   // 如果服务对象无效，则返回
    nowService = service;   // 更新当前选中的服务对象

    characterList.clear(); // 清空特征列表

    // 连接服务状态改变的信号
    disconnect(service, &QLowEnergyService::stateChanged, this, &BLE::serviceStateChanged);
    connect(service, &QLowEnergyService::stateChanged, this, &BLE::serviceStateChanged);

    if(service->state() == QLowEnergyService::DiscoveryRequired){
        // 发现服务的详细信息
        service->discoverDetails();
        return;
    }else if(service->state() == QLowEnergyService::ServiceDiscovered){
        characterList = service->characteristics(); // 获取服务的特征列表
        emit signal_findcharsFinished();    // 触发特征发现完成信号
    }
}

/**
 * @brief 服务状态变化 槽函数
 * 
 * @param s 服务状态
 */
void BLE::serviceStateChanged(QLowEnergyService::ServiceState s)
{
    qDebug()<<"State : "<<s; // 打印服务状态
    if (s == QLowEnergyService::ServiceDiscovered)  // 如果服务已被发现
    {
        // 获取本次触发信号的服务对象
        const QLowEnergyService *service = qobject_cast<QLowEnergyService *>(sender());
        if (!service) return;   // 如果服务对象无效，则返回

    // 描述符修改
    connect(service,&QLowEnergyService::descriptorWritten,[=](const QLowEnergyDescriptor &descriptor, const QByteArray &newValue){
        QString Charname = QString("%1").arg(descriptor.name());
        qDebug()<<"BLE设备-"+Charname+"描述符成功写入值："+ QString(newValue);
    });
    // 各种错误信息
    connect(service, static_cast<void(QLowEnergyService::*)(QLowEnergyService::ServiceError)>(&QLowEnergyService::error),
            [=](QLowEnergyService::ServiceError newErrorr)
    {
        if(QLowEnergyService::NoError == newErrorr){
            qDebug()<<"没有发生错误。\n";
        }
        if(QLowEnergyService::OperationError==newErrorr){
            qDebug()<<"错误: 当服务没有准备好时尝试进行操作!\n";
        }
        if(QLowEnergyService::CharacteristicReadError==newErrorr){
            qDebug()<<"尝试读取特征值失败!\n";
        }
        if(QLowEnergyService::CharacteristicWriteError==newErrorr){
            qDebug()<<"尝试为特性写入新值失败!\n";
        }
        if(QLowEnergyService::DescriptorReadError==newErrorr){
            qDebug()<<"尝试读取描述符值失败!\n";
        }
        if(QLowEnergyService::DescriptorWriteError==newErrorr){
            qDebug()<<"尝试向描述符写入新值失败!\n";
        }
        if(QLowEnergyService::UnknownError==newErrorr){
            qDebug()<<"与服务交互时发生未知错误!\n";
        }
    });

        characterList = service->characteristics(); // 获取服务的特征列表
        emit signal_findcharsFinished();    // 触发特征发现完成信号
    }
}


// 绑定特征
bool BLE::bindCharacteristic(QString uuid)
{
    bool ret = false;
    QLowEnergyCharacteristic notifyChar;
    for(auto s : characterList){
        if(s.uuid().toString() == uuid){
            notifyChar = s;
            break;
        }
    }
    if(!notifyChar.isValid()) return false; // 如果特征无效，则返回

    // 如果特征支持Notify
    if(notifyChar.properties() & QLowEnergyCharacteristic::Notify){
        // 获取通知描述符
        QLowEnergyDescriptor notice = notifyChar.descriptor(QBluetoothUuid::ClientCharacteristicConfiguration); 
        if(notice.isValid()){
            // 启用Notify
            nowService->writeDescriptor(notice,QByteArray::fromHex("0100"));    // 启用通知
            Notify_character = notifyChar;
            ret = true;
        }
    }
    // 如果特征支持Read
    if(notifyChar.properties() & QLowEnergyCharacteristic::Read){
        Read_character = notifyChar;
        ret = true;
    }
    // 如果特征支持WriteNoResponse或者Write
    if(notifyChar.properties() & QLowEnergyCharacteristic::WriteNoResponse 
        ||  notifyChar.properties() & QLowEnergyCharacteristic::Write){
        Write_character = notifyChar;
        ret = true;
    }
    isConnect = ret;
    return ret;
}

// 通知修改 槽函数
void BLE::ble_notify_changed(const QLowEnergyCharacteristic &c, const QByteArray &value)
{
    int len = value.length();
    emit signal_bleReadCount(len);  // 发送计数显示

    emit signal_notifyFinished(value);  // 发送通知值
}

// 启用通知读取
bool BLE::ble_notify()
{
    if(!Notify_character.isValid()) return false;        // 如果特征无效，则返回
    // BLE设备特征值改变
    connect(nowService, &QLowEnergyService::characteristicChanged, this, &BLE::ble_notify_changed);
    return true;
}
// 终止通知读取
bool BLE::ble_stopNotify()
{
    if(!Notify_character.isValid()) return false;        // 如果特征无效，则返回
    // BLE设备特征值改变
    disconnect(nowService, &QLowEnergyService::characteristicChanged, this, &BLE::ble_notify_changed);
    return true;
}

// 向特征写入数据
bool BLE::ble_write(QByteArray data)
{
    if(!Write_character.isValid()) return false;        // 如果特征无效，则返回
    nowService->writeCharacteristic(Write_character,data);   // 写入特征值
    connect(nowService, &QLowEnergyService::characteristicWritten,[=](const QLowEnergyCharacteristic &c, const QByteArray &value){
        QString Charname = c.uuid().toString();
        QString val = value.toHex();
        qDebug()<<"BLE设备-"+Charname+"特性值成功写入值："+ val;
        emit signal_writeFinished(value);
    });
    return true;
}

// 读取特征值
bool BLE::ble_read()
{
    if(!Read_character.isValid()) return false;         // 如果特征无效，则返回
    nowService->readCharacteristic(Read_character);    // 读取特征值
    connect(nowService,&QLowEnergyService::characteristicRead,[=](const QLowEnergyCharacteristic &c, const QByteArray &value){
        QString Charname = c.uuid().toString();
        QString val = value.toHex();
        qDebug()<<"BLE设备-"+Charname+"特性值读取到的值："+ val;
        emit signal_readFinished(value);
    });
    return true;
}


// void BLE::serviceDetailsDiscovered(QLowEnergyService::ServiceState newState)
// {
    // qDebug()<<"State : "<<newState; // 打印服务状态

    // // 如果服务状态不是已发现或正在发现，则返回
    // if (newState != QLowEnergyService::ServiceDiscovered || 
    //     newState == QLowEnergyService::DiscoveringServices) return;

    // // 获取服务对象
    // auto service = qobject_cast<QLowEnergyService *>(sender());
    // if (!service) return; // 如果服务对象无效，则返回

    // // BLE设备特征值改变
    // connect(service, &QLowEnergyService::characteristicChanged,[=](const QLowEnergyCharacteristic &c, const QByteArray &value){
    //     QString Charuuid = c.uuid().toString();
    //     QString Value = value.toHex();
    //     qDebug()<<"BLE设备-"+Charuuid+"特性值发生变化："+ Value;
    // });
    // // 当特征读取请求成功返回其值时，发出此信号。
    // connect(service,&QLowEnergyService::characteristicRead,[=](const QLowEnergyCharacteristic &c, const QByteArray &value){
    //     QString Charname = c.uuid().toString();
    //     QString Value = value.toHex();
    //     qDebug()<<"BLE设备-"+Charname+"特性值读取到的值："+ Value;
    // });
    // // 当特性值成功更改为newValue时，会发出此信号。
    // connect(service,&QLowEnergyService::characteristicWritten,[=](const QLowEnergyCharacteristic &c, const QByteArray &value){
    //     QString Charname = c.uuid().toString();
    //     QString Value = value.toHex();
    //     qDebug()<<"BLE设备-"+Charname+"特性值成功写入值："+ Value;
    // });
    // // 描述符修改
    // connect(service,&QLowEnergyService::descriptorWritten,[=](const QLowEnergyDescriptor &descriptor, const QByteArray &newValue){
    //     QString Charname = QString("%1").arg(descriptor.name());
    //     qDebug()<<"BLE设备-"+Charname+"描述符成功写入值："+ QString(newValue);
    // });
    // 各种错误信息
    // connect(service, static_cast<void(QLowEnergyService::*)(QLowEnergyService::ServiceError)>(&QLowEnergyService::error),
    //         [=](QLowEnergyService::ServiceError newErrorr)
    // {
    //     if(QLowEnergyService::NoError == newErrorr){
    //         qDebug()<<"没有发生错误。\n";
    //     }
    //     if(QLowEnergyService::OperationError==newErrorr){
    //         qDebug()<<"错误: 当服务没有准备好时尝试进行操作!\n";
    //     }
    //     if(QLowEnergyService::CharacteristicReadError==newErrorr){
    //         qDebug()<<"尝试读取特征值失败!\n";
    //     }
    //     if(QLowEnergyService::CharacteristicWriteError==newErrorr){
    //         qDebug()<<"尝试为特性写入新值失败!\n";
    //     }
    //     if(QLowEnergyService::DescriptorReadError==newErrorr){
    //         qDebug()<<"尝试读取描述符值失败!\n";
    //     }
    //     if(QLowEnergyService::DescriptorWriteError==newErrorr){
    //         qDebug()<<"尝试向描述符写入新值失败!\n";
    //     }
    //     if(QLowEnergyService::UnknownError==newErrorr){
    //         qDebug()<<"与服务交互时发生未知错误!\n";
    //     }
    // });

    // characterList = service->characteristics(); // 获取服务的特征列表
    // emit signal_findcharsFinished();    // 触发特征发现完成信号

    // for(auto s : characterList){
    //     qDebug()<<s.uuid(); // 打印特征的UUID
    // }
    // 遍历特征列表
    // for (const QLowEnergyCharacteristic &ch : characterList) {  
    //     // 如果特征有效
    //     if(ch.isValid()){   
    //         // 如果特征支持通知
    //         if(ch.properties() & QLowEnergyCharacteristic::Notify){ 
    //             QLowEnergyDescriptor notice = ch.descriptor(QBluetoothUuid::ClientCharacteristicConfiguration);
    //             if(notice.isValid()){
    //                 // 启用通知
    //                 service->writeDescriptor(notice,QByteArray::fromHex("0100"));   
    //             }
    //         }
    //         // 如果特征支持无响应写入或写入
    //         if(ch.properties() & QLowEnergyCharacteristic::WriteNoResponse ||  ch.properties() & QLowEnergyCharacteristic::Write){
    //             // 写入特性值
    //             QByteArray arr;
    //             arr.resize(20);
    //             for(int i=0;i<20;i++){
    //                 arr[i] = static_cast<char>(i);
    //             }
    //             service->writeCharacteristic(ch,arr);   // 写入特征值
    //         }
    //         // 如果特征支持读取
    //         if(ch.properties() & QLowEnergyCharacteristic::Read){
    //             // 读取特性值
    //             service->readCharacteristic(ch);    // 读取特征值
    //         }
    //     }
    // }
// }
