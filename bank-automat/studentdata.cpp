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
