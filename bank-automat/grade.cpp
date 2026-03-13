#include "grade.h"


Grade Grade::mapJson(const QJsonObject &json)
{
    Grade grade;
    grade.course_name=json["course_name"].toString();
    grade.grade=json["grade"].toInt();
    grade.grade_date=json["grade_date"].toString();

    return grade;
}
