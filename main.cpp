#include "mainmenu.h"
//#include "test.h"

#include <QApplication>

int main(int argc, char *argv[])
{
//    Memory("Start");

    QApplication a(argc, argv);

//    Test *test = new Test;
//    test->any_file_conf();
//    delete test;

    MainMenu w;
    w.show();

    return a.exec();
}
