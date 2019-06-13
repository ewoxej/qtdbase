/********************************************************************************
** Form generated from reading UI file 'snapshots_dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SNAPSHOTS_DIALOG_H
#define UI_SNAPSHOTS_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SnapshotsDialog
{
public:
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTableView *tableView;
    QHBoxLayout *hboxLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QLabel *label_2;

    void setupUi(QDialog *SnapshotsDialog)
    {
        if (SnapshotsDialog->objectName().isEmpty())
            SnapshotsDialog->setObjectName(QString::fromUtf8("SnapshotsDialog"));
        SnapshotsDialog->resize(800, 477);
        horizontalLayout = new QHBoxLayout(SnapshotsDialog);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(SnapshotsDialog);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        tableView = new QTableView(SnapshotsDialog);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        hboxLayout = new QHBoxLayout();
        hboxLayout->setSpacing(6);
        hboxLayout->setObjectName(QString::fromUtf8("hboxLayout"));
        hboxLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(SnapshotsDialog);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        hboxLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(SnapshotsDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);

        hboxLayout->addWidget(pushButton);


        verticalLayout->addLayout(hboxLayout);


        horizontalLayout->addLayout(verticalLayout);

        label_2 = new QLabel(SnapshotsDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        label_2->setMinimumSize(QSize(500, 400));
        QFont font;
        font.setPointSize(14);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label_2);


        retranslateUi(SnapshotsDialog);

        QMetaObject::connectSlotsByName(SnapshotsDialog);
    } // setupUi

    void retranslateUi(QDialog *SnapshotsDialog)
    {
        SnapshotsDialog->setWindowTitle(QApplication::translate("SnapshotsDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("SnapshotsDialog", "Patient name", nullptr));
        pushButton_2->setText(QApplication::translate("SnapshotsDialog", "Add", nullptr));
        pushButton->setText(QApplication::translate("SnapshotsDialog", "Delete", nullptr));
        label_2->setText(QApplication::translate("SnapshotsDialog", "Choose an image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SnapshotsDialog: public Ui_SnapshotsDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SNAPSHOTS_DIALOG_H
