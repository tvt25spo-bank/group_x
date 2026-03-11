#ifndef STUDENTINFO_H
#define STUDENTINFO_H

#include <QDialog>

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
};

#endif // STUDENTINFO_H
