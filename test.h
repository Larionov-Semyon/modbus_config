#ifndef TEST_H
#define TEST_H
#pragma once

#include "windows.h"
#include "psapi.h"
#include "TCHAR.h"

#include <QString>
#include <QStringList>
#include <QDesktopServices>
#include <QApplication>
#include <QTimer>

#include "configWindow/mainwindow.h"

void memory(const QString&);
void list_memory(const QString&);
void get_list_memory();


class MyWidget : public QWidget
{
    Q_OBJECT

public:
    MyWidget():i(0)
    {
        timer = new QTimer(this);
        QObject::connect(timer, SIGNAL(timeout()), this, SLOT(list_memory()));
        timer->start(1000); //time specified in ms
    }
    ~MyWidget(){
        get_list_memory();
    }

public slots:
    void list_memory();

private:
    QTimer *timer;
    void get_list_memory();
    QList<DWORDLONG> list_totalVirtualMem_1 = {0};
    QList<DWORDLONG> list_virtualMemUsed_1 = {1};
    QList<DWORDLONG> list_totalPhysMem_1 = {2};
    QList<DWORDLONG> list_physMemUsed_1 = {3};

protected:
    unsigned int i;
};


#endif // TEST_H
