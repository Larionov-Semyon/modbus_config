#include "file.h"

// Запись-чтение из файлов

Conf::Conf(const QString &filename):file(filename){// конструктор
    file.open(QIODevice::ReadOnly);
    if (!file.exists()){
        qWarning("Конфиг файл не существует");
        readed = QString("Конфиг файл не существует");
    }
    else{
        qDebug("Конфиг файл открыт");
        readed = read();
    }
}

Conf::~Conf(){
    file.close();
}


QString Conf::get_name_laba(){
    return name_laba;
};
QString Conf::get_serial_nom(){
    return serial_nom;
};
QString Conf::get_date(){
    return date;
};
QString Conf::get_version(){
    return version;
};
QString Conf::get_language(){
    return language;
};

QStringList Conf::get_lines(){
        // Создаем входящий поток, из которого будут считываться данные, и связываем его с нашим файлом
        QTextStream in(&file);

        in.setCodec(QTextCodec::codecForName("UTF-8"));

        QStringList list;
        // Считываем файл строка за строкой
        while (!in.atEnd()) { // метод atEnd() возвращает true, если в потоке больше нет данных для чтения
            QString line = in.readLine(); // метод readLine() считывает одну строку из потока
            list << line;
        }
        list.removeAll(QString(""));
        return list;
};

QString Conf::read(){
    QStringList list = get_lines();

    // проверка на пустой файл или недостаточное количество строк
    if (list == QStringList("")){
        qWarning("Ошибка: Файл пустой");
        return QString("Ошибка: Файл пустой");
    }
    else if ((readed == "") & (list.length() < head_len * 2)){
        qWarning("Ошибка: Файл не подходит для конфигурационого файла");
        return QString("Ошибка: Файл не подходит для конфигурационого файла");
    }

    QStringList::iterator it = list.begin();

    name_laba = set_str(*(++it));
    (++it);
    serial_nom = set_str(*(++it));
    (++it);
    date = set_str(*(++it));
    (++it);
    version = set_str(*(++it));
    (++it);
    language = set_str(*(++it));
    (++it);

    comport = set_str(*(++it));
    (++it);
    baudrate = set_str(*(++it));
    (++it);
    stopbits = set_str(*(++it));
    (++it);
    databits = set_str(*(++it));
    (++it);
    parity = set_str(*(++it));
    (++it);
    responsetime = set_str(*(++it));
    (++it);
    address = set_str(*(++it));


    QStringList _mode;
//    if (((it++) + 1) == list.end()){
//        return QStringList("ERROR");
//    }

    while (((it++) + 1) != list.end()){
        if (*it == "-----"){
            if (!_mode.isEmpty()){
                Mode << _mode.join(" -- ");
            }
            _mode = QStringList();
        }else{
            ++it;
            if (_mode.empty()){
                Mode_name << *(it);
            }
            _mode << *(it);
        }
    }
    Mode << _mode.join(" -- ");

    qDebug("Конфиг файл закрыт");
    file.close();
    return QString("True");
};

QString Conf::set_str(QString str){
    if (str == QString()){
        //qWarning("The empty place, where it is not necessary");
        return QString("None");
    }
    return str;
}

//-------------------------------------------------------

Worker::Worker(const QString &list){
    QStringList param = list.split(" -- ");

    if (param.length() != len){
        readed = "Ошибка: Режим не прочитан";
        qWarning("ERROR: Length MODE");
    }else{
        readed = "True";

        QStringList::iterator it = param.begin();

        // основные параметры
        name = *(it++);
        valible = *(it++);
        block = *(it++);
        outputs = *(it++);
        image = *(it++);
        file_exe = *(it++);
    }
}

Save_to_config::Save_to_config(const QString &filename):file(filename){
    if (file.open(QIODevice::WriteOnly)){

    }else{
        qWarning("Could not open file");
    }
}

Save_to_config::~Save_to_config(){
    file.close();
}

