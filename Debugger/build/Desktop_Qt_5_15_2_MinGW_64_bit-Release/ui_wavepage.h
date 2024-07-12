/********************************************************************************
** Form generated from reading UI file 'wavepage.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAVEPAGE_H
#define UI_WAVEPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Wave/mycustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_wavepage
{
public:
    QGridLayout *gridLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_Data;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *Wave_Screen;
    QPushButton *Wave_Open;
    QPushButton *pushButton;
    QWidget *widget1;
    QHBoxLayout *horizontalLayout;
    QPushButton *Serial_Wave_ON;
    QPushButton *Serial_Wave_Clean;
    QSpacerItem *horizontalSpacer;
    QLabel *label_12;
    QComboBox *Serial_Wave_XMode;
    QPushButton *Serial_Wave_Dot;
    QPushButton *Serial_Wave_New;
    QPushButton *Serial_Wave_Zoom;
    QPushButton *Serial_Wave_ZoomAuto;
    QPushButton *Serial_Help;
    QGroupBox *verticalGroupBox;
    QVBoxLayout *verticalLayout;
    MyCustomPlot *qcpWidget;

    void setupUi(QWidget *wavepage)
    {
        if (wavepage->objectName().isEmpty())
            wavepage->setObjectName(QString::fromUtf8("wavepage"));
        wavepage->resize(649, 294);
        wavepage->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        wavepage->setFont(font);
        gridLayout = new QGridLayout(wavepage);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(0);
        gridLayout->setVerticalSpacing(2);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(wavepage);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setMaximumSize(QSize(16777215, 25));
        widget->setFont(font);
        horizontalLayout_2 = new QHBoxLayout(widget);
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_Data = new QLabel(widget);
        label_Data->setObjectName(QString::fromUtf8("label_Data"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_Data->sizePolicy().hasHeightForWidth());
        label_Data->setSizePolicy(sizePolicy);
        label_Data->setMinimumSize(QSize(0, 15));
        label_Data->setMaximumSize(QSize(16777215, 15));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        font1.setPointSize(9);
        label_Data->setFont(font1);

        horizontalLayout_2->addWidget(label_Data, 0, Qt::AlignRight|Qt::AlignVCenter);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        Wave_Screen = new QPushButton(widget);
        Wave_Screen->setObjectName(QString::fromUtf8("Wave_Screen"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(Wave_Screen->sizePolicy().hasHeightForWidth());
        Wave_Screen->setSizePolicy(sizePolicy1);
        Wave_Screen->setMinimumSize(QSize(70, 20));
        Wave_Screen->setMaximumSize(QSize(80, 20));
        Wave_Screen->setFont(font);

        horizontalLayout_2->addWidget(Wave_Screen);

        Wave_Open = new QPushButton(widget);
        Wave_Open->setObjectName(QString::fromUtf8("Wave_Open"));
        sizePolicy1.setHeightForWidth(Wave_Open->sizePolicy().hasHeightForWidth());
        Wave_Open->setSizePolicy(sizePolicy1);
        Wave_Open->setMinimumSize(QSize(100, 20));
        Wave_Open->setMaximumSize(QSize(80, 20));
        Wave_Open->setFont(font);

        horizontalLayout_2->addWidget(Wave_Open);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);
        pushButton->setMinimumSize(QSize(70, 20));
        pushButton->setMaximumSize(QSize(80, 20));
        pushButton->setFont(font);

        horizontalLayout_2->addWidget(pushButton);


        gridLayout->addWidget(widget, 0, 0, 1, 1);

        widget1 = new QWidget(wavepage);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setMaximumSize(QSize(16777215, 25));
        widget1->setFont(font);
        horizontalLayout = new QHBoxLayout(widget1);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Serial_Wave_ON = new QPushButton(widget1);
        Serial_Wave_ON->setObjectName(QString::fromUtf8("Serial_Wave_ON"));
        Serial_Wave_ON->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(Serial_Wave_ON->sizePolicy().hasHeightForWidth());
        Serial_Wave_ON->setSizePolicy(sizePolicy2);
        Serial_Wave_ON->setMinimumSize(QSize(60, 20));
        Serial_Wave_ON->setMaximumSize(QSize(80, 20));
        Serial_Wave_ON->setFont(font);

        horizontalLayout->addWidget(Serial_Wave_ON);

        Serial_Wave_Clean = new QPushButton(widget1);
        Serial_Wave_Clean->setObjectName(QString::fromUtf8("Serial_Wave_Clean"));
        Serial_Wave_Clean->setEnabled(true);
        sizePolicy2.setHeightForWidth(Serial_Wave_Clean->sizePolicy().hasHeightForWidth());
        Serial_Wave_Clean->setSizePolicy(sizePolicy2);
        Serial_Wave_Clean->setMinimumSize(QSize(60, 20));
        Serial_Wave_Clean->setMaximumSize(QSize(80, 20));
        Serial_Wave_Clean->setFont(font);

        horizontalLayout->addWidget(Serial_Wave_Clean);

        horizontalSpacer = new QSpacerItem(13, 27, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_12 = new QLabel(widget1);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        sizePolicy2.setHeightForWidth(label_12->sizePolicy().hasHeightForWidth());
        label_12->setSizePolicy(sizePolicy2);
        label_12->setMinimumSize(QSize(30, 20));
        label_12->setMaximumSize(QSize(30, 20));
        label_12->setFont(font);

        horizontalLayout->addWidget(label_12);

        Serial_Wave_XMode = new QComboBox(widget1);
        Serial_Wave_XMode->addItem(QString());
        Serial_Wave_XMode->addItem(QString());
        Serial_Wave_XMode->setObjectName(QString::fromUtf8("Serial_Wave_XMode"));
        sizePolicy2.setHeightForWidth(Serial_Wave_XMode->sizePolicy().hasHeightForWidth());
        Serial_Wave_XMode->setSizePolicy(sizePolicy2);
        Serial_Wave_XMode->setMinimumSize(QSize(70, 20));
        Serial_Wave_XMode->setMaximumSize(QSize(80, 20));
        Serial_Wave_XMode->setFont(font);
        Serial_Wave_XMode->setSizeAdjustPolicy(QComboBox::AdjustToContents);

        horizontalLayout->addWidget(Serial_Wave_XMode);

        Serial_Wave_Dot = new QPushButton(widget1);
        Serial_Wave_Dot->setObjectName(QString::fromUtf8("Serial_Wave_Dot"));
        Serial_Wave_Dot->setEnabled(true);
        sizePolicy2.setHeightForWidth(Serial_Wave_Dot->sizePolicy().hasHeightForWidth());
        Serial_Wave_Dot->setSizePolicy(sizePolicy2);
        Serial_Wave_Dot->setMinimumSize(QSize(60, 20));
        Serial_Wave_Dot->setMaximumSize(QSize(80, 20));
        Serial_Wave_Dot->setFont(font);

        horizontalLayout->addWidget(Serial_Wave_Dot);

        Serial_Wave_New = new QPushButton(widget1);
        Serial_Wave_New->setObjectName(QString::fromUtf8("Serial_Wave_New"));
        Serial_Wave_New->setEnabled(true);
        sizePolicy2.setHeightForWidth(Serial_Wave_New->sizePolicy().hasHeightForWidth());
        Serial_Wave_New->setSizePolicy(sizePolicy2);
        Serial_Wave_New->setMinimumSize(QSize(120, 20));
        Serial_Wave_New->setMaximumSize(QSize(80, 20));
        Serial_Wave_New->setFont(font);

        horizontalLayout->addWidget(Serial_Wave_New);

        Serial_Wave_Zoom = new QPushButton(widget1);
        Serial_Wave_Zoom->setObjectName(QString::fromUtf8("Serial_Wave_Zoom"));
        Serial_Wave_Zoom->setEnabled(true);
        sizePolicy2.setHeightForWidth(Serial_Wave_Zoom->sizePolicy().hasHeightForWidth());
        Serial_Wave_Zoom->setSizePolicy(sizePolicy2);
        Serial_Wave_Zoom->setMinimumSize(QSize(70, 20));
        Serial_Wave_Zoom->setMaximumSize(QSize(80, 20));
        Serial_Wave_Zoom->setFont(font);

        horizontalLayout->addWidget(Serial_Wave_Zoom);

        Serial_Wave_ZoomAuto = new QPushButton(widget1);
        Serial_Wave_ZoomAuto->setObjectName(QString::fromUtf8("Serial_Wave_ZoomAuto"));
        Serial_Wave_ZoomAuto->setEnabled(true);
        sizePolicy2.setHeightForWidth(Serial_Wave_ZoomAuto->sizePolicy().hasHeightForWidth());
        Serial_Wave_ZoomAuto->setSizePolicy(sizePolicy2);
        Serial_Wave_ZoomAuto->setMinimumSize(QSize(70, 20));
        Serial_Wave_ZoomAuto->setMaximumSize(QSize(80, 20));
        Serial_Wave_ZoomAuto->setFont(font);

        horizontalLayout->addWidget(Serial_Wave_ZoomAuto);

        Serial_Help = new QPushButton(widget1);
        Serial_Help->setObjectName(QString::fromUtf8("Serial_Help"));
        Serial_Help->setEnabled(true);
        sizePolicy2.setHeightForWidth(Serial_Help->sizePolicy().hasHeightForWidth());
        Serial_Help->setSizePolicy(sizePolicy2);
        Serial_Help->setMinimumSize(QSize(30, 20));
        Serial_Help->setMaximumSize(QSize(30, 20));
        Serial_Help->setFont(font);

        horizontalLayout->addWidget(Serial_Help);


        gridLayout->addWidget(widget1, 1, 0, 1, 1);

        verticalGroupBox = new QGroupBox(wavepage);
        verticalGroupBox->setObjectName(QString::fromUtf8("verticalGroupBox"));
        verticalLayout = new QVBoxLayout(verticalGroupBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        qcpWidget = new MyCustomPlot(verticalGroupBox);
        qcpWidget->setObjectName(QString::fromUtf8("qcpWidget"));
        qcpWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(qcpWidget->sizePolicy().hasHeightForWidth());
        qcpWidget->setSizePolicy(sizePolicy);
        qcpWidget->setFont(font);

        verticalLayout->addWidget(qcpWidget);


        gridLayout->addWidget(verticalGroupBox, 2, 0, 1, 1);


        retranslateUi(wavepage);

        QMetaObject::connectSlotsByName(wavepage);
    } // setupUi

    void retranslateUi(QWidget *wavepage)
    {
        wavepage->setWindowTitle(QCoreApplication::translate("wavepage", "Form", nullptr));
        label_Data->setText(QString());
        Wave_Screen->setText(QCoreApplication::translate("wavepage", "\346\210\252\345\261\217", nullptr));
        Wave_Open->setText(QCoreApplication::translate("wavepage", "\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271", nullptr));
        pushButton->setText(QCoreApplication::translate("wavepage", "\346\263\242\345\275\242\346\265\213\350\257\225", nullptr));
        Serial_Wave_ON->setText(QCoreApplication::translate("wavepage", "\347\273\230\345\233\276\346\230\276\347\244\272", nullptr));
        Serial_Wave_Clean->setText(QCoreApplication::translate("wavepage", "\346\270\205\347\251\272", nullptr));
        label_12->setText(QCoreApplication::translate("wavepage", "X\350\275\264", nullptr));
        Serial_Wave_XMode->setItemText(0, QCoreApplication::translate("wavepage", "\350\256\241\346\225\260", nullptr));
        Serial_Wave_XMode->setItemText(1, QCoreApplication::translate("wavepage", "\346\227\266\351\227\264", nullptr));

        Serial_Wave_Dot->setText(QCoreApplication::translate("wavepage", "\346\230\276\347\244\272\347\202\271", nullptr));
        Serial_Wave_New->setText(QCoreApplication::translate("wavepage", "\350\267\237\351\232\217\346\234\200\346\226\260\346\225\260\346\215\256", nullptr));
        Serial_Wave_Zoom->setText(QCoreApplication::translate("wavepage", "X\350\275\264\347\274\251\346\224\276", nullptr));
        Serial_Wave_ZoomAuto->setText(QCoreApplication::translate("wavepage", "\350\207\252\351\200\202\345\272\224", nullptr));
        Serial_Help->setText(QCoreApplication::translate("wavepage", "?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class wavepage: public Ui_wavepage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAVEPAGE_H
