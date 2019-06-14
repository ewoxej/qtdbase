#include "discharge_dialog.h"

DischargeDialog::DischargeDialog( QWidget *parent )
   : QDialog( parent )
{
   ui.setupUi( this );
   ui.dateEdit->setDate( QDate::currentDate() );
}

QDate DischargeDialog::getValue()
{
   return ui.dateEdit->date();
}
