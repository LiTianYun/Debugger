/****************************************************************************
** Meta object code from reading C++ file 'button_setting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../Buttons/button_setting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'button_setting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Button_Setting_t {
    QByteArrayData data[17];
    char stringdata0[223];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Button_Setting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Button_Setting_t qt_meta_stringdata_Button_Setting = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Button_Setting"
QT_MOC_LITERAL(1, 15, 10), // "saveButton"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 7), // "setName"
QT_MOC_LITERAL(4, 35, 4), // "name"
QT_MOC_LITERAL(5, 40, 8), // "setColor"
QT_MOC_LITERAL(6, 49, 5), // "color"
QT_MOC_LITERAL(7, 55, 6), // "setHex"
QT_MOC_LITERAL(8, 62, 3), // "hex"
QT_MOC_LITERAL(9, 66, 7), // "setData"
QT_MOC_LITERAL(10, 74, 4), // "data"
QT_MOC_LITERAL(11, 79, 22), // "on_colorButton_clicked"
QT_MOC_LITERAL(12, 102, 27), // "on_nameEdit_editingFinished"
QT_MOC_LITERAL(13, 130, 22), // "on_radioButton_clicked"
QT_MOC_LITERAL(14, 153, 23), // "on_dataEdit_textChanged"
QT_MOC_LITERAL(15, 177, 23), // "on_DeleteButton_clicked"
QT_MOC_LITERAL(16, 201, 21) // "on_SaveButton_clicked"

    },
    "Button_Setting\0saveButton\0\0setName\0"
    "name\0setColor\0color\0setHex\0hex\0setData\0"
    "data\0on_colorButton_clicked\0"
    "on_nameEdit_editingFinished\0"
    "on_radioButton_clicked\0on_dataEdit_textChanged\0"
    "on_DeleteButton_clicked\0on_SaveButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Button_Setting[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   70,    2, 0x0a /* Public */,
       5,    1,   73,    2, 0x0a /* Public */,
       7,    1,   76,    2, 0x0a /* Public */,
       9,    1,   79,    2, 0x0a /* Public */,
      11,    0,   82,    2, 0x08 /* Private */,
      12,    0,   83,    2, 0x08 /* Private */,
      13,    0,   84,    2, 0x08 /* Private */,
      14,    0,   85,    2, 0x08 /* Private */,
      15,    0,   86,    2, 0x08 /* Private */,
      16,    0,   87,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QColor,    6,
    QMetaType::Void, QMetaType::Bool,    8,
    QMetaType::Void, QMetaType::QByteArray,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Button_Setting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Button_Setting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->saveButton(); break;
        case 1: _t->setName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setColor((*reinterpret_cast< const QColor(*)>(_a[1]))); break;
        case 3: _t->setHex((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 4: _t->setData((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 5: _t->on_colorButton_clicked(); break;
        case 6: _t->on_nameEdit_editingFinished(); break;
        case 7: _t->on_radioButton_clicked(); break;
        case 8: _t->on_dataEdit_textChanged(); break;
        case 9: _t->on_DeleteButton_clicked(); break;
        case 10: _t->on_SaveButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Button_Setting::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Button_Setting::saveButton)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Button_Setting::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_Button_Setting.data,
    qt_meta_data_Button_Setting,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Button_Setting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Button_Setting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Button_Setting.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Button_Setting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void Button_Setting::saveButton()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
