/********************************************************************************
** Form generated from reading UI file 'serial_port_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIAL_PORT_SETTINGS_H
#define UI_SERIAL_PORT_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Serial_Port_Settings
{
public:
    QGridLayout *gridLayout_2;
    QWidget *widget;
    QGridLayout *gridLayout;
    QComboBox *dataBits;
    QComboBox *baudRate;
    QLabel *parityBit_label;
    QLabel *dataBits_label;
    QLabel *Serial_Port_Num_label;
    QLabel *baudRate_label;
    QComboBox *Serial_Port_Num;
    QLabel *stopBit_label;
    QComboBox *parityBit;
    QComboBox *stopBit;
    QWidget *widget1;
    QGridLayout *gridLayout_3;
    QPushButton *Port_Scan_Button;
    QPushButton *Port_Open_Button;

    void setupUi(QDialog *Serial_Port_Settings)
    {
        if (Serial_Port_Settings->objectName().isEmpty())
            Serial_Port_Settings->setObjectName(QString::fromUtf8("Serial_Port_Settings"));
        Serial_Port_Settings->setEnabled(true);
        Serial_Port_Settings->resize(250, 155);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Serial_Port_Settings->sizePolicy().hasHeightForWidth());
        Serial_Port_Settings->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        Serial_Port_Settings->setFont(font);
        gridLayout_2 = new QGridLayout(Serial_Port_Settings);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(5);
        gridLayout_2->setVerticalSpacing(2);
        gridLayout_2->setContentsMargins(5, 5, 5, 5);
        widget = new QWidget(Serial_Port_Settings);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(widget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(5);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        dataBits = new QComboBox(widget);
        dataBits->addItem(QString());
        dataBits->addItem(QString());
        dataBits->addItem(QString());
        dataBits->addItem(QString());
        dataBits->setObjectName(QString::fromUtf8("dataBits"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dataBits->sizePolicy().hasHeightForWidth());
        dataBits->setSizePolicy(sizePolicy2);
        dataBits->setMinimumSize(QSize(100, 20));
        dataBits->setMaximumSize(QSize(16777215, 25));
        dataBits->setFont(font);

        gridLayout->addWidget(dataBits, 2, 1, 1, 1);

        baudRate = new QComboBox(widget);
        baudRate->addItem(QString());
        baudRate->addItem(QString());
        baudRate->addItem(QString());
        baudRate->addItem(QString());
        baudRate->addItem(QString());
        baudRate->addItem(QString());
        baudRate->addItem(QString());
        baudRate->addItem(QString());
        baudRate->addItem(QString());
        baudRate->addItem(QString());
        baudRate->addItem(QString());
        baudRate->addItem(QString());
        baudRate->addItem(QString());
        baudRate->addItem(QString());
        baudRate->addItem(QString());
        baudRate->setObjectName(QString::fromUtf8("baudRate"));
        sizePolicy2.setHeightForWidth(baudRate->sizePolicy().hasHeightForWidth());
        baudRate->setSizePolicy(sizePolicy2);
        baudRate->setMinimumSize(QSize(100, 20));
        baudRate->setMaximumSize(QSize(16777215, 25));
        baudRate->setFont(font);

        gridLayout->addWidget(baudRate, 1, 1, 1, 1);

        parityBit_label = new QLabel(widget);
        parityBit_label->setObjectName(QString::fromUtf8("parityBit_label"));
        parityBit_label->setMinimumSize(QSize(0, 20));
        parityBit_label->setMaximumSize(QSize(70, 25));
        parityBit_label->setFont(font);

        gridLayout->addWidget(parityBit_label, 3, 0, 1, 1);

        dataBits_label = new QLabel(widget);
        dataBits_label->setObjectName(QString::fromUtf8("dataBits_label"));
        dataBits_label->setMinimumSize(QSize(0, 20));
        dataBits_label->setMaximumSize(QSize(70, 25));
        dataBits_label->setFont(font);

        gridLayout->addWidget(dataBits_label, 2, 0, 1, 1);

        Serial_Port_Num_label = new QLabel(widget);
        Serial_Port_Num_label->setObjectName(QString::fromUtf8("Serial_Port_Num_label"));
        Serial_Port_Num_label->setMinimumSize(QSize(30, 20));
        Serial_Port_Num_label->setMaximumSize(QSize(70, 25));
        Serial_Port_Num_label->setFont(font);

        gridLayout->addWidget(Serial_Port_Num_label, 0, 0, 1, 1);

        baudRate_label = new QLabel(widget);
        baudRate_label->setObjectName(QString::fromUtf8("baudRate_label"));
        baudRate_label->setMinimumSize(QSize(0, 20));
        baudRate_label->setMaximumSize(QSize(70, 25));
        baudRate_label->setFont(font);

        gridLayout->addWidget(baudRate_label, 1, 0, 1, 1);

        Serial_Port_Num = new QComboBox(widget);
        Serial_Port_Num->setObjectName(QString::fromUtf8("Serial_Port_Num"));
        sizePolicy2.setHeightForWidth(Serial_Port_Num->sizePolicy().hasHeightForWidth());
        Serial_Port_Num->setSizePolicy(sizePolicy2);
        Serial_Port_Num->setMinimumSize(QSize(100, 20));
        Serial_Port_Num->setMaximumSize(QSize(16777215, 25));
        Serial_Port_Num->setFont(font);

        gridLayout->addWidget(Serial_Port_Num, 0, 1, 1, 1);

        stopBit_label = new QLabel(widget);
        stopBit_label->setObjectName(QString::fromUtf8("stopBit_label"));
        stopBit_label->setMinimumSize(QSize(0, 20));
        stopBit_label->setMaximumSize(QSize(70, 25));
        stopBit_label->setFont(font);

        gridLayout->addWidget(stopBit_label, 4, 0, 1, 1);

        parityBit = new QComboBox(widget);
        parityBit->addItem(QString());
        parityBit->addItem(QString());
        parityBit->addItem(QString());
        parityBit->addItem(QString());
        parityBit->addItem(QString());
        parityBit->setObjectName(QString::fromUtf8("parityBit"));
        sizePolicy2.setHeightForWidth(parityBit->sizePolicy().hasHeightForWidth());
        parityBit->setSizePolicy(sizePolicy2);
        parityBit->setMinimumSize(QSize(100, 20));
        parityBit->setMaximumSize(QSize(16777215, 25));
        parityBit->setFont(font);

        gridLayout->addWidget(parityBit, 3, 1, 1, 1);

        stopBit = new QComboBox(widget);
        stopBit->addItem(QString());
        stopBit->addItem(QString());
        stopBit->addItem(QString());
        stopBit->setObjectName(QString::fromUtf8("stopBit"));
        sizePolicy2.setHeightForWidth(stopBit->sizePolicy().hasHeightForWidth());
        stopBit->setSizePolicy(sizePolicy2);
        stopBit->setMinimumSize(QSize(100, 20));
        stopBit->setMaximumSize(QSize(16777215, 25));
        stopBit->setFont(font);

        gridLayout->addWidget(stopBit, 4, 1, 1, 1);


        gridLayout_2->addWidget(widget, 0, 0, 1, 1);

        widget1 = new QWidget(Serial_Port_Settings);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(widget1->sizePolicy().hasHeightForWidth());
        widget1->setSizePolicy(sizePolicy3);
        gridLayout_3 = new QGridLayout(widget1);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(0);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        Port_Scan_Button = new QPushButton(widget1);
        Port_Scan_Button->setObjectName(QString::fromUtf8("Port_Scan_Button"));
        sizePolicy2.setHeightForWidth(Port_Scan_Button->sizePolicy().hasHeightForWidth());
        Port_Scan_Button->setSizePolicy(sizePolicy2);
        Port_Scan_Button->setMinimumSize(QSize(0, 30));
        Port_Scan_Button->setMaximumSize(QSize(100, 16777215));
        Port_Scan_Button->setFont(font);

        gridLayout_3->addWidget(Port_Scan_Button, 0, 0, 1, 1);

        Port_Open_Button = new QPushButton(widget1);
        Port_Open_Button->setObjectName(QString::fromUtf8("Port_Open_Button"));
        sizePolicy2.setHeightForWidth(Port_Open_Button->sizePolicy().hasHeightForWidth());
        Port_Open_Button->setSizePolicy(sizePolicy2);
        Port_Open_Button->setMinimumSize(QSize(0, 30));
        Port_Open_Button->setMaximumSize(QSize(100, 16777215));
        Port_Open_Button->setFont(font);
        Port_Open_Button->setCheckable(true);
        Port_Open_Button->setChecked(false);
        Port_Open_Button->setAutoRepeatInterval(-1);
        Port_Open_Button->setAutoDefault(false);

        gridLayout_3->addWidget(Port_Open_Button, 1, 0, 1, 1);


        gridLayout_2->addWidget(widget1, 0, 1, 1, 1);


        retranslateUi(Serial_Port_Settings);

        QMetaObject::connectSlotsByName(Serial_Port_Settings);
    } // setupUi

    void retranslateUi(QDialog *Serial_Port_Settings)
    {
        Serial_Port_Settings->setWindowTitle(QCoreApplication::translate("Serial_Port_Settings", "Dialog", nullptr));
        dataBits->setItemText(0, QCoreApplication::translate("Serial_Port_Settings", "5", nullptr));
        dataBits->setItemText(1, QCoreApplication::translate("Serial_Port_Settings", "6", nullptr));
        dataBits->setItemText(2, QCoreApplication::translate("Serial_Port_Settings", "7", nullptr));
        dataBits->setItemText(3, QCoreApplication::translate("Serial_Port_Settings", "8", nullptr));

        baudRate->setItemText(0, QCoreApplication::translate("Serial_Port_Settings", "300", nullptr));
        baudRate->setItemText(1, QCoreApplication::translate("Serial_Port_Settings", "600", nullptr));
        baudRate->setItemText(2, QCoreApplication::translate("Serial_Port_Settings", "1200", nullptr));
        baudRate->setItemText(3, QCoreApplication::translate("Serial_Port_Settings", "2400", nullptr));
        baudRate->setItemText(4, QCoreApplication::translate("Serial_Port_Settings", "4800", nullptr));
        baudRate->setItemText(5, QCoreApplication::translate("Serial_Port_Settings", "9600", nullptr));
        baudRate->setItemText(6, QCoreApplication::translate("Serial_Port_Settings", "14400", nullptr));
        baudRate->setItemText(7, QCoreApplication::translate("Serial_Port_Settings", "19200", nullptr));
        baudRate->setItemText(8, QCoreApplication::translate("Serial_Port_Settings", "38400", nullptr));
        baudRate->setItemText(9, QCoreApplication::translate("Serial_Port_Settings", "56000", nullptr));
        baudRate->setItemText(10, QCoreApplication::translate("Serial_Port_Settings", "57600", nullptr));
        baudRate->setItemText(11, QCoreApplication::translate("Serial_Port_Settings", "115200", nullptr));
        baudRate->setItemText(12, QCoreApplication::translate("Serial_Port_Settings", "128000", nullptr));
        baudRate->setItemText(13, QCoreApplication::translate("Serial_Port_Settings", "256000", nullptr));
        baudRate->setItemText(14, QCoreApplication::translate("Serial_Port_Settings", "460800", nullptr));

        parityBit_label->setText(QCoreApplication::translate("Serial_Port_Settings", "\346\240\241\351\252\214\344\275\215\357\274\232", nullptr));
        dataBits_label->setText(QCoreApplication::translate("Serial_Port_Settings", "\346\225\260\346\215\256\344\275\215\357\274\232", nullptr));
        Serial_Port_Num_label->setText(QCoreApplication::translate("Serial_Port_Settings", "\344\270\262\345\217\243\345\217\267\357\274\232", nullptr));
        baudRate_label->setText(QCoreApplication::translate("Serial_Port_Settings", "\346\263\242\347\211\271\347\216\207\357\274\232", nullptr));
        stopBit_label->setText(QCoreApplication::translate("Serial_Port_Settings", "\345\201\234\346\255\242\344\275\215\357\274\232", nullptr));
        parityBit->setItemText(0, QCoreApplication::translate("Serial_Port_Settings", "None", nullptr));
        parityBit->setItemText(1, QCoreApplication::translate("Serial_Port_Settings", "Even", nullptr));
        parityBit->setItemText(2, QCoreApplication::translate("Serial_Port_Settings", "Odd", nullptr));
        parityBit->setItemText(3, QCoreApplication::translate("Serial_Port_Settings", "Space", nullptr));
        parityBit->setItemText(4, QCoreApplication::translate("Serial_Port_Settings", "Mark", nullptr));

        stopBit->setItemText(0, QCoreApplication::translate("Serial_Port_Settings", "OneStop", nullptr));
        stopBit->setItemText(1, QCoreApplication::translate("Serial_Port_Settings", "OneAndHalfStop", nullptr));
        stopBit->setItemText(2, QCoreApplication::translate("Serial_Port_Settings", "TwoStop", nullptr));

        Port_Scan_Button->setText(QCoreApplication::translate("Serial_Port_Settings", "\346\211\253\346\217\217\344\270\262\345\217\243", nullptr));
        Port_Open_Button->setText(QCoreApplication::translate("Serial_Port_Settings", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Serial_Port_Settings: public Ui_Serial_Port_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIAL_PORT_SETTINGS_H
