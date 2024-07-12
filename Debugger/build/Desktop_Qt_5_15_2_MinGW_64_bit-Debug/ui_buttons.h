/********************************************************************************
** Form generated from reading UI file 'buttons.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUTTONS_H
#define UI_BUTTONS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "Buttons/buttons.h"

QT_BEGIN_NAMESPACE

class Ui_Buttons
{
public:
    QGridLayout *gridLayout;
    QGroupBox *gridGroupBox;
    QGridLayout *gridLayout_2;
    MyFrame *frame;
    QPushButton *Button_add;

    void setupUi(QWidget *Buttons)
    {
        if (Buttons->objectName().isEmpty())
            Buttons->setObjectName(QString::fromUtf8("Buttons"));
        Buttons->resize(300, 275);
        Buttons->setMinimumSize(QSize(0, 0));
        gridLayout = new QGridLayout(Buttons);
        gridLayout->setSpacing(5);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        gridGroupBox = new QGroupBox(Buttons);
        gridGroupBox->setObjectName(QString::fromUtf8("gridGroupBox"));
        gridLayout_2 = new QGridLayout(gridGroupBox);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        frame = new MyFrame(gridGroupBox);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        gridLayout_2->addWidget(frame, 0, 0, 1, 1);


        gridLayout->addWidget(gridGroupBox, 1, 1, 1, 1);

        Button_add = new QPushButton(Buttons);
        Button_add->setObjectName(QString::fromUtf8("Button_add"));
        Button_add->setMinimumSize(QSize(100, 30));
        Button_add->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(Button_add, 0, 1, 1, 1);


        retranslateUi(Buttons);

        QMetaObject::connectSlotsByName(Buttons);
    } // setupUi

    void retranslateUi(QWidget *Buttons)
    {
        Buttons->setWindowTitle(QCoreApplication::translate("Buttons", "Form", nullptr));
        Button_add->setText(QCoreApplication::translate("Buttons", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Buttons: public Ui_Buttons {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUTTONS_H
