#pragma once

#include <QObject>
#include <qmessagebox.h>
#include <qitemselectionmodel.h>
#include "ui_add_dialog.h"

struct PatientInfo
{
   QString name;
   QString lastname;
   QString patronymic;
   QString adress;
   QDate birthDate;
   QDate receiptDate;
   QDate dischargeDate;
};
class AddDialog : public QDialog
{
   Q_OBJECT

public:
   AddDialog( QWidget* parent = Q_NULLPTR );
   PatientInfo getInfo();
   void prepareForEdit(QItemSelection* itm);
   ~AddDialog();
public slots:
   void accept();
private:
   PatientInfo m_newPatient;
   Ui::Dialog ui;

};
