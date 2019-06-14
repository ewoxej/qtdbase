#pragma once

#include <QObject>
#include <QtSql>
#include <qfiledialog.h>
#include "ui_snapshots_dialog.h"
#include <qmessagebox.h>
enum PatientsIndexes
{
   eDB_ID,
   eDB_Name,
   eDB_LastName,
   eDB_Patronymic,
   eDB_BirthDate,
   eDB_Adress,
   eDB_ReceiptDate,
   eDB_DischargeDate
};

enum SnapshotsIndexes
{
   eSI_ID,
   eSI_FilePath,
   eSI_SnapDate,
   eSI_PatientId
};

class SnapshotsDialog : public QDialog
{
   Q_OBJECT

public:
   SnapshotsDialog( QWidget *parent, QItemSelection* sel );
   void cleanSnapshots();
public slots:
   void onAddPressed();
   void onDeletePressed();
   void onTableViewItemSelected( QItemSelection, QItemSelection );
private:
   void dataBaseInit( QString dbname );
   void setUiInit();
   Ui::SnapshotsDialog ui;
   QItemSelection* m_patientItem;
   QItemSelection m_curSelect;
   QSqlDatabase m_Db;
   QSqlTableModel* m_DbModel;
};
