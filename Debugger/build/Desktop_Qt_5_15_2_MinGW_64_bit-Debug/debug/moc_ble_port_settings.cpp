/****************************************************************************
** Meta object code from reading C++ file 'ble_port_settings.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../ble_port/ble_port_settings.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ble_port_settings.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Ble_Port_Settings_t {
    QByteArrayData data[13];
    char stringdata0[263];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ble_Port_Settings_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ble_Port_Settings_t qt_meta_stringdata_Ble_Port_Settings = {
    {
QT_MOC_LITERAL(0, 0, 17), // "Ble_Port_Settings"
QT_MOC_LITERAL(1, 18, 24), // "signal_disconnect_Device"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 24), // "listWidget_dev_addDevice"
QT_MOC_LITERAL(4, 69, 20), // "QBluetoothDeviceInfo"
QT_MOC_LITERAL(5, 90, 4), // "info"
QT_MOC_LITERAL(6, 95, 14), // "onScanFinished"
QT_MOC_LITERAL(7, 110, 23), // "on_findservicesFinished"
QT_MOC_LITERAL(8, 134, 24), // "on_findcharacterFinished"
QT_MOC_LITERAL(9, 159, 22), // "on_scan_button_clicked"
QT_MOC_LITERAL(10, 182, 25), // "on_connect_button_clicked"
QT_MOC_LITERAL(11, 208, 25), // "on_service_button_clicked"
QT_MOC_LITERAL(12, 234, 28) // "on_binding_character_clicked"

    },
    "Ble_Port_Settings\0signal_disconnect_Device\0"
    "\0listWidget_dev_addDevice\0"
    "QBluetoothDeviceInfo\0info\0onScanFinished\0"
    "on_findservicesFinished\0"
    "on_findcharacterFinished\0"
    "on_scan_button_clicked\0on_connect_button_clicked\0"
    "on_service_button_clicked\0"
    "on_binding_character_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ble_Port_Settings[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x08 /* Private */,
       3,    1,   60,    2, 0x08 /* Private */,
       6,    0,   63,    2, 0x08 /* Private */,
       7,    0,   64,    2, 0x08 /* Private */,
       8,    0,   65,    2, 0x08 /* Private */,
       9,    0,   66,    2, 0x08 /* Private */,
      10,    0,   67,    2, 0x08 /* Private */,
      11,    0,   68,    2, 0x08 /* Private */,
      12,    0,   69,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Ble_Port_Settings::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Ble_Port_Settings *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_disconnect_Device(); break;
        case 1: _t->listWidget_dev_addDevice((*reinterpret_cast< const QBluetoothDeviceInfo(*)>(_a[1]))); break;
        case 2: _t->onScanFinished(); break;
        case 3: _t->on_findservicesFinished(); break;
        case 4: _t->on_findcharacterFinished(); break;
        case 5: _t->on_scan_button_clicked(); break;
        case 6: _t->on_connect_button_clicked(); break;
        case 7: _t->on_service_button_clicked(); break;
        case 8: _t->on_binding_character_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothDeviceInfo >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Ble_Port_Settings::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Ble_Port_Settings.data,
    qt_meta_data_Ble_Port_Settings,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Ble_Port_Settings::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ble_Port_Settings::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Ble_Port_Settings.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Ble_Port_Settings::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