void Save_to_config::save_main_param(const QString &laba, const QString &serial, const QString &date,
                                     const QString &version, const QString &lang, const QString &com,
                                     const QString &baud, const QString &stop, const QString &data,
                                     const QString &parity, const QString &response, const QString &address){

    QTextStream out(&file);
    out.setCodec(QTextCodec::codecForName("UTF-8"));

//    out << QString("Данные настроек подключения к устройству управления") <<Qt::endl;
//    out << set_str(*setting) << Qt::endl << Qt::endl;

    out << QString("Название лаборатории") <<Qt::endl;
    out << set_str(laba) << Qt::endl << Qt::endl;

    out << QString("Серийный номер") <<Qt::endl;
    out << set_str(serial) << Qt::endl << Qt::endl;

    out << QString("Дата изготовления") <<Qt::endl;
    out << set_str(date) << Qt::endl << Qt::endl;

    out << QString("Версия ПО контроллера") <<Qt::endl;
    out << set_str(version) << Qt::endl << Qt::endl;

    out << QString("Язык") <<Qt::endl;
    out << set_str(lang) << Qt::endl << Qt::endl;

    // -----
    out << QString("COM порт") <<Qt::endl;
    out << set_str(com) << Qt::endl << Qt::endl;

    out << QString("Baud rate") <<Qt::endl;
    out << set_str(baud) << Qt::endl << Qt::endl;

    out << QString("Stop bits") <<Qt::endl;
    out << set_str(stop) << Qt::endl << Qt::endl;

    out << QString("Data bits") <<Qt::endl;
    out << set_str(data) << Qt::endl << Qt::endl;

    out << QString("Parity") <<Qt::endl;
    out << set_str(parity) << Qt::endl << Qt::endl;

    out << QString("Response time") <<Qt::endl;
    out << set_str(response) << Qt::endl << Qt::endl;

    out << QString("Adress") <<Qt::endl;
    out << set_str(address) << Qt::endl << Qt::endl;
}

void Save_to_config::save_mode(const QString &name, const QString &valible, const QString &block,
                               const QString &output, const QString &image, const QString &file_exe){
    QTextStream out(&file);
    out.setCodec(QTextCodec::codecForName("UTF-8"));

    out << QString("-----") << Qt::endl;
    out << QString("Название режима") << Qt::endl;
    out << set_str(name) << Qt::endl << Qt::endl;

    out << QString("Доступность в данной комплектации") << Qt::endl;
    out << set_str(valible) << Qt::endl << Qt::endl;

    out << QString("Перечень проверяемых блокировок") << Qt::endl;
    out << set_str(block) << Qt::endl << Qt::endl;

    out << QString("Перечень проверяемых выходов") << Qt::endl;
    out << set_str(output) << Qt::endl << Qt::endl;

    out << QString("Имя файла изображения") << Qt::endl;
    out << set_str(image) << Qt::endl << Qt::endl;

    out << QString("Путь до файла стороннего приложения") << Qt::endl;
    out << set_str(file_exe) << Qt::endl << Qt::endl;
}

QString Save_to_config::set_str(QString str){
    if (str == QString()){
        //qWarning("The empty place, where it is not necessary");
        return QString("None");
    }
    return str;
}

// ----------------------------------------------

InfoParser::InfoParser(const QString &filename):file(filename){}

InfoParser::~InfoParser(){
    file.close();
}

QStringList InfoParser::read(){
    if (!file.open(QIODevice::ReadOnly)){
        qWarning("Файл закрыт для записи");
        return QStringList("Файл закрыт для записи");
    }
    else if (!file.exists()){
        qWarning("Файл не существует");
        return QStringList("Файл не существует");
    }
    else{
        qDebug("Файл открыт");
        return get_lines();
    }
};

QStringList InfoParser::get_lines(){
        // Создаем входящий поток, из которого будут
        //считываться данные, и связываем его с нашим файлом
        QTextStream in(&file);

        in.setCodec(QTextCodec::codecForName("UTF-8"));

        QStringList list;
        // Считываем файл строка за строкой
        while (!in.atEnd()) { // метод atEnd() возвращает true,
                              //если в потоке больше нет данных для чтения
            QString line = in.readLine(); // метод readLine() считывает одну строку из потока
            list << line;
        }
        list.removeAll(QString(""));

        if (list.count() % 2 == 0)
            return QStringList("") << list;
        else
            return QStringList("Ошибка в прочитанных данных. Не совпадение ключ-значение");
};


bool InfoParser::write(){
    if (file.open(QIODevice::WriteOnly)){
        qDebug("Файл открыт для записи");
        return true;
    }else{
        qWarning("Ошибка открытия файла для записи");
        return false;
    }
}

void InfoParser::set_lines(const QString &key, const QString &value){
    QTextStream out(&file);
    out.setCodec(QTextCodec::codecForName("UTF-8"));
    out << key << Qt::endl;
    out << value << Qt::endl << Qt::endl;
}

