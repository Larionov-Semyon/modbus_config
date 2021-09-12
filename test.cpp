#include "test.h"

#include <QDebug>

//QList<int> list_totalVirtualMem1;

void memory(const QString &place){
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);
    DWORDLONG totalVirtualMem = memInfo.ullTotalPageFile;

    DWORDLONG virtualMemUsed = memInfo.ullTotalPageFile - memInfo.ullAvailPageFile;

    DWORDLONG totalPhysMem = memInfo.ullTotalPhys;
    DWORDLONG physMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;

    qDebug() << "-- " << place << " -----------";
    qDebug() << "Virtual Memory: " << totalVirtualMem / (1024*1024);
    qDebug() << "Virtual Used Memory: " << virtualMemUsed / (1024*1024);
    qDebug() << "Physical Memory: " << totalPhysMem / (1024*1024);
    qDebug() << "Physical Memory Used: " << physMemUsed / (1024*1024);
}

void MyWidget::list_memory(){
    qDebug() << "+";
    MEMORYSTATUSEX memInfo;
    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
    GlobalMemoryStatusEx(&memInfo);
    DWORDLONG totalVirtualMem = memInfo.ullTotalPageFile;

    DWORDLONG virtualMemUsed = memInfo.ullTotalPageFile - memInfo.ullAvailPageFile;

    DWORDLONG totalPhysMem = memInfo.ullTotalPhys;
    DWORDLONG physMemUsed = memInfo.ullTotalPhys - memInfo.ullAvailPhys;

    if (list_totalVirtualMem_1[list_totalVirtualMem_1.size() - 1] != totalVirtualMem / (1024*1024)){
        list_totalVirtualMem_1.append(totalVirtualMem / (1024*1024));
    }
    if (list_virtualMemUsed_1[list_virtualMemUsed_1.size() - 1] != virtualMemUsed / (1024*1024)){
        list_virtualMemUsed_1.append(virtualMemUsed / (1024*1024));
    }
    if (list_totalPhysMem_1[list_totalPhysMem_1.size() - 1] != totalPhysMem / (1024*1024)){
        list_totalPhysMem_1.append(totalPhysMem / (1024*1024));
    }
    if (list_physMemUsed_1[list_physMemUsed_1.size() - 1] != physMemUsed / (1024*1024)){
        list_physMemUsed_1.append(physMemUsed / (1024*1024));
    }
//    list_virtualMemUsed_1 << virtualMemUsed / (1024*1024);
//    list_totalPhysMem_1 << totalPhysMem / (1024*1024);
//    list_physMemUsed_1 << physMemUsed / (1024*1024);
}

void MyWidget::get_list_memory(){
    qDebug() << list_totalVirtualMem_1;
    qDebug() << list_virtualMemUsed_1;
    qDebug() << list_totalPhysMem_1;
    qDebug() << list_physMemUsed_1;
}




//Test::Test()
//{

//}

//void Test::any_file_conf(){
//    QString PATH = QFileDialog::getOpenFileName(nullptr, "Открыть конфигурационный файл...",
//                                                QDir::currentPath());
//    Conf *config = new Conf(PATH);
//    qDebug() << " +++ " << config->Mode;
//    for(int i = 0; i < config->Mode.length(); i++){
//        qDebug() << config->Mode[i] << " ------------ ";
//        Worker mode = Worker(config->Mode[i]);
//    }
//}

//void Test::test_worker(){
//    Worker *mode = new Worker("1 -- 2");
//    if (mode->readed == "Ошибка: Режим не прочитан") qDebug() << " + Yes";
//    else qDebug() << " - No";
////    qDebug() << mode->file_exe;
//    delete mode;

//    mode = new Worker("1 -- 2 --  -- 4 -- 5 -- 6");
//    if ((mode->readed == "True") & (mode->block == "") & (mode->file_exe == "6")) qDebug() << " + Yes";
//    else qDebug() << " - No";
//}

//void Test::test_conf_read(){ //тест чтения конф файла
//    Conf *file = new Conf(path + tests[0]);
//    if ( file->readed == "Ошибка: Файл не подходит для конфигурационого файла") qDebug() << " + Yes";
//    else qDebug() << " - No";
//    delete file;

//    file = new Conf(path + tests[1]);
//    if ( file->readed == "Конфиг файл не существует") qDebug() << " + Yes";
//    else qDebug() << " - No";
//    delete file;

//    file = new Conf(path + tests[2]);
//    qDebug() << file->readed;
//    if ( file->readed == "True") qDebug() << " + Yes";
//    else qDebug() << " - No";
//    delete file;

//    file = new Conf(path + tests[3]);
//    if ( (file->readed == "True") & (file->address == "end")) qDebug() << " + Yes";
//    else qDebug() << " - No";
//    delete file;
//}
