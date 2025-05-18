/********************************************************************************
** Form generated from reading UI file 'discharge_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISCHARGE_DIALOG_H
#define UI_DISCHARGE_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DischargeDialog
{
public:
    QVBoxLayout *verticalLayout;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *DischargeDialog)
    {
        if (DischargeDialog->objectName().isEmpty())
            DischargeDialog->setObjectName(QString::fromUtf8("DischargeDialog"));
        DischargeDialog->resize(199, 103);
        verticalLayout = new QVBoxLayout(DischargeDialog);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        dateEdit = new QDateEdit(DischargeDialog);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        verticalLayout->addWidget(dateEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_2 = new QPushButton(DischargeDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(DischargeDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DischargeDialog);
        QObject::connect(pushButton_2, SIGNAL(clicked()), DischargeDialog, SLOT(accept()));
        QObject::connect(pushButton, SIGNAL(clicked()), DischargeDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(DischargeDialog);
    } // setupUi

    void retranslateUi(QDialog *DischargeDialog)
    {
        DischargeDialog->setWindowTitle(QApplication::translate("DischargeDialog", "DischargeDialog", nullptr));
        pushButton_2->setText(QApplication::translate("DischargeDialog", "OK", nullptr));
        pushButton->setText(QApplication::translate("DischargeDialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DischargeDialog: public Ui_DischargeDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISCHARGE_DIALOG_H
