#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file(":/style.qss");
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        a.setStyleSheet(file.readAll());
    }

    MainWindow w;
    w.show();
    return a.exec();
}
