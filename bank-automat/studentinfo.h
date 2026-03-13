#ifndef STUDENTINFO_H
#define STUDENTINFO_H

#include <QDialog>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include "studentdata.h"

namespace Ui {
class StudentInfo;
}

class StudentInfo : public QDialog
{
    Q_OBJECT

public:
    explicit StudentInfo(QWidget *parent = nullptr);
    ~StudentInfo();

    void setUsername(const QString &newUsername);

    void setToken(const QByteArray &newToken);

private:
    Ui::StudentInfo *ui;
    QString username;
    QByteArray token;
    QNetworkAccessManager *manager;

private slots:
    void btnStudentDataSlot();
    void btnStudentGradeSlot();
};

#endif // STUDENTINFO_H
