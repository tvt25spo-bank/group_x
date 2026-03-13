#include "grades.h"
#include "ui_grades.h"

Grades::Grades(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Grades)
{
    ui->setupUi(this);
}

Grades::~Grades()
{
    delete ui;
}

void Grades::setGradeList(const QVector<Grade> &newGradeList)
{
    gradeList = newGradeList;

    // Luo model: rivit, sarakkeet, parent
    auto *tableModel = new QStandardItemModel(gradeList.size(), 3, this);

    // Aseta sarakkeiden otsikot
    tableModel->setHorizontalHeaderLabels({ tr("kurssi"), tr("arvosana"), tr("suoritus pvm") });

    // Täytä taulukko gradeList:stä
    for (int row = 0; row < gradeList.size(); ++row) {
        const Grade &grade = gradeList[row];
        tableModel->setItem(row, 0, new QStandardItem(grade.course_name));
        tableModel->setItem(row, 1, new QStandardItem(QString::number(grade.grade)));
        tableModel->setItem(row, 2, new QStandardItem(grade.grade_date));
    }

    // Aseta model tableView:lle
    ui->tableGrades->setModel(tableModel);

    // Piilota rivinumerot vasemmalta (optional)
    ui->tableGrades->verticalHeader()->setVisible(false);

    // Sovita sarakkeiden leveys sisällön mukaan
    ui->tableGrades->resizeColumnsToContents();

}
