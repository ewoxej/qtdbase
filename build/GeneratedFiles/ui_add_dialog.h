/********************************************************************************
** Form generated from reading UI file 'add_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_DIALOG_H
#define UI_ADD_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label_10;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QPlainTextEdit *plainTextEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QPlainTextEdit *plainTextEdit_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QPlainTextEdit *plainTextEdit_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QPlainTextEdit *plainTextEdit_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_8;
    QDateEdit *dateEdit;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_9;
    QDateEdit *dateEdit_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *okButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->setWindowModality(Qt::WindowModal);
        Dialog->setEnabled(true);
        Dialog->resize(400, 230);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Dialog->sizePolicy().hasHeightForWidth());
        Dialog->setSizePolicy(sizePolicy);
        Dialog->setMinimumSize(QSize(400, 200));
        Dialog->setAutoFillBackground(false);
        verticalLayout = new QVBoxLayout(Dialog);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_10 = new QLabel(Dialog);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout->addWidget(label_10);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(5, -1, -1, -1);
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        plainTextEdit = new QPlainTextEdit(Dialog);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy1);
        plainTextEdit->setMaximumSize(QSize(16777215, 20));
        plainTextEdit->setAcceptDrops(true);
        plainTextEdit->setFrameShape(QFrame::StyledPanel);
        plainTextEdit->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_2->addWidget(plainTextEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(5, -1, -1, -1);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        plainTextEdit_2 = new QPlainTextEdit(Dialog);
        plainTextEdit_2->setObjectName(QString::fromUtf8("plainTextEdit_2"));
        sizePolicy1.setHeightForWidth(plainTextEdit_2->sizePolicy().hasHeightForWidth());
        plainTextEdit_2->setSizePolicy(sizePolicy1);
        plainTextEdit_2->setMaximumSize(QSize(16777215, 20));
        plainTextEdit_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        plainTextEdit_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_3->addWidget(plainTextEdit_2);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(5, -1, -1, -1);
        label_3 = new QLabel(Dialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_4->addWidget(label_3);

        plainTextEdit_3 = new QPlainTextEdit(Dialog);
        plainTextEdit_3->setObjectName(QString::fromUtf8("plainTextEdit_3"));
        sizePolicy1.setHeightForWidth(plainTextEdit_3->sizePolicy().hasHeightForWidth());
        plainTextEdit_3->setSizePolicy(sizePolicy1);
        plainTextEdit_3->setMaximumSize(QSize(16777215, 20));
        plainTextEdit_3->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_4->addWidget(plainTextEdit_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(5, -1, -1, -1);
        label_4 = new QLabel(Dialog);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_5->addWidget(label_4);

        plainTextEdit_4 = new QPlainTextEdit(Dialog);
        plainTextEdit_4->setObjectName(QString::fromUtf8("plainTextEdit_4"));
        sizePolicy1.setHeightForWidth(plainTextEdit_4->sizePolicy().hasHeightForWidth());
        plainTextEdit_4->setSizePolicy(sizePolicy1);
        plainTextEdit_4->setMaximumSize(QSize(16777215, 20));
        plainTextEdit_4->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_5->addWidget(plainTextEdit_4);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(5, -1, -1, -1);
        label_8 = new QLabel(Dialog);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_9->addWidget(label_8);

        dateEdit = new QDateEdit(Dialog);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        horizontalLayout_9->addWidget(dateEdit);


        verticalLayout->addLayout(horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(5, -1, -1, -1);
        label_9 = new QLabel(Dialog);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_10->addWidget(label_9);

        dateEdit_2 = new QDateEdit(Dialog);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));

        horizontalLayout_10->addWidget(dateEdit_2);


        verticalLayout->addLayout(horizontalLayout_10);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        okButton = new QPushButton(Dialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));

        horizontalLayout->addWidget(okButton);

        cancelButton = new QPushButton(Dialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Dialog);
        QObject::connect(okButton, SIGNAL(clicked()), Dialog, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Add...", nullptr));
        label_10->setText(QApplication::translate("Dialog", "Add a new patient:", nullptr));
        label->setText(QApplication::translate("Dialog", "Name", nullptr));
        label_2->setText(QApplication::translate("Dialog", "Lastname", nullptr));
        label_3->setText(QApplication::translate("Dialog", "Patronymic", nullptr));
        label_4->setText(QApplication::translate("Dialog", "Adress", nullptr));
        label_8->setText(QApplication::translate("Dialog", "Birth Date", nullptr));
        label_9->setText(QApplication::translate("Dialog", "Receipt Date", nullptr));
        okButton->setText(QApplication::translate("Dialog", "Add", nullptr));
        cancelButton->setText(QApplication::translate("Dialog", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_DIALOG_H
