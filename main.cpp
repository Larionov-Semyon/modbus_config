#include "configWindow/mainwindow.h"
#include "test.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    MyWidget test;

    MainWindow w;
    w.show();

    return a.exec();
}
