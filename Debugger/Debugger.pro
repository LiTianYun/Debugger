QT       += core gui
QT       += serialport
QT       += charts
QT       += bluetooth
QT       += network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17 static

#解决编译时无法解释中文的问题
msvc {
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Buttons/button_setting.cpp \
    Buttons/buttons.cpp \
    Wave/legenditemdialog.cpp \
    Wave/mycustomplot.cpp \
    Wave/qcustomplot.cpp \
    Wave/wavepage.cpp \
    ble_port/ble_port_settings.cpp \
    ble_port/ble.cpp \
    serial_port/serial_port_settings.cpp \
    serial_port/serialport.cpp \
    web/web_port_settings.cpp \
    web/web_tcp.cpp \
    widget.cpp \
    main.cpp

HEADERS += \
    Buttons/button_setting.h \
    Buttons/buttons.h \
    Wave/legenditemdialog.h \
    Wave/mycustomplot.h \
    Wave/qcustomplot.h \
    Wave/wavepage.h \
    ble_port/ble_port_settings.h \
    ble_port/ble.h \
    serial_port/serial_port_settings.h \
    serial_port/serialport.h \
    web/web_port_settings.h \
    web/web_tcp.h \
    widget.h

FORMS += \
    Buttons/button_setting.ui \
    Buttons/buttons.ui \
    Wave/legenditemdialog.ui \
    Wave/wavepage.ui \
    ble_port/ble_port_settings.ui \
    serial_port/serial_port_settings.ui \
    web/web_port_settings.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RC_ICONS = ico.ico
