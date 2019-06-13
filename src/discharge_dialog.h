#pragma once

#include <QWidget>
#include <qdialog.h>
#include "ui_discharge_dialog.h"

class DischargeDialog : public QDialog
{
    Q_OBJECT

public:
    DischargeDialog(QWidget *parent = Q_NULLPTR);
    QString getValue();
private:
    Ui::DischargeDialog ui;
};
