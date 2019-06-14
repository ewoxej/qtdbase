#include "add_dialog.h"

AddDialog::AddDialog( QWidget* parent ) :QDialog( parent )
{
   ui.setupUi( this );
   ui.dateEdit->setDate( QDate::currentDate() );
   ui.dateEdit_2->setDate( QDate::currentDate() );
}

void AddDialog::accept()
{
   m_newPatient.name = ui.plainTextEdit->toPlainText();
   m_newPatient.lastname = ui.plainTextEdit_2->toPlainText();
   m_newPatient.patronymic = ui.plainTextEdit_3->toPlainText();
   m_newPatient.adress = ui.plainTextEdit_4->toPlainText();
   m_newPatient.birthDate = ui.dateEdit->date();
   m_newPatient.receiptDate = ui.dateEdit_2->date();
   if (m_newPatient.receiptDate < m_newPatient.birthDate || m_newPatient.birthDate>QDate::currentDate() || m_newPatient.receiptDate > QDate::currentDate())
   {
      QMessageBox* msgb = new QMessageBox( this );
      msgb->setText( "Receipt and birth date must be correct!" );
      msgb->show();
      return;
   }
   QDialog::accept();
}
PatientInfo AddDialog::getInfo()
{
   return m_newPatient;
}

AddDialog::~AddDialog()
{
}
