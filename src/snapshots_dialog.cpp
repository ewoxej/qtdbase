#include "snapshots_dialog.h"

SnapshotsDialog::SnapshotsDialog(QWidget *parent, QItemSelection* sel)
   : QDialog(parent), m_patientItem(sel)
{
   dataBaseInit("patients.db");
   setUiInit();
   QObject::connect(ui.pushButton_2, SIGNAL(clicked()), this, SLOT(onAddPressed()));
   QObject::connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(onDeletePressed()));
}

void SnapshotsDialog::onAddPressed()
{
   QString fullPath = QFileDialog::getOpenFileName(this, "Choose snapshot", QString(), "*.jpg");
   QString id = m_patientItem->indexes()[eDB_ID].data().toString();
   QFile file(fullPath);
   file.setPermissions(QFileDevice::WriteUser | QFileDevice::ReadUser | QFileDevice::ExeUser);
   QString newpath = "snapshots/" + id + "_" + QString::number(m_DbModel->rowCount()) + ".jpg";
   QFileInfo finfo(file);
   QDateTime fileCreationDate = finfo.birthTime();
   QSqlQuery addQuery(m_Db);
   addQuery.prepare
   (
     "INSERT INTO Snapshots(FilePath,SnapDate,PatientId)\
     VALUES(:bindedPath,:bindedDate,:bindedID)"
   );
   addQuery.bindValue(":bindedPath", newpath);
   addQuery.bindValue(":bindedDate", fileCreationDate.toString("dd.MM.yyyy"));
   addQuery.bindValue(":bindedID", id);
   addQuery.exec();
   m_DbModel->select();
   file.copy(newpath);
}

void SnapshotsDialog::onDeletePressed()
{
   auto ilist = m_curSelect.indexes();
   QString deletePath = ilist[eSI_FilePath].data().toString();
   m_DbModel->removeRow(ilist[eSI_ID].row());
   ui.label_2->setText("Choose an image");
   QFile file(deletePath);
   file.setPermissions(QFileDevice::WriteUser | QFileDevice::ReadUser | QFileDevice::ExeUser);
   bool ok = file.remove();
   m_DbModel->select();
}

void SnapshotsDialog::onTableViewItemSelected(QItemSelection itemSel, QItemSelection itemDesel)
{
   ui.pushButton->setEnabled(true);
   m_curSelect = itemSel;
   auto ilist = itemSel.indexes();
   QString path = ilist[1].data().toString();
   QPixmap pix(path);
   pix = pix.scaled(500, 500, Qt::KeepAspectRatio, Qt::SmoothTransformation);
   ui.label_2->setPixmap(pix);
}

void SnapshotsDialog::dataBaseInit(QString dbname)
{
   m_Db = QSqlDatabase::addDatabase("QSQLITE");
   m_Db.setDatabaseName(dbname);
   m_Db.open();
}

void SnapshotsDialog::setUiInit()
{
   ui.setupUi(this);
   m_DbModel = new QSqlTableModel(this, m_Db);
   m_DbModel->setTable("Snapshots");
   QString id = m_patientItem->indexes()[eDB_ID].data().toString();
   m_DbModel->setFilter("PatientID = " + id);
   m_DbModel->select();
   m_DbModel->setEditStrategy(QSqlTableModel::OnRowChange);
   ui.tableView->setModel(m_DbModel);
   ui.tableView->setSelectionMode(QAbstractItemView::SingleSelection);
   ui.tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
   ui.tableView->hideColumn(eSI_ID);
   ui.label->setText
   ((m_patientItem->indexes()[eDB_Name].data().toString()) + " " +
      (m_patientItem->indexes()[eDB_LastName].data().toString()) + " snapshots:");
   ui.tableView->hideColumn(eSI_FilePath);
   ui.tableView->hideColumn(eSI_PatientId);
   ui.tableView->horizontalHeader()->setSectionResizeMode(eSI_SnapDate, QHeaderView::Stretch);
   ui.tableView->sortByColumn(eSI_SnapDate);
   QItemSelectionModel* sm = ui.tableView->selectionModel();
   QObject::connect(sm, SIGNAL(selectionChanged(QItemSelection, QItemSelection)),
      this, SLOT(onTableViewItemSelected(QItemSelection, QItemSelection)));
}


void SnapshotsDialog::cleanSnapshots()
{
   for (int i = 0; i < m_DbModel->rowCount(); i++)
   {
      QString val = m_DbModel->data(m_DbModel->index(i, 1)).toString();
      QFile delFile(val);
      delFile.remove();
      m_DbModel->removeRow(i);
   }
}
