#pragma once

#include <qmessagebox.h>
#include <QtWidgets/QMainWindow>
#include <QtSql>
#include "add_dialog.h"
#include "discharge_dialog.h"
#include "snapshots_dialog.h"
#include "ui_main_window.h"

class MainWindow : public QMainWindow
{
   Q_OBJECT
public:
   MainWindow(QWidget *parent = Q_NULLPTR);
   QItemSelection getCurrentSelection();
public slots:
   void onAddPressed();
   void onSnapPressed();
   void onDischargePressed();
   void onDischarged();
   void onDeletePressed();
   void onInsertPatient();
   void onTableViewItemSelected(QItemSelection, QItemSelection);
private:
   void dataBaseInit(QString dbname);
   void deletePatientAndSnapshots();
   void setUiInit();
   Ui::DataBaseClass ui;
   AddDialog* m_dialogAdd;
   QSqlDatabase m_Db;
   DischargeDialog* m_dischargeDialog;
   QSqlTableModel* m_DbModel;
   QItemSelection m_curSelect;
};
