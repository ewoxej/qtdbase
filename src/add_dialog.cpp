#include "add_dialog.h"

AddDialog::AddDialog( QWidget* parent ) :QDialog( parent )
{
   ui.setupUi( this );
   ui.dateEdit_2->setDate( QDate::currentDate() );
   ui.dateEdit_3->setDate( QDate::currentDate() );
}

void AddDialog::accept()
{
   m_newPatient.name = ui.plainTextEdit->toPlainText();
   m_newPatient.lastname = ui.plainTextEdit_2->toPlainText();
   m_newPatient.patronymic = ui.plainTextEdit_3->toPlainText();
   m_newPatient.adress = ui.plainTextEdit_4->toPlainText();
   m_newPatient.birthDate = ui.dateEdit->date();
   m_newPatient.receiptDate = ui.dateEdit_2->date();
   if (ui.checkBox->checkState() == Qt::Checked)
      m_newPatient.dischargeDate = ui.dateEdit_3->date();
   if (m_newPatient.name == "" || m_newPatient.lastname == "" || m_newPatient.patronymic == "" || m_newPatient.adress == "")
   {
      QMessageBox* msgb = new QMessageBox( this );
      msgb->setText( "All fields must be filled!" );
      msgb->show();
      return;
   }
   QRegExp forbSymbols ("[0-9]");
   if (m_newPatient.name.contains(forbSymbols) || m_newPatient.lastname.contains( forbSymbols ) || m_newPatient.patronymic.contains( forbSymbols ) )
   {
      QMessageBox* msgb = new QMessageBox( this );
      msgb->setText( "You can`t enter digits!" );
      msgb->show();
      return;
   }
   if (m_newPatient.receiptDate < m_newPatient.birthDate ||
      (m_newPatient.dischargeDate < m_newPatient.receiptDate ||
      m_newPatient.dischargeDate>QDate::currentDate()) && (ui.checkBox->isChecked()) ||
      m_newPatient.birthDate>QDate::currentDate() ||
      m_newPatient.receiptDate > QDate::currentDate())
   {
      QMessageBox* msgb = new QMessageBox( this );
      msgb->setText( "Check entered dates!" );
      msgb->show();
      return;
   }
   QDialog::accept();
}
PatientInfo AddDialog::getInfo()
{
   return m_newPatient;
}

void AddDialog::prepareForEdit( QItemSelection* curSel )
{
   m_newPatient.name = curSel->indexes()[1].data().toString();
   m_newPatient.lastname = curSel->indexes()[2].data().toString();
   m_newPatient.patronymic = curSel->indexes()[3].data().toString();
   m_newPatient.birthDate = QDate::fromString( curSel->indexes()[4].data().toString(), "MM.dd.yyyy" );
   m_newPatient.adress = curSel->indexes()[5].data().toString();
   m_newPatient.receiptDate = QDate::fromString( curSel->indexes()[6].data().toString(), "MM.dd.yyyy" );
   m_newPatient.dischargeDate = QDate::fromString( curSel->indexes()[7].data().toString(), "MM.dd.yyyy" );
   ui.label_10->setText( "Edit patient:" );
   ui.okButton->setText( "Save" );
   ui.dateEdit->setDate( m_newPatient.birthDate );
   ui.dateEdit_2->setDate( m_newPatient.receiptDate );
   if (!m_newPatient.dischargeDate.isNull())
      ui.dateEdit_3->setDate( m_newPatient.dischargeDate );
   ui.plainTextEdit->insertPlainText( m_newPatient.name );
   ui.plainTextEdit_2->setPlainText( m_newPatient.lastname );
   ui.plainTextEdit_3->setPlainText( m_newPatient.patronymic );
   ui.plainTextEdit_4->setPlainText( m_newPatient.adress );
   if (curSel->indexes()[7].data().toString() != "")
   {
      ui.checkBox->setCheckState( Qt::Checked );
      ui.checkBox->setEnabled( false );
   }
}

AddDialog::~AddDialog()
{
}
