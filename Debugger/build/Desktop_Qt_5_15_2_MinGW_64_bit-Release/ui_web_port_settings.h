/********************************************************************************
** Form generated from reading UI file 'web_port_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEB_PORT_SETTINGS_H
#define UI_WEB_PORT_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Web_Port_Settings
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_log;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QComboBox *model_comboBox;
    QGroupBox *Server_box;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QComboBox *ip_comboBox;
    QGroupBox *groupBox1;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *ip_Edit;
    QGroupBox *groupBox2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *port_Edit;
    QPushButton *Server_Create_Button;
    QPushButton *Connect_Server_Button;

    void setupUi(QWidget *Web_Port_Settings)
    {
        if (Web_Port_Settings->objectName().isEmpty())
            Web_Port_Settings->setObjectName(QString::fromUtf8("Web_Port_Settings"));
        Web_Port_Settings->resize(368, 306);
        verticalLayout = new QVBoxLayout(Web_Port_Settings);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_log = new QLabel(Web_Port_Settings);
        label_log->setObjectName(QString::fromUtf8("label_log"));
        label_log->setMinimumSize(QSize(0, 14));
        label_log->setMaximumSize(QSize(16777215, 15));

        verticalLayout->addWidget(label_log);

        groupBox = new QGroupBox(Web_Port_Settings);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        horizontalLayout_4 = new QHBoxLayout(groupBox);
        horizontalLayout_4->setSpacing(5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(70, 30));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_4);

        model_comboBox = new QComboBox(groupBox);
        model_comboBox->addItem(QString());
        model_comboBox->addItem(QString());
        model_comboBox->setObjectName(QString::fromUtf8("model_comboBox"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(model_comboBox->sizePolicy().hasHeightForWidth());
        model_comboBox->setSizePolicy(sizePolicy);
        model_comboBox->setMinimumSize(QSize(100, 30));

        horizontalLayout_4->addWidget(model_comboBox);


        verticalLayout->addWidget(groupBox);

        Server_box = new QGroupBox(Web_Port_Settings);
        Server_box->setObjectName(QString::fromUtf8("Server_box"));
        horizontalLayout_3 = new QHBoxLayout(Server_box);
        horizontalLayout_3->setSpacing(5);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(Server_box);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(70, 30));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);

        ip_comboBox = new QComboBox(Server_box);
        ip_comboBox->setObjectName(QString::fromUtf8("ip_comboBox"));
        sizePolicy.setHeightForWidth(ip_comboBox->sizePolicy().hasHeightForWidth());
        ip_comboBox->setSizePolicy(sizePolicy);
        ip_comboBox->setMinimumSize(QSize(100, 30));

        horizontalLayout_3->addWidget(ip_comboBox);


        verticalLayout->addWidget(Server_box);

        groupBox1 = new QGroupBox(Web_Port_Settings);
        groupBox1->setObjectName(QString::fromUtf8("groupBox1"));
        horizontalLayout = new QHBoxLayout(groupBox1);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(groupBox1);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(70, 30));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label);

        ip_Edit = new QLineEdit(groupBox1);
        ip_Edit->setObjectName(QString::fromUtf8("ip_Edit"));
        ip_Edit->setMinimumSize(QSize(100, 30));

        horizontalLayout->addWidget(ip_Edit);


        verticalLayout->addWidget(groupBox1);

        groupBox2 = new QGroupBox(Web_Port_Settings);
        groupBox2->setObjectName(QString::fromUtf8("groupBox2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox2);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(groupBox2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(70, 30));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_2);

        port_Edit = new QLineEdit(groupBox2);
        port_Edit->setObjectName(QString::fromUtf8("port_Edit"));
        port_Edit->setMinimumSize(QSize(100, 30));

        horizontalLayout_2->addWidget(port_Edit);


        verticalLayout->addWidget(groupBox2);

        Server_Create_Button = new QPushButton(Web_Port_Settings);
        Server_Create_Button->setObjectName(QString::fromUtf8("Server_Create_Button"));
        Server_Create_Button->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(Server_Create_Button);

        Connect_Server_Button = new QPushButton(Web_Port_Settings);
        Connect_Server_Button->setObjectName(QString::fromUtf8("Connect_Server_Button"));
        Connect_Server_Button->setMinimumSize(QSize(0, 30));

        verticalLayout->addWidget(Connect_Server_Button);


        retranslateUi(Web_Port_Settings);

        QMetaObject::connectSlotsByName(Web_Port_Settings);
    } // setupUi

    void retranslateUi(QWidget *Web_Port_Settings)
    {
        Web_Port_Settings->setWindowTitle(QCoreApplication::translate("Web_Port_Settings", "Form", nullptr));
        label_log->setText(QString());
        label_4->setText(QCoreApplication::translate("Web_Port_Settings", "\346\250\241\345\274\217\351\200\211\346\213\251: ", nullptr));
        model_comboBox->setItemText(0, QCoreApplication::translate("Web_Port_Settings", "TCP Server", nullptr));
        model_comboBox->setItemText(1, QCoreApplication::translate("Web_Port_Settings", "TCP Client", nullptr));

        label_3->setText(QCoreApplication::translate("Web_Port_Settings", "\346\234\254\345\234\260\345\234\260\345\235\200: ", nullptr));
        label->setText(QCoreApplication::translate("Web_Port_Settings", "\346\234\215\345\212\241\345\231\250\345\234\260\345\235\200:", nullptr));
        label_2->setText(QCoreApplication::translate("Web_Port_Settings", "\347\253\257\345\217\243:", nullptr));
        Server_Create_Button->setText(QCoreApplication::translate("Web_Port_Settings", "\347\233\221\345\220\254\347\253\257\345\217\243", nullptr));
        Connect_Server_Button->setText(QCoreApplication::translate("Web_Port_Settings", "\350\277\236\346\216\245\346\234\215\345\212\241\345\231\250", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Web_Port_Settings: public Ui_Web_Port_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEB_PORT_SETTINGS_H
