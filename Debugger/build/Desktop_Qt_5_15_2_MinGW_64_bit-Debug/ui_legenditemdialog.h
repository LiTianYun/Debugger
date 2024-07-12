/********************************************************************************
** Form generated from reading UI file 'legenditemdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LEGENDITEMDIALOG_H
#define UI_LEGENDITEMDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_LegendItemDialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLineEdit *nameEdit;
    QLabel *label_2;
    QPushButton *colorButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *LegendItemDialog)
    {
        if (LegendItemDialog->objectName().isEmpty())
            LegendItemDialog->setObjectName(QString::fromUtf8("LegendItemDialog"));
        LegendItemDialog->resize(200, 175);
        verticalLayout = new QVBoxLayout(LegendItemDialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(LegendItemDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        nameEdit = new QLineEdit(LegendItemDialog);
        nameEdit->setObjectName(QString::fromUtf8("nameEdit"));
        nameEdit->setEnabled(false);

        verticalLayout->addWidget(nameEdit);

        label_2 = new QLabel(LegendItemDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        colorButton = new QPushButton(LegendItemDialog);
        colorButton->setObjectName(QString::fromUtf8("colorButton"));

        verticalLayout->addWidget(colorButton);

        buttonBox = new QDialogButtonBox(LegendItemDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(LegendItemDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), LegendItemDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LegendItemDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(LegendItemDialog);
    } // setupUi

    void retranslateUi(QDialog *LegendItemDialog)
    {
        label->setText(QCoreApplication::translate("LegendItemDialog", "\346\233\262\347\272\277\345\220\215\347\247\260:", nullptr));
        label_2->setText(QCoreApplication::translate("LegendItemDialog", "\351\242\234\350\211\262:", nullptr));
        (void)LegendItemDialog;
    } // retranslateUi

};

namespace Ui {
    class LegendItemDialog: public Ui_LegendItemDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LEGENDITEMDIALOG_H
