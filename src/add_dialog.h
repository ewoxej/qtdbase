#pragma once

#include <QObject>
#include <qmessagebox.h>
#include "ui_add_dialog.h"

struct PatientInfo
{
   QString name;
   QString lastname;
   QString patronymic;
   QString adress;
   QDate birthDate;
   QDate receiptDate;
};
class AddDialog : public QDialog
{
   Q_OBJECT

public:
   AddDialog( QWidget* parent = Q_NULLPTR );
   PatientInfo getInfo();
   ~AddDialog();
public slots:
   void accept();
private:
   PatientInfo m_newPatient;
   Ui::Dialog ui;

};
