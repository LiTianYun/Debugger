/****************************************************************************
** Meta object code from reading C++ file 'ble.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../ble_port/ble.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ble.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_BLE_t {
    QByteArrayData data[22];
    char stringdata0[351];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BLE_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BLE_t qt_meta_stringdata_BLE = {
    {
QT_MOC_LITERAL(0, 0, 3), // "BLE"
QT_MOC_LITERAL(1, 4, 20), // "signal_scanAddDevice"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 20), // "QBluetoothDeviceInfo"
QT_MOC_LITERAL(4, 47, 6), // "device"
QT_MOC_LITERAL(5, 54, 19), // "signal_scanFinished"
QT_MOC_LITERAL(6, 74, 4), // "scan"
QT_MOC_LITERAL(7, 79, 27), // "signal_findservicesFinished"
QT_MOC_LITERAL(8, 107, 23), // "signal_disconnectDevice"
QT_MOC_LITERAL(9, 131, 24), // "signal_findcharsFinished"
QT_MOC_LITERAL(10, 156, 21), // "signal_notifyFinished"
QT_MOC_LITERAL(11, 178, 5), // "value"
QT_MOC_LITERAL(12, 184, 20), // "signal_writeFinished"
QT_MOC_LITERAL(13, 205, 19), // "signal_readFinished"
QT_MOC_LITERAL(14, 225, 19), // "signal_bleReadCount"
QT_MOC_LITERAL(15, 245, 5), // "count"
QT_MOC_LITERAL(16, 251, 19), // "serviceStateChanged"
QT_MOC_LITERAL(17, 271, 31), // "QLowEnergyService::ServiceState"
QT_MOC_LITERAL(18, 303, 1), // "s"
QT_MOC_LITERAL(19, 305, 18), // "ble_notify_changed"
QT_MOC_LITERAL(20, 324, 24), // "QLowEnergyCharacteristic"
QT_MOC_LITERAL(21, 349, 1) // "c"

    },
    "BLE\0signal_scanAddDevice\0\0"
    "QBluetoothDeviceInfo\0device\0"
    "signal_scanFinished\0scan\0"
    "signal_findservicesFinished\0"
    "signal_disconnectDevice\0"
    "signal_findcharsFinished\0signal_notifyFinished\0"
    "value\0signal_writeFinished\0"
    "signal_readFinished\0signal_bleReadCount\0"
    "count\0serviceStateChanged\0"
    "QLowEnergyService::ServiceState\0s\0"
    "ble_notify_changed\0QLowEnergyCharacteristic\0"
    "c"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BLE[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       5,    1,   72,    2, 0x06 /* Public */,
       7,    0,   75,    2, 0x06 /* Public */,
       8,    0,   76,    2, 0x06 /* Public */,
       9,    0,   77,    2, 0x06 /* Public */,
      10,    1,   78,    2, 0x06 /* Public */,
      12,    1,   81,    2, 0x06 /* Public */,
      13,    1,   84,    2, 0x06 /* Public */,
      14,    1,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      16,    1,   90,    2, 0x08 /* Private */,
      19,    2,   93,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,   11,
    QMetaType::Void, QMetaType::QByteArray,   11,
    QMetaType::Void, QMetaType::QByteArray,   11,
    QMetaType::Void, QMetaType::Int,   15,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, 0x80000000 | 20, QMetaType::QByteArray,   21,   11,

       0        // eod
};

void BLE::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<BLE *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->signal_scanAddDevice((*reinterpret_cast< QBluetoothDeviceInfo(*)>(_a[1]))); break;
        case 1: _t->signal_scanFinished((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->signal_findservicesFinished(); break;
        case 3: _t->signal_disconnectDevice(); break;
        case 4: _t->signal_findcharsFinished(); break;
        case 5: _t->signal_notifyFinished((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 6: _t->signal_writeFinished((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 7: _t->signal_readFinished((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 8: _t->signal_bleReadCount((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->serviceStateChanged((*reinterpret_cast< QLowEnergyService::ServiceState(*)>(_a[1]))); break;
        case 10: _t->ble_notify_changed((*reinterpret_cast< const QLowEnergyCharacteristic(*)>(_a[1])),(*reinterpret_cast< const QByteArray(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QBluetoothDeviceInfo >(); break;
            }
            break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyService::ServiceState >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QLowEnergyCharacteristic >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (BLE::*)(QBluetoothDeviceInfo );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BLE::signal_scanAddDevice)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (BLE::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BLE::signal_scanFinished)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (BLE::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BLE::signal_findservicesFinished)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (BLE::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BLE::signal_disconnectDevice)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (BLE::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BLE::signal_findcharsFinished)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (BLE::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BLE::signal_notifyFinished)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (BLE::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BLE::signal_writeFinished)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (BLE::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BLE::signal_readFinished)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (BLE::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&BLE::signal_bleReadCount)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject BLE::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_BLE.data,
    qt_meta_data_BLE,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *BLE::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BLE::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_BLE.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int BLE::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void BLE::signal_scanAddDevice(QBluetoothDeviceInfo _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BLE::signal_scanFinished(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BLE::signal_findservicesFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void BLE::signal_disconnectDevice()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void BLE::signal_findcharsFinished()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void BLE::signal_notifyFinished(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void BLE::signal_writeFinished(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void BLE::signal_readFinished(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void BLE::signal_bleReadCount(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
