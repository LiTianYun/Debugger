/********************************************************************************
** Form generated from reading UI file 'buttons.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUTTONS_H
#define UI_BUTTONS_H

#include <Buttons/buttons.h>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Buttons
{
public:
    QVBoxLayout *verticalLayout_2;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Button_add;
    QPushButton *Button_clear;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *Button_auto;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Button_Load;
    QPushButton *Button_save_2;
    QPushButton *Button_save_as;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer_4;
    QGroupBox *verticalGroupBox;
    QVBoxLayout *verticalLayout;
    MyFrame *myFrame;

    void setupUi(QWidget *Buttons)
    {
        if (Buttons->objectName().isEmpty())
            Buttons->setObjectName(QString::fromUtf8("Buttons"));
        Buttons->resize(443, 280);
        Buttons->setMinimumSize(QSize(0, 0));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\273\221\344\275\223"));
        Buttons->setFont(font);
        verticalLayout_2 = new QVBoxLayout(Buttons);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(Buttons);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Button_add = new QPushButton(widget);
        Button_add->setObjectName(QString::fromUtf8("Button_add"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Button_add->sizePolicy().hasHeightForWidth());
        Button_add->setSizePolicy(sizePolicy);
        Button_add->setMinimumSize(QSize(70, 20));
        Button_add->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(Button_add);

        Button_clear = new QPushButton(widget);
        Button_clear->setObjectName(QString::fromUtf8("Button_clear"));
        sizePolicy.setHeightForWidth(Button_clear->sizePolicy().hasHeightForWidth());
        Button_clear->setSizePolicy(sizePolicy);
        Button_clear->setMinimumSize(QSize(70, 20));
        Button_clear->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(Button_clear);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        Button_auto = new QPushButton(widget);
        Button_auto->setObjectName(QString::fromUtf8("Button_auto"));
        sizePolicy.setHeightForWidth(Button_auto->sizePolicy().hasHeightForWidth());
        Button_auto->setSizePolicy(sizePolicy);
        Button_auto->setMinimumSize(QSize(70, 20));
        Button_auto->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(Button_auto);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        Button_Load = new QPushButton(widget);
        Button_Load->setObjectName(QString::fromUtf8("Button_Load"));
        sizePolicy.setHeightForWidth(Button_Load->sizePolicy().hasHeightForWidth());
        Button_Load->setSizePolicy(sizePolicy);
        Button_Load->setMinimumSize(QSize(70, 20));
        Button_Load->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(Button_Load);

        Button_save_2 = new QPushButton(widget);
        Button_save_2->setObjectName(QString::fromUtf8("Button_save_2"));
        sizePolicy.setHeightForWidth(Button_save_2->sizePolicy().hasHeightForWidth());
        Button_save_2->setSizePolicy(sizePolicy);
        Button_save_2->setMinimumSize(QSize(50, 20));
        Button_save_2->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(Button_save_2);

        Button_save_as = new QPushButton(widget);
        Button_save_as->setObjectName(QString::fromUtf8("Button_save_as"));
        sizePolicy.setHeightForWidth(Button_save_as->sizePolicy().hasHeightForWidth());
        Button_save_as->setSizePolicy(sizePolicy);
        Button_save_as->setMinimumSize(QSize(50, 20));
        Button_save_as->setMaximumSize(QSize(16777215, 30));

        horizontalLayout->addWidget(Button_save_as);


        verticalLayout_2->addWidget(widget);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(Buttons);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMaximumSize(QSize(16777215, 30));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        verticalLayout_2->addLayout(horizontalLayout_2);

        verticalGroupBox = new QGroupBox(Buttons);
        verticalGroupBox->setObjectName(QString::fromUtf8("verticalGroupBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(verticalGroupBox->sizePolicy().hasHeightForWidth());
        verticalGroupBox->setSizePolicy(sizePolicy1);
        verticalLayout = new QVBoxLayout(verticalGroupBox);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        myFrame = new MyFrame(verticalGroupBox);
        myFrame->setObjectName(QString::fromUtf8("myFrame"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(myFrame->sizePolicy().hasHeightForWidth());
        myFrame->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(myFrame);


        verticalLayout_2->addWidget(verticalGroupBox);


        retranslateUi(Buttons);

        QMetaObject::connectSlotsByName(Buttons);
    } // setupUi

    void retranslateUi(QWidget *Buttons)
    {
        Buttons->setWindowTitle(QCoreApplication::translate("Buttons", "Form", nullptr));
        Button_add->setText(QCoreApplication::translate("Buttons", "\345\242\236\345\212\240\346\216\247\344\273\266", nullptr));
        Button_clear->setText(QCoreApplication::translate("Buttons", "\346\270\205\347\251\272\346\216\247\344\273\266", nullptr));
        Button_auto->setText(QCoreApplication::translate("Buttons", "\350\207\252\345\212\250\345\270\203\345\261\200", nullptr));
        Button_Load->setText(QCoreApplication::translate("Buttons", "\345\212\240\350\275\275\346\216\247\344\273\266\347\273\204", nullptr));
        Button_save_2->setText(QCoreApplication::translate("Buttons", "\344\277\235\345\255\230", nullptr));
        Button_save_as->setText(QCoreApplication::translate("Buttons", "\345\217\246\345\255\230\344\270\272", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Buttons: public Ui_Buttons {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUTTONS_H
