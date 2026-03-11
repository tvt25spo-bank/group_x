#include "mainwindow.h"
#include "studentinfo.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->btnLogin, &QPushButton::clicked, this, &MainWindow::loginSlot);
    manager=new QNetworkAccessManager(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loginSlot()
{
    QString username=ui->textUsername->text();
    QString password=ui->textPassword->text();
    QString url=Environment::GetBaseUrl()+"/login";
    QNetworkRequest request(url);request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QJsonObject loginData;
    loginData.insert("username",username);
    loginData.insert("password",password);
    QJsonDocument jsonDoc(loginData);
    QNetworkReply *reply=manager->post(request,jsonDoc.toJson());

    connect(reply, &QNetworkReply::finished, this,[reply,username, this](){
        QByteArray response_data=reply->readAll();
        int status = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        qDebug()<<"koodi="<<status;
        if(status==0 || status==500){
            ui->labelInfo->setText("Virhe tietoliikenneyhteydessä");
        }
        else if(status==400 || status==401){
            ui->labelInfo->setText("Tunnus ja salasana eivät täsmää");
        }
        else{
            StudentInfo *objStudentInfo=new StudentInfo(this);
            objStudentInfo->setUsername(username);
            QJsonDocument jDoc=QJsonDocument::fromJson(response_data);
            QJsonObject json_obj = jDoc.object();
            QByteArray token="Bearer "+json_obj["token"].toString().toUtf8();
            objStudentInfo->setToken(token);
            objStudentInfo->show();
        }

        reply->deleteLater();
    });
}
