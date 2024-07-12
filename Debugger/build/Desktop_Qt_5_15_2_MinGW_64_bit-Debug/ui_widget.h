/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *SerialSettings;
    QPushButton *BleSettings;
    QPushButton *WebSettings;
    QSpacerItem *horizontalSpacer_10;
    QLabel *Serial_State;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *Serial_Run;
    QTabWidget *Action_Widget;
    QWidget *Serial_Setting;
    QGridLayout *gridLayout;
    QHBoxLayout *TX_Layout;
    QTextEdit *TX_textEdit;
    QPushButton *Send_Button;
    QHBoxLayout *horizontalLayout_5;
    QTextEdit *textEdit_Search;
    QPushButton *Search_Button;
    QPushButton *Search_Button_Clean;
    QPushButton *Search_Button_Refresh;
    QHBoxLayout *horizontalLayout_6;
    QTextEdit *Read_Display_textEdit;
    QTextEdit *Search_Display;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_11;
    QSpacerItem *horizontalSpacer;
    QPushButton *Serial_Send_Clean;
    QPushButton *Serial_Send_Display;
    QPushButton *Serial_Send_Text;
    QLineEdit *Send_Timed_Edit;
    QLabel *label_12;
    QPushButton *Send_Timed;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout;
    QLabel *label_6;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *Serial_Read_ON;
    QPushButton *Serial_Read_Clean;
    QPushButton *Serial_Read_Time;
    QPushButton *Serial_Read_Line;
    QPushButton *Serial_Read_Text;
    QPushButton *Serial_Read_Save;
    QPushButton *Open_Save;
    QGroupBox *groupBox;
    QHBoxLayout *Count_Layout;
    QLabel *label_7;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_8;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *Reset_Count_Button;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(693, 463);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        SerialSettings = new QPushButton(Widget);
        SerialSettings->setObjectName(QString::fromUtf8("SerialSettings"));
        sizePolicy.setHeightForWidth(SerialSettings->sizePolicy().hasHeightForWidth());
        SerialSettings->setSizePolicy(sizePolicy);
        SerialSettings->setMinimumSize(QSize(50, 30));
        SerialSettings->setMaximumSize(QSize(100, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        SerialSettings->setFont(font);

        horizontalLayout_4->addWidget(SerialSettings);

        BleSettings = new QPushButton(Widget);
        BleSettings->setObjectName(QString::fromUtf8("BleSettings"));
        BleSettings->setEnabled(false);
        sizePolicy.setHeightForWidth(BleSettings->sizePolicy().hasHeightForWidth());
        BleSettings->setSizePolicy(sizePolicy);
        BleSettings->setMinimumSize(QSize(50, 30));
        BleSettings->setMaximumSize(QSize(100, 30));
        BleSettings->setFont(font);

        horizontalLayout_4->addWidget(BleSettings);

        WebSettings = new QPushButton(Widget);
        WebSettings->setObjectName(QString::fromUtf8("WebSettings"));
        WebSettings->setEnabled(false);
        sizePolicy.setHeightForWidth(WebSettings->sizePolicy().hasHeightForWidth());
        WebSettings->setSizePolicy(sizePolicy);
        WebSettings->setMinimumSize(QSize(50, 30));
        WebSettings->setMaximumSize(QSize(100, 30));
        WebSettings->setFont(font);

        horizontalLayout_4->addWidget(WebSettings);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);

        Serial_State = new QLabel(Widget);
        Serial_State->setObjectName(QString::fromUtf8("Serial_State"));
        sizePolicy.setHeightForWidth(Serial_State->sizePolicy().hasHeightForWidth());
        Serial_State->setSizePolicy(sizePolicy);
        Serial_State->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(10);
        font1.setBold(false);
        Serial_State->setFont(font1);

        horizontalLayout_4->addWidget(Serial_State);

        horizontalSpacer_11 = new QSpacerItem(112, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);

        Serial_Run = new QPushButton(Widget);
        Serial_Run->setObjectName(QString::fromUtf8("Serial_Run"));
        Serial_Run->setEnabled(false);
        sizePolicy.setHeightForWidth(Serial_Run->sizePolicy().hasHeightForWidth());
        Serial_Run->setSizePolicy(sizePolicy);
        Serial_Run->setMinimumSize(QSize(100, 30));
        Serial_Run->setMaximumSize(QSize(100, 30));
        Serial_Run->setFont(font);

        horizontalLayout_4->addWidget(Serial_Run);


        gridLayout_2->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        Action_Widget = new QTabWidget(Widget);
        Action_Widget->setObjectName(QString::fromUtf8("Action_Widget"));
        Action_Widget->setEnabled(true);
        sizePolicy.setHeightForWidth(Action_Widget->sizePolicy().hasHeightForWidth());
        Action_Widget->setSizePolicy(sizePolicy);
        Action_Widget->setMinimumSize(QSize(0, 0));
        Serial_Setting = new QWidget();
        Serial_Setting->setObjectName(QString::fromUtf8("Serial_Setting"));
        gridLayout = new QGridLayout(Serial_Setting);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        TX_Layout = new QHBoxLayout();
        TX_Layout->setObjectName(QString::fromUtf8("TX_Layout"));
        TX_textEdit = new QTextEdit(Serial_Setting);
        TX_textEdit->setObjectName(QString::fromUtf8("TX_textEdit"));
        sizePolicy.setHeightForWidth(TX_textEdit->sizePolicy().hasHeightForWidth());
        TX_textEdit->setSizePolicy(sizePolicy);
        TX_textEdit->setMinimumSize(QSize(0, 60));
        TX_textEdit->setMaximumSize(QSize(16777215, 60));
        TX_textEdit->setFont(font);

        TX_Layout->addWidget(TX_textEdit, 0, Qt::AlignVCenter);

        Send_Button = new QPushButton(Serial_Setting);
        Send_Button->setObjectName(QString::fromUtf8("Send_Button"));
        Send_Button->setEnabled(false);
        sizePolicy.setHeightForWidth(Send_Button->sizePolicy().hasHeightForWidth());
        Send_Button->setSizePolicy(sizePolicy);
        Send_Button->setMinimumSize(QSize(100, 60));
        Send_Button->setMaximumSize(QSize(100, 60));
        Send_Button->setFont(font);

        TX_Layout->addWidget(Send_Button, 0, Qt::AlignVCenter);


        gridLayout->addLayout(TX_Layout, 4, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(5);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        textEdit_Search = new QTextEdit(Serial_Setting);
        textEdit_Search->setObjectName(QString::fromUtf8("textEdit_Search"));
        textEdit_Search->setMinimumSize(QSize(0, 30));
        textEdit_Search->setMaximumSize(QSize(16777215, 30));
        textEdit_Search->setFont(font);

        horizontalLayout_5->addWidget(textEdit_Search, 0, Qt::AlignVCenter);

        Search_Button = new QPushButton(Serial_Setting);
        Search_Button->setObjectName(QString::fromUtf8("Search_Button"));
        sizePolicy.setHeightForWidth(Search_Button->sizePolicy().hasHeightForWidth());
        Search_Button->setSizePolicy(sizePolicy);
        Search_Button->setMinimumSize(QSize(50, 30));
        Search_Button->setMaximumSize(QSize(50, 30));
        Search_Button->setFont(font);

        horizontalLayout_5->addWidget(Search_Button);

        Search_Button_Clean = new QPushButton(Serial_Setting);
        Search_Button_Clean->setObjectName(QString::fromUtf8("Search_Button_Clean"));
        sizePolicy.setHeightForWidth(Search_Button_Clean->sizePolicy().hasHeightForWidth());
        Search_Button_Clean->setSizePolicy(sizePolicy);
        Search_Button_Clean->setMinimumSize(QSize(60, 30));
        Search_Button_Clean->setMaximumSize(QSize(100, 30));
        Search_Button_Clean->setFont(font);

        horizontalLayout_5->addWidget(Search_Button_Clean);

        Search_Button_Refresh = new QPushButton(Serial_Setting);
        Search_Button_Refresh->setObjectName(QString::fromUtf8("Search_Button_Refresh"));
        sizePolicy.setHeightForWidth(Search_Button_Refresh->sizePolicy().hasHeightForWidth());
        Search_Button_Refresh->setSizePolicy(sizePolicy);
        Search_Button_Refresh->setMinimumSize(QSize(60, 30));
        Search_Button_Refresh->setMaximumSize(QSize(100, 30));
        Search_Button_Refresh->setFont(font);

        horizontalLayout_5->addWidget(Search_Button_Refresh);


        gridLayout->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        Read_Display_textEdit = new QTextEdit(Serial_Setting);
        Read_Display_textEdit->setObjectName(QString::fromUtf8("Read_Display_textEdit"));
        Read_Display_textEdit->setEnabled(true);
        sizePolicy.setHeightForWidth(Read_Display_textEdit->sizePolicy().hasHeightForWidth());
        Read_Display_textEdit->setSizePolicy(sizePolicy);
        Read_Display_textEdit->setFont(font);
        Read_Display_textEdit->setReadOnly(true);

        horizontalLayout_6->addWidget(Read_Display_textEdit);

        Search_Display = new QTextEdit(Serial_Setting);
        Search_Display->setObjectName(QString::fromUtf8("Search_Display"));
        Search_Display->setEnabled(true);
        sizePolicy.setHeightForWidth(Search_Display->sizePolicy().hasHeightForWidth());
        Search_Display->setSizePolicy(sizePolicy);
        Search_Display->setFont(font);
        Search_Display->setReadOnly(true);

        horizontalLayout_6->addWidget(Search_Display);


        gridLayout->addLayout(horizontalLayout_6, 2, 0, 1, 1);

        groupBox_3 = new QGroupBox(Serial_Setting);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMaximumSize(QSize(16777215, 45));
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, 2, 5, 2);
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy);
        label_11->setMinimumSize(QSize(100, 0));
        label_11->setMaximumSize(QSize(100, 30));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setPointSize(9);
        font2.setBold(false);
        label_11->setFont(font2);

        horizontalLayout_2->addWidget(label_11);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        Serial_Send_Clean = new QPushButton(groupBox_3);
        Serial_Send_Clean->setObjectName(QString::fromUtf8("Serial_Send_Clean"));
        sizePolicy.setHeightForWidth(Serial_Send_Clean->sizePolicy().hasHeightForWidth());
        Serial_Send_Clean->setSizePolicy(sizePolicy);
        Serial_Send_Clean->setMinimumSize(QSize(70, 30));
        Serial_Send_Clean->setMaximumSize(QSize(100, 30));
        Serial_Send_Clean->setFont(font);

        horizontalLayout_2->addWidget(Serial_Send_Clean);

        Serial_Send_Display = new QPushButton(groupBox_3);
        Serial_Send_Display->setObjectName(QString::fromUtf8("Serial_Send_Display"));
        sizePolicy.setHeightForWidth(Serial_Send_Display->sizePolicy().hasHeightForWidth());
        Serial_Send_Display->setSizePolicy(sizePolicy);
        Serial_Send_Display->setMinimumSize(QSize(70, 30));
        Serial_Send_Display->setMaximumSize(QSize(100, 30));
        Serial_Send_Display->setFont(font);

        horizontalLayout_2->addWidget(Serial_Send_Display);

        Serial_Send_Text = new QPushButton(groupBox_3);
        Serial_Send_Text->setObjectName(QString::fromUtf8("Serial_Send_Text"));
        sizePolicy.setHeightForWidth(Serial_Send_Text->sizePolicy().hasHeightForWidth());
        Serial_Send_Text->setSizePolicy(sizePolicy);
        Serial_Send_Text->setMinimumSize(QSize(60, 30));
        Serial_Send_Text->setMaximumSize(QSize(100, 30));
        Serial_Send_Text->setFont(font);

        horizontalLayout_2->addWidget(Serial_Send_Text);

        Send_Timed_Edit = new QLineEdit(groupBox_3);
        Send_Timed_Edit->setObjectName(QString::fromUtf8("Send_Timed_Edit"));
        Send_Timed_Edit->setMaximumSize(QSize(70, 30));
        Send_Timed_Edit->setFont(font);

        horizontalLayout_2->addWidget(Send_Timed_Edit);

        label_12 = new QLabel(groupBox_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        label_12->setMaximumSize(QSize(20, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font3.setPointSize(12);
        font3.setBold(false);
        label_12->setFont(font3);

        horizontalLayout_2->addWidget(label_12);

        Send_Timed = new QPushButton(groupBox_3);
        Send_Timed->setObjectName(QString::fromUtf8("Send_Timed"));
        sizePolicy.setHeightForWidth(Send_Timed->sizePolicy().hasHeightForWidth());
        Send_Timed->setSizePolicy(sizePolicy);
        Send_Timed->setMinimumSize(QSize(60, 30));
        Send_Timed->setMaximumSize(QSize(100, 30));
        Send_Timed->setFont(font);

        horizontalLayout_2->addWidget(Send_Timed);


        gridLayout->addWidget(groupBox_3, 3, 0, 1, 1);

        groupBox_2 = new QGroupBox(Serial_Setting);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(16777215, 45));
        horizontalLayout = new QHBoxLayout(groupBox_2);
        horizontalLayout->setSpacing(5);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(5, 2, 5, 2);
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy);
        label_6->setMinimumSize(QSize(100, 0));
        label_6->setMaximumSize(QSize(100, 20));
        label_6->setFont(font2);

        horizontalLayout->addWidget(label_6);

        horizontalSpacer_14 = new QSpacerItem(21, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_14);

        Serial_Read_ON = new QPushButton(groupBox_2);
        Serial_Read_ON->setObjectName(QString::fromUtf8("Serial_Read_ON"));
        Serial_Read_ON->setEnabled(true);
        sizePolicy.setHeightForWidth(Serial_Read_ON->sizePolicy().hasHeightForWidth());
        Serial_Read_ON->setSizePolicy(sizePolicy);
        Serial_Read_ON->setMinimumSize(QSize(60, 30));
        Serial_Read_ON->setMaximumSize(QSize(100, 30));
        Serial_Read_ON->setFont(font);

        horizontalLayout->addWidget(Serial_Read_ON);

        Serial_Read_Clean = new QPushButton(groupBox_2);
        Serial_Read_Clean->setObjectName(QString::fromUtf8("Serial_Read_Clean"));
        sizePolicy.setHeightForWidth(Serial_Read_Clean->sizePolicy().hasHeightForWidth());
        Serial_Read_Clean->setSizePolicy(sizePolicy);
        Serial_Read_Clean->setMinimumSize(QSize(70, 30));
        Serial_Read_Clean->setMaximumSize(QSize(100, 30));
        Serial_Read_Clean->setFont(font);

        horizontalLayout->addWidget(Serial_Read_Clean);

        Serial_Read_Time = new QPushButton(groupBox_2);
        Serial_Read_Time->setObjectName(QString::fromUtf8("Serial_Read_Time"));
        sizePolicy.setHeightForWidth(Serial_Read_Time->sizePolicy().hasHeightForWidth());
        Serial_Read_Time->setSizePolicy(sizePolicy);
        Serial_Read_Time->setMinimumSize(QSize(70, 30));
        Serial_Read_Time->setMaximumSize(QSize(100, 30));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font4.setBold(false);
        Serial_Read_Time->setFont(font4);

        horizontalLayout->addWidget(Serial_Read_Time);

        Serial_Read_Line = new QPushButton(groupBox_2);
        Serial_Read_Line->setObjectName(QString::fromUtf8("Serial_Read_Line"));
        sizePolicy.setHeightForWidth(Serial_Read_Line->sizePolicy().hasHeightForWidth());
        Serial_Read_Line->setSizePolicy(sizePolicy);
        Serial_Read_Line->setMinimumSize(QSize(60, 30));
        Serial_Read_Line->setMaximumSize(QSize(100, 30));
        Serial_Read_Line->setFont(font4);

        horizontalLayout->addWidget(Serial_Read_Line);

        Serial_Read_Text = new QPushButton(groupBox_2);
        Serial_Read_Text->setObjectName(QString::fromUtf8("Serial_Read_Text"));
        sizePolicy.setHeightForWidth(Serial_Read_Text->sizePolicy().hasHeightForWidth());
        Serial_Read_Text->setSizePolicy(sizePolicy);
        Serial_Read_Text->setMinimumSize(QSize(70, 30));
        Serial_Read_Text->setMaximumSize(QSize(100, 30));
        Serial_Read_Text->setFont(font);

        horizontalLayout->addWidget(Serial_Read_Text);

        Serial_Read_Save = new QPushButton(groupBox_2);
        Serial_Read_Save->setObjectName(QString::fromUtf8("Serial_Read_Save"));
        sizePolicy.setHeightForWidth(Serial_Read_Save->sizePolicy().hasHeightForWidth());
        Serial_Read_Save->setSizePolicy(sizePolicy);
        Serial_Read_Save->setMinimumSize(QSize(60, 30));
        Serial_Read_Save->setMaximumSize(QSize(100, 30));
        Serial_Read_Save->setFont(font);

        horizontalLayout->addWidget(Serial_Read_Save);

        Open_Save = new QPushButton(groupBox_2);
        Open_Save->setObjectName(QString::fromUtf8("Open_Save"));
        sizePolicy.setHeightForWidth(Open_Save->sizePolicy().hasHeightForWidth());
        Open_Save->setSizePolicy(sizePolicy);
        Open_Save->setMinimumSize(QSize(60, 30));
        Open_Save->setMaximumSize(QSize(100, 30));
        Open_Save->setFont(font);

        horizontalLayout->addWidget(Open_Save);


        gridLayout->addWidget(groupBox_2, 0, 0, 1, 1);

        Action_Widget->addTab(Serial_Setting, QString());

        gridLayout_2->addWidget(Action_Widget, 1, 0, 1, 1);

        groupBox = new QGroupBox(Widget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 40));
        Count_Layout = new QHBoxLayout(groupBox);
        Count_Layout->setSpacing(0);
        Count_Layout->setObjectName(QString::fromUtf8("Count_Layout"));
        Count_Layout->setContentsMargins(0, 0, 0, 0);
        label_7 = new QLabel(groupBox);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(0, 25));
        label_7->setMaximumSize(QSize(16777215, 25));
        QFont font5;
        font5.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font5.setPointSize(8);
        label_7->setFont(font5);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Count_Layout->addWidget(label_7);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);
        label_9->setMinimumSize(QSize(0, 25));
        label_9->setMaximumSize(QSize(16777215, 25));
        label_9->setFont(font5);

        Count_Layout->addWidget(label_9);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Count_Layout->addItem(horizontalSpacer_8);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);
        label_8->setMinimumSize(QSize(0, 25));
        label_8->setMaximumSize(QSize(16777215, 25));
        label_8->setFont(font5);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Count_Layout->addWidget(label_8);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy);
        label_10->setMinimumSize(QSize(0, 25));
        label_10->setMaximumSize(QSize(16777215, 25));
        label_10->setFont(font5);

        Count_Layout->addWidget(label_10);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Count_Layout->addItem(horizontalSpacer_9);

        Reset_Count_Button = new QPushButton(groupBox);
        Reset_Count_Button->setObjectName(QString::fromUtf8("Reset_Count_Button"));
        sizePolicy.setHeightForWidth(Reset_Count_Button->sizePolicy().hasHeightForWidth());
        Reset_Count_Button->setSizePolicy(sizePolicy);
        Reset_Count_Button->setMinimumSize(QSize(60, 25));
        Reset_Count_Button->setMaximumSize(QSize(100, 25));
        Reset_Count_Button->setFont(font5);

        Count_Layout->addWidget(Reset_Count_Button, 0, Qt::AlignRight|Qt::AlignVCenter);


        gridLayout_2->addWidget(groupBox, 2, 0, 1, 1);

        QWidget::setTabOrder(Send_Button, Serial_Read_Clean);
        QWidget::setTabOrder(Serial_Read_Clean, Serial_Read_Save);
        QWidget::setTabOrder(Serial_Read_Save, Reset_Count_Button);
        QWidget::setTabOrder(Reset_Count_Button, Read_Display_textEdit);
        QWidget::setTabOrder(Read_Display_textEdit, Serial_Send_Clean);
        QWidget::setTabOrder(Serial_Send_Clean, TX_textEdit);

        retranslateUi(Widget);

        Action_Widget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        SerialSettings->setText(QCoreApplication::translate("Widget", "\344\270\262\345\217\243", nullptr));
        BleSettings->setText(QCoreApplication::translate("Widget", "BLE", nullptr));
        WebSettings->setText(QCoreApplication::translate("Widget", "WEB", nullptr));
        Serial_State->setText(QCoreApplication::translate("Widget", "\346\234\252\350\277\236\346\216\245", nullptr));
        Serial_Run->setText(QCoreApplication::translate("Widget", "\346\216\245\346\224\266", nullptr));
        Send_Button->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        Search_Button->setText(QCoreApplication::translate("Widget", "\346\220\234\347\264\242", nullptr));
        Search_Button_Clean->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272\346\220\234\347\264\242\345\214\272", nullptr));
        Search_Button_Refresh->setText(QCoreApplication::translate("Widget", "\345\256\236\346\227\266\345\210\267\346\226\260", nullptr));
        label_11->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\345\214\272\350\256\276\347\275\256", nullptr));
        Serial_Send_Clean->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272\345\217\221\351\200\201\345\214\272", nullptr));
        Serial_Send_Display->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\346\230\276\347\244\272", nullptr));
        Serial_Send_Text->setText(QCoreApplication::translate("Widget", "Hex\345\217\221\351\200\201", nullptr));
        label_12->setText(QCoreApplication::translate("Widget", "ms", nullptr));
        Send_Timed->setText(QCoreApplication::translate("Widget", "\345\256\232\346\227\266\345\217\221\351\200\201", nullptr));
        label_6->setText(QCoreApplication::translate("Widget", "\346\216\245\346\224\266\345\214\272\350\256\276\347\275\256", nullptr));
        Serial_Read_ON->setText(QCoreApplication::translate("Widget", "\346\216\245\346\224\266\346\230\276\347\244\272", nullptr));
        Serial_Read_Clean->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272\346\216\245\346\224\266\345\214\272", nullptr));
        Serial_Read_Time->setText(QCoreApplication::translate("Widget", "\346\227\266\351\227\264\346\210\263", nullptr));
        Serial_Read_Line->setText(QCoreApplication::translate("Widget", "\351\253\230\351\200\237\346\250\241\345\274\217", nullptr));
        Serial_Read_Text->setText(QCoreApplication::translate("Widget", "Hex\346\216\245\346\224\266", nullptr));
        Serial_Read_Save->setText(QCoreApplication::translate("Widget", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
        Open_Save->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\347\233\256\345\275\225", nullptr));
        Action_Widget->setTabText(Action_Widget->indexOf(Serial_Setting), QCoreApplication::translate("Widget", "\346\225\260\346\215\256\346\224\266\345\217\221", nullptr));
        label_7->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\345\255\227\350\212\202\357\274\232", nullptr));
        label_9->setText(QCoreApplication::translate("Widget", "0", nullptr));
        label_8->setText(QCoreApplication::translate("Widget", "\346\216\245\346\224\266\345\255\227\350\212\202\357\274\232", nullptr));
        label_10->setText(QCoreApplication::translate("Widget", "0", nullptr));
        Reset_Count_Button->setText(QCoreApplication::translate("Widget", "\345\244\215\344\275\215\350\256\241\346\225\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
