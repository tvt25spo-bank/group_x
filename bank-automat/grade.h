#ifndef GRADE_H
#define GRADE_H

#include <QString>
#include <qjsonobject.h>

class Grade
{
public:
    QString course_name;
    int grade;
    QString grade_date;

    static Grade mapJson(const QJsonObject &json);
};

#endif // GRADE_H
