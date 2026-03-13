#ifndef STUDENTDATA_H
#define STUDENTDATA_H

#include <QDialog>

namespace Ui {
class StudentData;
}

class StudentData : public QDialog
{
    Q_OBJECT

public:
    explicit StudentData(QWidget *parent = nullptr);
    ~StudentData();
    void SetData(QString, QString, QString, QString);

private:
    Ui::StudentData *ui;
};

#endif // STUDENTDATA_H
