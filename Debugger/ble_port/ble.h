#ifndef BLE_H
#define BLE_H

#include <QObject>
#include <QThread>
#include <QVariant>
#include <QList>
#include <QBluetoothServiceDiscoveryAgent>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QLowEnergyController>
#include <QBluetoothServiceInfo>

class BLE : public QObject
{
    Q_OBJECT
public:
    explicit BLE(QObject *parent = nullptr);
    ~BLE();

    void init();

    // 开始扫描设备
    void startScanDevices();
    // 停止扫描设备
    void stopScanDevices();
    // 连接设备
    void connectDevice(QString address);
    // 断开连接
    void disconnectDevice();
    // 连接服务
    void connectService(QString uuid);
    // 绑定特征
    bool bindCharacteristic(QString uuid);
    // 启用通知读取
    bool ble_notify();
    // 终止通知读取
    bool ble_stopNotify();
    // 写入特征
    bool ble_write(QByteArray data);
    // 读取特征
    bool ble_read();
    
    bool getScanning(){
        return isScanning;
    }

    bool getConnect(){
        return isConnect;
    }

    QList<QBluetoothDeviceInfo> getDevices(){   // 获取设备列表
        return bleDevicesList;
    }

    QList<QBluetoothUuid> getServicesUUID(){    // 获取服务uuid列表
        return servicesUUIDList;
    }

    QList<QLowEnergyCharacteristic> getChars(){ // 获取特征列表
        return characterList;
    }

    QBluetoothDeviceInfo getNowDevice(){    // 获取当前设备
        return nowDevice;
    }

    QLowEnergyService *getNowService(){      // 获取当前选中的服务
        return nowService;
    }

    QLowEnergyCharacteristic getNotifyChar(){   // 获取选中的通知特征
        return Notify_character;
    }

    QLowEnergyCharacteristic getWriteChar(){    // 获取选中的写入特征
        return Write_character;
    }

    QLowEnergyCharacteristic getReadChar(){     // 获取选中的读取特征
        return Read_character;
    }

private slots:
    void serviceStateChanged(QLowEnergyService::ServiceState s);
    void ble_notify_changed(const QLowEnergyCharacteristic &c, const QByteArray &value);         // 通知改变

signals:
    void signal_scanAddDevice(QBluetoothDeviceInfo device);

    void signal_scanFinished(bool scan);

    void signal_findservicesFinished();
    void signal_disconnectDevice();

    void signal_findcharsFinished();

    void signal_notifyFinished(QByteArray value);     // 通知读取完成
    void signal_writeFinished(QByteArray value);      // 写入完成
    void signal_readFinished(QByteArray value);       // 读取完成

    // 发送计数信号 参数为新增的字节数
    void signal_bleReadCount(int count);

private:
    QBluetoothDeviceDiscoveryAgent * m_DiscoveryAgent;  // 设备发现对象
    QThread *ble_Thread;     // ble收发线程

    bool isScanning = false;    // 是否正在扫描

    bool isConnect = false;     // 是否已经连接

    QLowEnergyController *          m_LowController = nullptr;    // 中心控制器

    QList<QBluetoothDeviceInfo >    bleDevicesList;

    QString                         previousAddress;        // 之前的设备

    QList<QLowEnergyService>        servicesList;           // 服务列表

    QList<QLowEnergyCharacteristic> characterList;          // 特征列表

    QList<QBluetoothUuid>           servicesUUIDList;       // 服务UUID列表

    QBluetoothDeviceInfo            nowDevice;              // 当前设备
    QLowEnergyService *             nowService;             // 当前服务

    QLowEnergyCharacteristic        Notify_character;       // 通知特征
    QLowEnergyCharacteristic        Write_character;        // 写入特征 包括WriteNoResponse和Write
    QLowEnergyCharacteristic        Read_character;         // 读取特征

};

#endif // BLE_H
