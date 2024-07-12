#ifndef BLE_PORT_SETTINGS_H
#define BLE_PORT_SETTINGS_H

#include <QDialog>
#include "widget.h"
#include "ble.h"

namespace Ui {
class Ble_Port_Settings;
}

class Ble_Port_Settings : public QDialog
{
    Q_OBJECT

public:
    explicit Ble_Port_Settings(Widget *parent = nullptr, BLE *ble = nullptr);
    ~Ble_Port_Settings();

private slots:
    void signal_disconnect_Device();
    void listWidget_dev_addDevice(const QBluetoothDeviceInfo &info);
    void onScanFinished();
    void on_findservicesFinished();
    void on_findcharacterFinished();

    void on_scan_button_clicked();
    void on_connect_button_clicked();

    void on_service_button_clicked();

    void on_binding_character_clicked();

private:
    Ui::Ble_Port_Settings *ui;
    Widget *parentWidget;                        // 父窗口

    BLE *m_ble;                                  // 蓝牙对象

    void ble_scan_device(bool scan);
    void ble_connect_Device(QString address, bool conn);
};

#endif // BLE_PORT_SETTINGS_H
