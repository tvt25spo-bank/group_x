#include "studentdata.h"
#include "ui_studentdata.h"

StudentData::StudentData(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StudentData)
{
    ui->setupUi(this);
}

StudentData::~StudentData()
{
    delete ui;
}

void StudentData::SetData(QString u, QString f, QString l, QString e)
{
    ui->textUsername->setText(u);
    ui->textFname->setText(f);
    ui->textLname->setText(l);
    ui->textEmail->setText(e);
}
