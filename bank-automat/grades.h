#ifndef GRADES_H
#define GRADES_H

#include "grade.h"

#include <QDialog>
#include <QStandardItemModel>

namespace Ui {
class Grades;
}

class Grades : public QDialog
{
    Q_OBJECT

public:
    explicit Grades(QWidget *parent = nullptr);
    ~Grades();

    void setGradeList(const QVector<Grade> &newGradeList);

private:
    Ui::Grades *ui;
    QVector<Grade> gradeList;
};

#endif // GRADES_H
