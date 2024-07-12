/********************************************************************************
** Form generated from reading UI file 'ble_port_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BLE_PORT_SETTINGS_H
#define UI_BLE_PORT_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Ble_Port_Settings
{
public:
    QVBoxLayout *verticalLayout_4;
    QLabel *ble_label;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget_dev;
    QVBoxLayout *verticalLayout;
    QPushButton *scan_button;
    QPushButton *connect_button;
    QSpacerItem *verticalSpacer;
    QPushButton *help_button;
    QWidget *service_box;
    QVBoxLayout *verticalLayout_2;
    QListWidget *list_service;
    QPushButton *service_button;
    QWidget *character_box;
    QVBoxLayout *verticalLayout_3;
    QListWidget *list_character;
    QPushButton *binding_character;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *Ble_Port_Settings)
    {
        if (Ble_Port_Settings->objectName().isEmpty())
            Ble_Port_Settings->setObjectName(QString::fromUtf8("Ble_Port_Settings"));
        Ble_Port_Settings->resize(448, 431);
        verticalLayout_4 = new QVBoxLayout(Ble_Port_Settings);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        ble_label = new QLabel(Ble_Port_Settings);
        ble_label->setObjectName(QString::fromUtf8("ble_label"));
        ble_label->setMinimumSize(QSize(0, 15));
        ble_label->setMaximumSize(QSize(16777215, 20));

        verticalLayout_4->addWidget(ble_label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        listWidget_dev = new QListWidget(Ble_Port_Settings);
        listWidget_dev->setObjectName(QString::fromUtf8("listWidget_dev"));
        listWidget_dev->setMinimumSize(QSize(0, 0));
        listWidget_dev->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout->addWidget(listWidget_dev);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        scan_button = new QPushButton(Ble_Port_Settings);
        scan_button->setObjectName(QString::fromUtf8("scan_button"));
        scan_button->setMinimumSize(QSize(0, 50));
        scan_button->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(scan_button);

        connect_button = new QPushButton(Ble_Port_Settings);
        connect_button->setObjectName(QString::fromUtf8("connect_button"));
        connect_button->setMinimumSize(QSize(0, 50));
        connect_button->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(connect_button);

        verticalSpacer = new QSpacerItem(17, 37, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        help_button = new QPushButton(Ble_Port_Settings);
        help_button->setObjectName(QString::fromUtf8("help_button"));
        help_button->setMinimumSize(QSize(0, 20));
        help_button->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout->addWidget(help_button);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_4->addLayout(horizontalLayout);

        service_box = new QWidget(Ble_Port_Settings);
        service_box->setObjectName(QString::fromUtf8("service_box"));
        service_box->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_2 = new QVBoxLayout(service_box);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        list_service = new QListWidget(service_box);
        list_service->setObjectName(QString::fromUtf8("list_service"));
        list_service->setMinimumSize(QSize(0, 0));
        list_service->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(list_service);

        service_button = new QPushButton(service_box);
        service_button->setObjectName(QString::fromUtf8("service_button"));
        service_button->setMinimumSize(QSize(0, 30));
        service_button->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(service_button);


        verticalLayout_4->addWidget(service_box);

        character_box = new QWidget(Ble_Port_Settings);
        character_box->setObjectName(QString::fromUtf8("character_box"));
        character_box->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout_3 = new QVBoxLayout(character_box);
        verticalLayout_3->setSpacing(5);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        list_character = new QListWidget(character_box);
        list_character->setObjectName(QString::fromUtf8("list_character"));
        list_character->setMinimumSize(QSize(0, 0));
        list_character->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_3->addWidget(list_character);

        binding_character = new QPushButton(character_box);
        binding_character->setObjectName(QString::fromUtf8("binding_character"));
        binding_character->setMinimumSize(QSize(0, 30));
        binding_character->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_3->addWidget(binding_character);


        verticalLayout_4->addWidget(character_box);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

#if QT_CONFIG(shortcut)
        ble_label->setBuddy(character_box);
#endif // QT_CONFIG(shortcut)

        retranslateUi(Ble_Port_Settings);

        QMetaObject::connectSlotsByName(Ble_Port_Settings);
    } // setupUi

    void retranslateUi(QWidget *Ble_Port_Settings)
    {
        Ble_Port_Settings->setWindowTitle(QCoreApplication::translate("Ble_Port_Settings", "Form", nullptr));
        ble_label->setText(QString());
        scan_button->setText(QCoreApplication::translate("Ble_Port_Settings", "\346\211\253\346\217\217", nullptr));
        connect_button->setText(QCoreApplication::translate("Ble_Port_Settings", "\350\277\236\346\216\245", nullptr));
        help_button->setText(QCoreApplication::translate("Ble_Port_Settings", "\357\274\237", nullptr));
        service_button->setText(QCoreApplication::translate("Ble_Port_Settings", "\351\200\211\346\213\251\346\234\215\345\212\241", nullptr));
        binding_character->setText(QCoreApplication::translate("Ble_Port_Settings", "\347\273\221\345\256\232\347\211\271\345\276\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ble_Port_Settings: public Ui_Ble_Port_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BLE_PORT_SETTINGS_H
