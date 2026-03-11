#include "studentinfo.h"
#include "ui_studentinfo.h"

StudentInfo::StudentInfo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StudentInfo)
{
    ui->setupUi(this);

}

StudentInfo::~StudentInfo()
{
    delete ui;
}

void StudentInfo::setUsername(const QString &newUsername)
{
    username = newUsername;
}

void StudentInfo::setToken(const QByteArray &newToken)
{
    token = newToken;
    ui->labelUserInfo->setText("Tervetuloa:"+this->username+ "token="+this->token);
}
