#include "environment.h"
#include "grade.h"
#include "grades.h"
#include "studentinfo.h"
#include "ui_studentinfo.h"

StudentInfo::StudentInfo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StudentInfo)
{
    ui->setupUi(this);
    manager=new QNetworkAccessManager(this);
    connect(ui->btnMyData, &QPushButton::clicked, this, &StudentInfo::btnStudentDataSlot);
    connect(ui->btnGrades, &QPushButton::clicked, this, &StudentInfo::btnStudentGradeSlot);

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

void StudentInfo::btnStudentDataSlot()
{
    QString url=Environment::GetBaseUrl()+"/student/"+this->username;
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(QByteArray("Authorization"),(token));
    QNetworkReply *reply = manager->get(request);
    connect(reply, &QNetworkReply::finished, [this, reply](){
        // Tarkistetaan verkkovirheet
        if (reply->error() != QNetworkReply::NoError) {
            qWarning() << "Network error:" << reply->errorString();
            reply->deleteLater();
            return;
        }

        QByteArray response_data=reply->readAll();
        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonObject json_obj = json_doc.object();
        StudentData *objStudentData=new StudentData(this);
        objStudentData->SetData(json_obj["username"].toString(),json_obj["fname"].toString(), json_obj["lname"].toString(), json_obj["email"].toString());
        objStudentData->show();

        //qDebug()<<response_data;

        reply->deleteLater();
    });
}

void StudentInfo::btnStudentGradeSlot()
{
    QString url=Environment::GetBaseUrl()+"/grade/"+this->username;
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    request.setRawHeader(QByteArray("Authorization"),(token));
    QNetworkReply *reply = manager->get(request);
    connect(reply, &QNetworkReply::finished, [this, reply](){
        // Tarkistetaan verkkovirheet
        if (reply->error() != QNetworkReply::NoError) {
            qWarning() << "Network error:" << reply->errorString();
            reply->deleteLater();
            return;
        }

        QByteArray response_data=reply->readAll();
        QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
        QJsonArray json_array = json_doc.array();

        QVector<Grade> gradeList;
        for (const QJsonValue &value : json_array) {
            if (value.isObject()) {
                Grade grade = Grade::mapJson(value.toObject());
                gradeList.append(grade);
            }
        }

        Grades *objGrades=new Grades(this);
        objGrades->setGradeList(gradeList);
        objGrades->show();

        reply->deleteLater();
    });
}
