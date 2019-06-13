/********************************************************************************
** Form generated from reading UI file 'main_window.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_WINDOW_H
#define UI_MAIN_WINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataBaseClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAdd;
    QPushButton *btnSnap;
    QPushButton *btnDischarge;
    QPushButton *btnDelete;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DataBaseClass)
    {
        if (DataBaseClass->objectName().isEmpty())
            DataBaseClass->setObjectName(QString::fromUtf8("DataBaseClass"));
        DataBaseClass->resize(889, 570);
        centralWidget = new QWidget(DataBaseClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnAdd = new QPushButton(centralWidget);
        btnAdd->setObjectName(QString::fromUtf8("btnAdd"));

        horizontalLayout->addWidget(btnAdd);

        btnSnap = new QPushButton(centralWidget);
        btnSnap->setObjectName(QString::fromUtf8("btnSnap"));
        btnSnap->setEnabled(false);

        horizontalLayout->addWidget(btnSnap);

        btnDischarge = new QPushButton(centralWidget);
        btnDischarge->setObjectName(QString::fromUtf8("btnDischarge"));
        btnDischarge->setEnabled(false);

        horizontalLayout->addWidget(btnDischarge);

        btnDelete = new QPushButton(centralWidget);
        btnDelete->setObjectName(QString::fromUtf8("btnDelete"));
        btnDelete->setEnabled(false);

        horizontalLayout->addWidget(btnDelete);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setEnabled(true);
        tableView->setMinimumSize(QSize(871, 468));
        tableView->setMaximumSize(QSize(16777215, 16777215));
        tableView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);

        verticalLayout->addWidget(tableView);

        DataBaseClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DataBaseClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 889, 21));
        DataBaseClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DataBaseClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        DataBaseClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DataBaseClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DataBaseClass->setStatusBar(statusBar);

        retranslateUi(DataBaseClass);

        QMetaObject::connectSlotsByName(DataBaseClass);
    } // setupUi

    void retranslateUi(QMainWindow *DataBaseClass)
    {
        DataBaseClass->setWindowTitle(QApplication::translate("DataBaseClass", "Patients", nullptr));
        btnAdd->setText(QApplication::translate("DataBaseClass", "Add", nullptr));
        btnSnap->setText(QApplication::translate("DataBaseClass", "Snapshots", nullptr));
        btnDischarge->setText(QApplication::translate("DataBaseClass", "Discharge", nullptr));
        btnDelete->setText(QApplication::translate("DataBaseClass", "Delete", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataBaseClass: public Ui_DataBaseClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_WINDOW_H
