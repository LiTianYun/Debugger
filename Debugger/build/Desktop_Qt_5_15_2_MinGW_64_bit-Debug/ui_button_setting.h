/********************************************************************************
** Form generated from reading UI file 'button_setting.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUTTON_SETTING_H
#define UI_BUTTON_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Button_Setting
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QLabel *label_2;
    QPushButton *colorButton;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QRadioButton *radioButton;
    QTextEdit *dataEdit;
    QPushButton *DeleteButton;
    QPushButton *SaveButton;

    void setupUi(QDialog *Button_Setting)
    {
        if (Button_Setting->objectName().isEmpty())
            Button_Setting->setObjectName(QString::fromUtf8("Button_Setting"));
        Button_Setting->resize(184, 300);
        verticalLayout = new QVBoxLayout(Button_Setting);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Button_Setting);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        nameEdit = new QLineEdit(Button_Setting);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setEnabled(true);

        verticalLayout->addWidget(nameEdit);

        label_2 = new QLabel(Button_Setting);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        colorButton = new QPushButton(Button_Setting);
        colorButton->setObjectName(QString::fromUtf8("colorButton"));

        verticalLayout->addWidget(colorButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_3 = new QLabel(Button_Setting);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        radioButton = new QRadioButton(Button_Setting);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        horizontalLayout->addWidget(radioButton);


        verticalLayout->addLayout(horizontalLayout);

        dataEdit = new QTextEdit(Button_Setting);
        dataEdit->setObjectName(QString::fromUtf8("dataEdit"));

        verticalLayout->addWidget(dataEdit);

        DeleteButton = new QPushButton(Button_Setting);
        DeleteButton->setObjectName(QString::fromUtf8("DeleteButton"));

        verticalLayout->addWidget(DeleteButton);

        SaveButton = new QPushButton(Button_Setting);
        SaveButton->setObjectName(QString::fromUtf8("SaveButton"));

        verticalLayout->addWidget(SaveButton);


        retranslateUi(Button_Setting);

        QMetaObject::connectSlotsByName(Button_Setting);
    } // setupUi

    void retranslateUi(QDialog *Button_Setting)
    {
        label->setText(QCoreApplication::translate("Button_Setting", "\346\214\211\351\222\256\345\220\215\347\247\260:", nullptr));
        label_2->setText(QCoreApplication::translate("Button_Setting", "\351\242\234\350\211\262:", nullptr));
        label_3->setText(QCoreApplication::translate("Button_Setting", "\346\225\260\346\215\256:", nullptr));
        radioButton->setText(QCoreApplication::translate("Button_Setting", "Hex", nullptr));
        DeleteButton->setText(QCoreApplication::translate("Button_Setting", "\345\210\240\351\231\244\346\214\211\351\222\256", nullptr));
        SaveButton->setText(QCoreApplication::translate("Button_Setting", "\344\277\235\345\255\230", nullptr));
        (void)Button_Setting;
    } // retranslateUi

};

namespace Ui {
    class Button_Setting: public Ui_Button_Setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUTTON_SETTING_H
