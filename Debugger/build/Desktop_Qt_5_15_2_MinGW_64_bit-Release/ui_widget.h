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
    QTabWidget *Action_Widget;
    QWidget *Serial_Setting;
    QGridLayout *gridLayout;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *Serial_Send_Display;
    QPushButton *Serial_Send_Clean;
    QSpacerItem *horizontalSpacer;
    QPushButton *Serial_Send_Text;
    QLineEdit *Send_Timed_Edit;
    QLabel *label_12;
    QPushButton *Send_Timed;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *Serial_Read_ON;
    QPushButton *Serial_Read_Clean;
    QSpacerItem *horizontalSpacer_14;
    QPushButton *Serial_Read_Text;
    QPushButton *Serial_Read_Time;
    QPushButton *Serial_Read_Line;
    QPushButton *Serial_Read_Save;
    QPushButton *Open_Save;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_6;
    QTextEdit *Read_Display_textEdit;
    QTextEdit *Search_Display;
    QWidget *widget1;
    QHBoxLayout *TX_Layout;
    QTextEdit *TX_textEdit;
    QPushButton *Send_Button;
    QWidget *widget2;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    QTextEdit *textEdit_Search;
    QPushButton *Search_Button;
    QPushButton *Search_Button_Clean;
    QPushButton *Search_Button_Refresh;
    QWidget *widget3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *SerialSettings;
    QPushButton *BleSettings;
    QPushButton *WebSettings;
    QSpacerItem *horizontalSpacer_10;
    QLabel *Serial_State;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *Serial_Run;
    QWidget *widget4;
    QHBoxLayout *Count_Layout;
    QSpacerItem *horizontalSpacer_8;
    QLabel *label_7;
    QLabel *label_9;
    QLabel *label_8;
    QLabel *label_10;
    QPushButton *Reset_Count_Button;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(722, 463);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        Widget->setFont(font);
        gridLayout_2 = new QGridLayout(Widget);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(5);
        gridLayout_2->setVerticalSpacing(2);
        gridLayout_2->setContentsMargins(5, 5, 5, 5);
        Action_Widget = new QTabWidget(Widget);
        Action_Widget->setObjectName(QString::fromUtf8("Action_Widget"));
        Action_Widget->setEnabled(true);
        sizePolicy.setHeightForWidth(Action_Widget->sizePolicy().hasHeightForWidth());
        Action_Widget->setSizePolicy(sizePolicy);
        Action_Widget->setMinimumSize(QSize(0, 0));
        Serial_Setting = new QWidget();
        Serial_Setting->setObjectName(QString::fromUtf8("Serial_Setting"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Serial_Setting->sizePolicy().hasHeightForWidth());
        Serial_Setting->setSizePolicy(sizePolicy1);
        gridLayout = new QGridLayout(Serial_Setting);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        widget_3 = new QWidget(Serial_Setting);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        sizePolicy1.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy1);
        widget_3->setMaximumSize(QSize(16777215, 25));
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Serial_Send_Display = new QPushButton(widget_3);
        Serial_Send_Display->setObjectName(QString::fromUtf8("Serial_Send_Display"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Serial_Send_Display->sizePolicy().hasHeightForWidth());
        Serial_Send_Display->setSizePolicy(sizePolicy2);
        Serial_Send_Display->setMinimumSize(QSize(80, 20));
        Serial_Send_Display->setMaximumSize(QSize(80, 25));
        Serial_Send_Display->setFont(font);

        horizontalLayout_2->addWidget(Serial_Send_Display);

        Serial_Send_Clean = new QPushButton(widget_3);
        Serial_Send_Clean->setObjectName(QString::fromUtf8("Serial_Send_Clean"));
        sizePolicy2.setHeightForWidth(Serial_Send_Clean->sizePolicy().hasHeightForWidth());
        Serial_Send_Clean->setSizePolicy(sizePolicy2);
        Serial_Send_Clean->setMinimumSize(QSize(80, 20));
        Serial_Send_Clean->setMaximumSize(QSize(80, 25));
        Serial_Send_Clean->setFont(font);

        horizontalLayout_2->addWidget(Serial_Send_Clean);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        Serial_Send_Text = new QPushButton(widget_3);
        Serial_Send_Text->setObjectName(QString::fromUtf8("Serial_Send_Text"));
        sizePolicy2.setHeightForWidth(Serial_Send_Text->sizePolicy().hasHeightForWidth());
        Serial_Send_Text->setSizePolicy(sizePolicy2);
        Serial_Send_Text->setMinimumSize(QSize(80, 20));
        Serial_Send_Text->setMaximumSize(QSize(80, 25));
        Serial_Send_Text->setFont(font);

        horizontalLayout_2->addWidget(Serial_Send_Text);

        Send_Timed_Edit = new QLineEdit(widget_3);
        Send_Timed_Edit->setObjectName(QString::fromUtf8("Send_Timed_Edit"));
        QSizePolicy sizePolicy3(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Send_Timed_Edit->sizePolicy().hasHeightForWidth());
        Send_Timed_Edit->setSizePolicy(sizePolicy3);
        Send_Timed_Edit->setMinimumSize(QSize(80, 20));
        Send_Timed_Edit->setMaximumSize(QSize(80, 25));
        Send_Timed_Edit->setFont(font);

        horizontalLayout_2->addWidget(Send_Timed_Edit);

        label_12 = new QLabel(widget_3);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy);
        label_12->setMinimumSize(QSize(0, 20));
        label_12->setMaximumSize(QSize(20, 25));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(12);
        font1.setBold(false);
        label_12->setFont(font1);

        horizontalLayout_2->addWidget(label_12);

        Send_Timed = new QPushButton(widget_3);
        Send_Timed->setObjectName(QString::fromUtf8("Send_Timed"));
        sizePolicy2.setHeightForWidth(Send_Timed->sizePolicy().hasHeightForWidth());
        Send_Timed->setSizePolicy(sizePolicy2);
        Send_Timed->setMinimumSize(QSize(80, 20));
        Send_Timed->setMaximumSize(QSize(80, 25));
        Send_Timed->setFont(font);

        horizontalLayout_2->addWidget(Send_Timed);


        gridLayout->addWidget(widget_3, 3, 0, 1, 1);

        widget_2 = new QWidget(Serial_Setting);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        widget_2->setMaximumSize(QSize(16777215, 25));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Serial_Read_ON = new QPushButton(widget_2);
        Serial_Read_ON->setObjectName(QString::fromUtf8("Serial_Read_ON"));
        Serial_Read_ON->setEnabled(true);
        sizePolicy2.setHeightForWidth(Serial_Read_ON->sizePolicy().hasHeightForWidth());
        Serial_Read_ON->setSizePolicy(sizePolicy2);
        Serial_Read_ON->setMinimumSize(QSize(80, 20));
        Serial_Read_ON->setMaximumSize(QSize(80, 25));
        Serial_Read_ON->setFont(font);

        horizontalLayout->addWidget(Serial_Read_ON);

        Serial_Read_Clean = new QPushButton(widget_2);
        Serial_Read_Clean->setObjectName(QString::fromUtf8("Serial_Read_Clean"));
        sizePolicy2.setHeightForWidth(Serial_Read_Clean->sizePolicy().hasHeightForWidth());
        Serial_Read_Clean->setSizePolicy(sizePolicy2);
        Serial_Read_Clean->setMinimumSize(QSize(80, 20));
        Serial_Read_Clean->setMaximumSize(QSize(80, 25));
        Serial_Read_Clean->setFont(font);

        horizontalLayout->addWidget(Serial_Read_Clean);

        horizontalSpacer_14 = new QSpacerItem(21, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_14);

        Serial_Read_Text = new QPushButton(widget_2);
        Serial_Read_Text->setObjectName(QString::fromUtf8("Serial_Read_Text"));
        sizePolicy2.setHeightForWidth(Serial_Read_Text->sizePolicy().hasHeightForWidth());
        Serial_Read_Text->setSizePolicy(sizePolicy2);
        Serial_Read_Text->setMinimumSize(QSize(80, 20));
        Serial_Read_Text->setMaximumSize(QSize(80, 25));
        Serial_Read_Text->setFont(font);

        horizontalLayout->addWidget(Serial_Read_Text);

        Serial_Read_Time = new QPushButton(widget_2);
        Serial_Read_Time->setObjectName(QString::fromUtf8("Serial_Read_Time"));
        sizePolicy2.setHeightForWidth(Serial_Read_Time->sizePolicy().hasHeightForWidth());
        Serial_Read_Time->setSizePolicy(sizePolicy2);
        Serial_Read_Time->setMinimumSize(QSize(80, 20));
        Serial_Read_Time->setMaximumSize(QSize(80, 25));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font2.setBold(false);
        Serial_Read_Time->setFont(font2);

        horizontalLayout->addWidget(Serial_Read_Time);

        Serial_Read_Line = new QPushButton(widget_2);
        Serial_Read_Line->setObjectName(QString::fromUtf8("Serial_Read_Line"));
        sizePolicy2.setHeightForWidth(Serial_Read_Line->sizePolicy().hasHeightForWidth());
        Serial_Read_Line->setSizePolicy(sizePolicy2);
        Serial_Read_Line->setMinimumSize(QSize(80, 20));
        Serial_Read_Line->setMaximumSize(QSize(80, 25));
        Serial_Read_Line->setFont(font2);

        horizontalLayout->addWidget(Serial_Read_Line);

        Serial_Read_Save = new QPushButton(widget_2);
        Serial_Read_Save->setObjectName(QString::fromUtf8("Serial_Read_Save"));
        sizePolicy2.setHeightForWidth(Serial_Read_Save->sizePolicy().hasHeightForWidth());
        Serial_Read_Save->setSizePolicy(sizePolicy2);
        Serial_Read_Save->setMinimumSize(QSize(80, 20));
        Serial_Read_Save->setMaximumSize(QSize(80, 25));
        Serial_Read_Save->setFont(font);

        horizontalLayout->addWidget(Serial_Read_Save);

        Open_Save = new QPushButton(widget_2);
        Open_Save->setObjectName(QString::fromUtf8("Open_Save"));
        sizePolicy2.setHeightForWidth(Open_Save->sizePolicy().hasHeightForWidth());
        Open_Save->setSizePolicy(sizePolicy2);
        Open_Save->setMinimumSize(QSize(80, 20));
        Open_Save->setMaximumSize(QSize(80, 25));
        Open_Save->setFont(font);

        horizontalLayout->addWidget(Open_Save);


        gridLayout->addWidget(widget_2, 0, 0, 1, 1);

        widget = new QWidget(Serial_Setting);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy4);
        widget->setMaximumSize(QSize(16777215, 16777215));
        horizontalLayout_6 = new QHBoxLayout(widget);
        horizontalLayout_6->setSpacing(2);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        Read_Display_textEdit = new QTextEdit(widget);
        Read_Display_textEdit->setObjectName(QString::fromUtf8("Read_Display_textEdit"));
        Read_Display_textEdit->setEnabled(true);
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(Read_Display_textEdit->sizePolicy().hasHeightForWidth());
        Read_Display_textEdit->setSizePolicy(sizePolicy5);
        Read_Display_textEdit->setFont(font);
        Read_Display_textEdit->setReadOnly(true);

        horizontalLayout_6->addWidget(Read_Display_textEdit);

        Search_Display = new QTextEdit(widget);
        Search_Display->setObjectName(QString::fromUtf8("Search_Display"));
        Search_Display->setEnabled(true);
        sizePolicy5.setHeightForWidth(Search_Display->sizePolicy().hasHeightForWidth());
        Search_Display->setSizePolicy(sizePolicy5);
        Search_Display->setFont(font);
        Search_Display->setReadOnly(true);

        horizontalLayout_6->addWidget(Search_Display);


        gridLayout->addWidget(widget, 2, 0, 1, 1);

        widget1 = new QWidget(Serial_Setting);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        sizePolicy1.setHeightForWidth(widget1->sizePolicy().hasHeightForWidth());
        widget1->setSizePolicy(sizePolicy1);
        widget1->setMaximumSize(QSize(16777215, 60));
        TX_Layout = new QHBoxLayout(widget1);
        TX_Layout->setSpacing(2);
        TX_Layout->setObjectName(QString::fromUtf8("TX_Layout"));
        TX_Layout->setContentsMargins(0, 0, 0, 0);
        TX_textEdit = new QTextEdit(widget1);
        TX_textEdit->setObjectName(QString::fromUtf8("TX_textEdit"));
        sizePolicy.setHeightForWidth(TX_textEdit->sizePolicy().hasHeightForWidth());
        TX_textEdit->setSizePolicy(sizePolicy);
        TX_textEdit->setMinimumSize(QSize(0, 60));
        TX_textEdit->setMaximumSize(QSize(16777215, 60));
        TX_textEdit->setFont(font);

        TX_Layout->addWidget(TX_textEdit, 0, Qt::AlignVCenter);

        Send_Button = new QPushButton(widget1);
        Send_Button->setObjectName(QString::fromUtf8("Send_Button"));
        Send_Button->setEnabled(false);
        sizePolicy2.setHeightForWidth(Send_Button->sizePolicy().hasHeightForWidth());
        Send_Button->setSizePolicy(sizePolicy2);
        Send_Button->setMinimumSize(QSize(80, 60));
        Send_Button->setMaximumSize(QSize(80, 60));
        Send_Button->setFont(font);

        TX_Layout->addWidget(Send_Button, 0, Qt::AlignVCenter);


        gridLayout->addWidget(widget1, 4, 0, 1, 1);

        widget2 = new QWidget(Serial_Setting);
        widget2->setObjectName(QString::fromUtf8("widget2"));
        sizePolicy1.setHeightForWidth(widget2->sizePolicy().hasHeightForWidth());
        widget2->setSizePolicy(sizePolicy1);
        widget2->setMaximumSize(QSize(16777215, 25));
        horizontalLayout_3 = new QHBoxLayout(widget2);
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_2 = new QSpacerItem(187, 17, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        textEdit_Search = new QTextEdit(widget2);
        textEdit_Search->setObjectName(QString::fromUtf8("textEdit_Search"));
        textEdit_Search->setMinimumSize(QSize(0, 20));
        textEdit_Search->setMaximumSize(QSize(16777215, 25));
        textEdit_Search->setFont(font);

        horizontalLayout_3->addWidget(textEdit_Search);

        Search_Button = new QPushButton(widget2);
        Search_Button->setObjectName(QString::fromUtf8("Search_Button"));
        sizePolicy2.setHeightForWidth(Search_Button->sizePolicy().hasHeightForWidth());
        Search_Button->setSizePolicy(sizePolicy2);
        Search_Button->setMinimumSize(QSize(80, 20));
        Search_Button->setMaximumSize(QSize(80, 25));
        Search_Button->setFont(font);

        horizontalLayout_3->addWidget(Search_Button);

        Search_Button_Clean = new QPushButton(widget2);
        Search_Button_Clean->setObjectName(QString::fromUtf8("Search_Button_Clean"));
        sizePolicy2.setHeightForWidth(Search_Button_Clean->sizePolicy().hasHeightForWidth());
        Search_Button_Clean->setSizePolicy(sizePolicy2);
        Search_Button_Clean->setMinimumSize(QSize(80, 20));
        Search_Button_Clean->setMaximumSize(QSize(80, 25));
        Search_Button_Clean->setFont(font);

        horizontalLayout_3->addWidget(Search_Button_Clean);

        Search_Button_Refresh = new QPushButton(widget2);
        Search_Button_Refresh->setObjectName(QString::fromUtf8("Search_Button_Refresh"));
        sizePolicy2.setHeightForWidth(Search_Button_Refresh->sizePolicy().hasHeightForWidth());
        Search_Button_Refresh->setSizePolicy(sizePolicy2);
        Search_Button_Refresh->setMinimumSize(QSize(80, 20));
        Search_Button_Refresh->setMaximumSize(QSize(80, 25));
        Search_Button_Refresh->setFont(font);

        horizontalLayout_3->addWidget(Search_Button_Refresh);


        gridLayout->addWidget(widget2, 1, 0, 1, 1);

        Action_Widget->addTab(Serial_Setting, QString());

        gridLayout_2->addWidget(Action_Widget, 1, 0, 1, 1);

        widget3 = new QWidget(Widget);
        widget3->setObjectName(QString::fromUtf8("widget3"));
        widget3->setMaximumSize(QSize(16777215, 30));
        horizontalLayout_4 = new QHBoxLayout(widget3);
        horizontalLayout_4->setSpacing(2);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        SerialSettings = new QPushButton(widget3);
        SerialSettings->setObjectName(QString::fromUtf8("SerialSettings"));
        sizePolicy2.setHeightForWidth(SerialSettings->sizePolicy().hasHeightForWidth());
        SerialSettings->setSizePolicy(sizePolicy2);
        SerialSettings->setMinimumSize(QSize(80, 30));
        SerialSettings->setMaximumSize(QSize(80, 30));
        SerialSettings->setFont(font);

        horizontalLayout_4->addWidget(SerialSettings);

        BleSettings = new QPushButton(widget3);
        BleSettings->setObjectName(QString::fromUtf8("BleSettings"));
        BleSettings->setEnabled(false);
        sizePolicy2.setHeightForWidth(BleSettings->sizePolicy().hasHeightForWidth());
        BleSettings->setSizePolicy(sizePolicy2);
        BleSettings->setMinimumSize(QSize(80, 30));
        BleSettings->setMaximumSize(QSize(80, 30));
        BleSettings->setFont(font);

        horizontalLayout_4->addWidget(BleSettings);

        WebSettings = new QPushButton(widget3);
        WebSettings->setObjectName(QString::fromUtf8("WebSettings"));
        WebSettings->setEnabled(false);
        sizePolicy2.setHeightForWidth(WebSettings->sizePolicy().hasHeightForWidth());
        WebSettings->setSizePolicy(sizePolicy2);
        WebSettings->setMinimumSize(QSize(80, 30));
        WebSettings->setMaximumSize(QSize(80, 30));
        WebSettings->setFont(font);

        horizontalLayout_4->addWidget(WebSettings);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_10);

        Serial_State = new QLabel(widget3);
        Serial_State->setObjectName(QString::fromUtf8("Serial_State"));
        sizePolicy.setHeightForWidth(Serial_State->sizePolicy().hasHeightForWidth());
        Serial_State->setSizePolicy(sizePolicy);
        Serial_State->setMinimumSize(QSize(0, 30));
        Serial_State->setMaximumSize(QSize(16777215, 30));
        QFont font3;
        font3.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font3.setPointSize(10);
        font3.setBold(false);
        Serial_State->setFont(font3);

        horizontalLayout_4->addWidget(Serial_State);

        horizontalSpacer_11 = new QSpacerItem(112, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_11);

        Serial_Run = new QPushButton(widget3);
        Serial_Run->setObjectName(QString::fromUtf8("Serial_Run"));
        Serial_Run->setEnabled(false);
        sizePolicy2.setHeightForWidth(Serial_Run->sizePolicy().hasHeightForWidth());
        Serial_Run->setSizePolicy(sizePolicy2);
        Serial_Run->setMinimumSize(QSize(80, 30));
        Serial_Run->setMaximumSize(QSize(80, 30));
        Serial_Run->setFont(font);

        horizontalLayout_4->addWidget(Serial_Run);


        gridLayout_2->addWidget(widget3, 0, 0, 1, 1);

        widget4 = new QWidget(Widget);
        widget4->setObjectName(QString::fromUtf8("widget4"));
        widget4->setMaximumSize(QSize(16777215, 20));
        Count_Layout = new QHBoxLayout(widget4);
        Count_Layout->setSpacing(2);
        Count_Layout->setObjectName(QString::fromUtf8("Count_Layout"));
        Count_Layout->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        Count_Layout->addItem(horizontalSpacer_8);

        label_7 = new QLabel(widget4);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(20);
        sizePolicy6.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy6);
        label_7->setMinimumSize(QSize(0, 20));
        label_7->setMaximumSize(QSize(55, 25));
        QFont font4;
        font4.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font4.setPointSize(8);
        label_7->setFont(font4);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Count_Layout->addWidget(label_7);

        label_9 = new QLabel(widget4);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy6.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy6);
        label_9->setMinimumSize(QSize(0, 20));
        label_9->setMaximumSize(QSize(16777215, 25));
        label_9->setFont(font4);

        Count_Layout->addWidget(label_9);

        label_8 = new QLabel(widget4);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy6.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy6);
        label_8->setMinimumSize(QSize(0, 20));
        label_8->setMaximumSize(QSize(55, 25));
        label_8->setFont(font4);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        Count_Layout->addWidget(label_8);

        label_10 = new QLabel(widget4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        sizePolicy6.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy6);
        label_10->setMinimumSize(QSize(0, 20));
        label_10->setMaximumSize(QSize(16777215, 25));
        label_10->setFont(font4);

        Count_Layout->addWidget(label_10);

        Reset_Count_Button = new QPushButton(widget4);
        Reset_Count_Button->setObjectName(QString::fromUtf8("Reset_Count_Button"));
        QSizePolicy sizePolicy7(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(20);
        sizePolicy7.setHeightForWidth(Reset_Count_Button->sizePolicy().hasHeightForWidth());
        Reset_Count_Button->setSizePolicy(sizePolicy7);
        Reset_Count_Button->setMinimumSize(QSize(80, 20));
        Reset_Count_Button->setMaximumSize(QSize(80, 25));
        Reset_Count_Button->setFont(font4);

        Count_Layout->addWidget(Reset_Count_Button, 0, Qt::AlignRight|Qt::AlignVCenter);


        gridLayout_2->addWidget(widget4, 2, 0, 1, 1);

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
        Serial_Send_Display->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201\346\230\276\347\244\272", nullptr));
        Serial_Send_Clean->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272\345\217\221\351\200\201\345\214\272", nullptr));
        Serial_Send_Text->setText(QCoreApplication::translate("Widget", "Hex\345\217\221\351\200\201", nullptr));
        label_12->setText(QCoreApplication::translate("Widget", "ms", nullptr));
        Send_Timed->setText(QCoreApplication::translate("Widget", "\345\256\232\346\227\266\345\217\221\351\200\201", nullptr));
        Serial_Read_ON->setText(QCoreApplication::translate("Widget", "\346\216\245\346\224\266\346\230\276\347\244\272", nullptr));
        Serial_Read_Clean->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272\346\216\245\346\224\266\345\214\272", nullptr));
        Serial_Read_Text->setText(QCoreApplication::translate("Widget", "Hex\346\216\245\346\224\266", nullptr));
        Serial_Read_Time->setText(QCoreApplication::translate("Widget", "\346\227\266\351\227\264\346\210\263", nullptr));
        Serial_Read_Line->setText(QCoreApplication::translate("Widget", "\351\253\230\351\200\237\346\250\241\345\274\217", nullptr));
        Serial_Read_Save->setText(QCoreApplication::translate("Widget", "\344\277\235\345\255\230\346\226\207\344\273\266", nullptr));
        Open_Save->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\347\233\256\345\275\225", nullptr));
        Send_Button->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
        Search_Button->setText(QCoreApplication::translate("Widget", "\346\220\234\347\264\242", nullptr));
        Search_Button_Clean->setText(QCoreApplication::translate("Widget", "\346\270\205\347\251\272\346\220\234\347\264\242\345\214\272", nullptr));
        Search_Button_Refresh->setText(QCoreApplication::translate("Widget", "\345\256\236\346\227\266\345\210\267\346\226\260", nullptr));
        Action_Widget->setTabText(Action_Widget->indexOf(Serial_Setting), QCoreApplication::translate("Widget", "\346\225\260\346\215\256\346\224\266\345\217\221", nullptr));
        SerialSettings->setText(QCoreApplication::translate("Widget", "\344\270\262\345\217\243", nullptr));
        BleSettings->setText(QCoreApplication::translate("Widget", "BLE", nullptr));
        WebSettings->setText(QCoreApplication::translate("Widget", "WEB", nullptr));
        Serial_State->setText(QCoreApplication::translate("Widget", "\346\234\252\350\277\236\346\216\245", nullptr));
        Serial_Run->setText(QCoreApplication::translate("Widget", "\346\216\245\346\224\266", nullptr));
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
