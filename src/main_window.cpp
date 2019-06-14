#include "main_window.h"

MainWindow::MainWindow( QWidget *parent )
   : QMainWindow( parent ),m_dischargeDialog(NULL)
{
   dataBaseInit( "patients.db" );
   setUiInit();
   QObject::connect( ui.btnAdd, &QPushButton::clicked, this, &MainWindow::onAddPressed );
   QObject::connect( ui.btnEdit, &QPushButton::clicked, this, &MainWindow::onEditPressed );
   QObject::connect( ui.btnDelete, &QPushButton::clicked, this, &MainWindow::onDeletePressed );
   QObject::connect( ui.btnSnap, &QPushButton::clicked, this, &MainWindow::onSnapPressed );
}

void MainWindow::onAddPressed()
{
   m_dialogAdd = new AddDialog( this );
   QObject::connect( m_dialogAdd, &AddDialog::accepted, this, &MainWindow::onInsertPatient );
   m_dialogAdd->show();
}

void MainWindow::onEditPressed()
{
   m_dialogAdd = new AddDialog( this );
   m_dialogAdd->prepareForEdit( &m_curSelect );
   QObject::connect( m_dialogAdd, &AddDialog::accepted, this, &MainWindow::onEditPatient );
   m_dialogAdd->show();
}

void MainWindow::onSnapPressed()
{
   SnapshotsDialog* m_dialogSnapshots = new SnapshotsDialog( this, &m_curSelect );
   m_dialogSnapshots->show();
}

void MainWindow::onTableViewItemSelected( QItemSelection itemSel, QItemSelection itemDesel )
{
   m_curSelect = itemSel;
   ui.btnSnap->setEnabled( true );
   ui.btnDelete->setEnabled( true );
   ui.btnEdit->setEnabled( true );
}

void MainWindow::onDeletePressed()
{
   QMessageBox::StandardButton reply;
   reply = QMessageBox::question( this, "Are you sure?", "Delete this patient?",
      QMessageBox::Yes | QMessageBox::No );
   if (reply == QMessageBox::Yes)
   {
      deletePatientAndSnapshots();
      ui.btnSnap->setEnabled( false );
      ui.btnDelete->setEnabled( false );
      ui.btnEdit->setEnabled( false );
   }
}

void MainWindow::onInsertPatient()
{
   PatientInfo info = m_dialogAdd->getInfo();
   QSqlQuery addQuery( m_Db );
   addQuery.prepare(
      "INSERT INTO Patients(Name,LastName,Patronymic,BirthDate,Adress,ReceiptDate,DischargeDate)\
     VALUES(:bindedName,:bindedLastName,:bindedPatr,:bindedBirthDate,:bindedAdr,:bindedReceiptDate,:bindedDischargeDate)" );
   addQuery.bindValue( ":bindedName", info.name );
   addQuery.bindValue( ":bindedLastName", info.lastname );
   addQuery.bindValue( ":bindedPatr", info.patronymic );
   addQuery.bindValue( ":bindedAdr", info.adress );
   addQuery.bindValue( ":bindedBirthDate", info.birthDate.toString( "MM.dd.yyyy" ) );
   addQuery.bindValue( ":bindedReceiptDate", info.receiptDate.toString( "MM.dd.yyyy" ) );
   addQuery.bindValue( ":bindedDischargeDate", info.dischargeDate.toString( "MM.dd.yyyy" ) );
   addQuery.exec();
   m_DbModel->select();
   ui.btnSnap->setEnabled( false );
   ui.btnDelete->setEnabled( false );
   ui.btnEdit->setEnabled( false );
}

void MainWindow::onEditPatient()
{
   PatientInfo info = m_dialogAdd->getInfo();
   m_DbModel->setData( m_DbModel->index( m_curSelect.indexes()[0].row(), eDB_Name ), info.name );
   m_DbModel->setData( m_DbModel->index( m_curSelect.indexes()[0].row(), eDB_LastName ), info.lastname );
   m_DbModel->setData( m_DbModel->index( m_curSelect.indexes()[0].row(), eDB_Patronymic ), info.patronymic );
   m_DbModel->setData( m_DbModel->index( m_curSelect.indexes()[0].row(), eDB_Adress ), info.adress );
   m_DbModel->setData( m_DbModel->index( m_curSelect.indexes()[0].row(), eDB_BirthDate ), info.birthDate.toString("MM.dd.yyyy") );
   m_DbModel->setData( m_DbModel->index( m_curSelect.indexes()[0].row(), eDB_ReceiptDate ), info.receiptDate.toString("MM.dd.yyyy") );
   m_DbModel->setData( m_DbModel->index( m_curSelect.indexes()[0].row(), eDB_DischargeDate ), info.dischargeDate.toString("MM.dd.yyyy") );
}

void MainWindow::deletePatientAndSnapshots()
{
   SnapshotsDialog* dlg = new SnapshotsDialog( this, &m_curSelect );
   dlg->cleanSnapshots();
   m_DbModel->removeRow( m_curSelect.indexes()[eDB_ID].row() );
   m_DbModel->select();
}

QItemSelection MainWindow::getCurrentSelection()
{
   return m_curSelect;
}

void MainWindow::dataBaseInit( QString dbname )
{
   m_Db = QSqlDatabase::addDatabase( "QSQLITE" );
   m_Db.setDatabaseName( dbname );
   m_Db.open();
   m_Db.exec
   (
      "CREATE TABLE Patients\
      (\
      ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,\
      Name TEXT,\
      LastName TEXT,\
      Patronymic TEXT,\
      BirthDate DATE,\
      Adress TEXT,\
      ReceiptDate DATE,\
      DischargeDate DATE\
      );"
   );
   m_Db.exec( "PRAGMA foreign_keys=on" );//FOREIGN keys are disabled on SQLITE by default
   QSqlQuery res = m_Db.exec
   (
      "CREATE TABLE Snapshots\
      (\
      ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL,\
      FilePath TEXT,\
      SnapDate DATE,\
      PatientId INTEGER NOT NULL,\
      FOREIGN KEY(PatientId) REFERENCES Patients(ID)\
      );"
   );
   QDir().mkdir( "snapshots" );
}

void MainWindow::setUiInit()
{
   ui.setupUi( this );
   m_DbModel = new QSqlTableModel( this, m_Db );
   m_DbModel->setTable( "Patients" );
   m_DbModel->select();
   m_DbModel->setEditStrategy( QSqlTableModel::OnFieldChange );
   ui.tableView->setEditTriggers( QAbstractItemView::NoEditTriggers );
   ui.tableView->setModel( m_DbModel );
   ui.tableView->setSelectionMode( QAbstractItemView::SingleSelection );
   ui.tableView->setSelectionBehavior( QAbstractItemView::SelectRows );
   QItemSelectionModel *sm = ui.tableView->selectionModel();
   QObject::connect( sm, &QItemSelectionModel::selectionChanged, this, &MainWindow::onTableViewItemSelected );
   ui.tableView->hideColumn( 0 );
   ui.tableView->horizontalHeader()->setSectionResizeMode( 0, QHeaderView::Stretch );
}
