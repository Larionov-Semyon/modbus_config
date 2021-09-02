#include "mainmenu.h"
//#include "test.h"
#include "configWindow/mainwindow.h"
#include "infoWindow/infowindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
//    Memory("Start");

    QApplication a(argc, argv);

//    Test *test = new Test;
//    test->any_file_conf();
//    delete test;

    MainWindow w;
    w.show();

//    InfoWindow q;
//    q.show();
    return a.exec();
}
