#include "discharge_dialog.h"

DischargeDialog::DischargeDialog(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUi(this);
}

QString DischargeDialog::getValue()
{
   return ui.dateEdit->date().toString("dd.MM.yyyy");
}
