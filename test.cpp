#include "test.h"

Test::Test()
{

}

void Test::any_file_conf(){
    QString PATH = QFileDialog::getOpenFileName(nullptr, "Открыть конфигурационный файл...",
                                                QDir::currentPath());
    Conf *config = new Conf(PATH);
    qDebug() << " +++ " << config->Mode;
    for(int i = 0; i < config->Mode.length(); i++){
        qDebug() << config->Mode[i] << " ------------ ";
        Worker mode = Worker(config->Mode[i]);
    }
}

void Test::test_worker(){
    Worker *mode = new Worker("1 -- 2");
    if (mode->readed == "Ошибка: Режим не прочитан") qDebug() << " + Yes";
    else qDebug() << " - No";
//    qDebug() << mode->file_exe;
    delete mode;

    mode = new Worker("1 -- 2 --  -- 4 -- 5 -- 6");
    if ((mode->readed == "True") & (mode->block == "") & (mode->file_exe == "6")) qDebug() << " + Yes";
    else qDebug() << " - No";
}

void Test::test_conf_read(){ //тест чтения конф файла
    Conf *file = new Conf(path + tests[0]);
    if ( file->readed == "Ошибка: Файл не подходит для конфигурационого файла") qDebug() << " + Yes";
    else qDebug() << " - No";
    delete file;

    file = new Conf(path + tests[1]);
    if ( file->readed == "Конфиг файл не существует") qDebug() << " + Yes";
    else qDebug() << " - No";
    delete file;

    file = new Conf(path + tests[2]);
    qDebug() << file->readed;
    if ( file->readed == "True") qDebug() << " + Yes";
    else qDebug() << " - No";
    delete file;

    file = new Conf(path + tests[3]);
    if ( (file->readed == "True") & (file->address == "end")) qDebug() << " + Yes";
    else qDebug() << " - No";
    delete file;
}

void Test::memtest(){ // тест использования памяти
    Memory("Start test");
    MainMenu *w = new MainMenu;
    w->show();
    Memory("1");

    InfoWindow *infoWindow = new InfoWindow;
    infoWindow->show();
    w->close();
    Memory("2");

    infoWindow->close();
    Memory("3");

    QApplication::quit();
    delete infoWindow;
    delete w;
}

void Test::test_info_read(){ // тест чтения информ сообщений
    // right
    InfoParser* file = new InfoParser(path + tests[0]);
    QStringList list = file->read();

    if (list == QStringList({"", "key", "value", "key", "value", "key", "value", "key", "value"})){
        qDebug() << "YES. Test 1";
    }else{
        qDebug() << "No. Test 1";
    }
    delete file;

    // no exist
    file = new InfoParser(path + tests[1]);
    list = file->read();

    if (list == QStringList({"Файл закрыт для записи"})){
        qDebug() << "YES. Test 2";
    }else{
        qDebug() << "No. Test 2";
    }
    delete file;

    // bad file
    file = new InfoParser(path + tests[1]);
    list = file->read();

    if (list == QStringList({"Файл закрыт для записи"})){
        qDebug() << "YES. Test 2";
    }else{
        qDebug() << "No. Test 2";
    }
    delete file;
}

void Memory(const QString &place){
    ///
//    MEMORYSTATUSEX memInfo;
//    memInfo.dwLength = sizeof(MEMORYSTATUSEX);
//    GlobalMemoryStatusEx(&memInfo);
//    DWORDLONG totalVirtualMem = memInfo.ullTotalPageFile;

//    DWORDLONG virtualMemUsed = memInfo.ullTotalPageFile - memInfo.ullAvailPageFile;

//    qDebug() << place << totalVirtualMem << Qt::endl << virtualMemUsed << " -- " << memInfo.ullTotalPageFile - memInfo.ullAvailPageFile;
    ///
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
