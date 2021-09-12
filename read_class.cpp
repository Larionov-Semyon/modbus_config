#include "read_class.h"
#include <fstream>
#include <string>

//#include <QDebug>
#include <QFile>
#include <QTextCodec>
#include <QTextStream>
#include <iostream>

QString Sets::set_str(QString str)
{
    if (str == QString()) {
        //qWarning("The empty place, where it is not necessary");
        return QString("None");
    }
    return str;
}

QStringList Sets::get_lines(QFile* file)
{

    // Создаем входящий поток, из которого будут считываться данные, и связываем его с нашим файлом
    QTextStream in(file);

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

QStringList Butts::get_lines(QFile* file)
{
    // Создаем входящий поток, из которого будут считываться данные, и связываем его с нашим файлом
    QTextStream in(file);

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

QStringList Inf_Msg::get_lines(QFile* file)
{
    // Создаем входящий поток, из которого будут считываться данные, и связываем его с нашим файлом
    QTextStream in(file);

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

QStringList Mode_chan::get_lines(QFile* file)
{

    //   QFile fil("D:\\config_file.txt");
    // Создаем входящий поток, из которого будут считываться данные, и связываем его с нашим файлом
    QTextStream in(file);

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

QString Sets::read(QString file_name)
{
    //    file.close();
    //cоздаем объект
    //    file = file_name;
    QFile file(file_name);
    file.open(QIODevice::ReadOnly);

    QStringList list = get_lines(&file);
    //    qDebug() << list << "---";
    QTextStream out(stdout);

    //cоздаем объект
    //    QFile file("D:\\config_file.txt");

    //открываем файл в режиме чтения
    if (0) {
        qWarning("Cannot open file for reading"); // если файл не найден, то выводим предупреждение и завершаем выполнение программы
        return 0;
    }

    // Создаем входящий поток, из которого будут считываться данные, и связываем его с нашим файлом
    QTextStream in(&file);
    QStringList::iterator it = list.begin();
    QStringList _mode;
    int count_ = 0;

    //    while (!in.atEnd())
    while ((it) != list.end()) {
        //       return 0;

        if (*it == "-----") {
            count_++;
        }
        if (count_ == 0) {
            if (*it == "name") {
                //           it++;
                lab_name = *(++it);
            }
            if (*it == "serial_number") {
                it++;
                serial_num = *it;
            }
            if (*it == "date_of_production") {
                it++;
                product_date = *it;
            }
            if (*it == "controller_version") {
                it++;
                vers = *it;
            }
            if (*it == "default_language") {
                it++;
                language = *it;
            }
            if (*it == "abbreviation") {
                it++;
                abbrev = *it;
            }
            if (*it == "add_language") { //изменена строка с name на add_language
                it++;
                lang_name = *it;
            }
        }
        //-------------------------------------------
        if (count_ == 1) {
            if (*it == "com_port") {
                it++;
                com_port = *it;
            }
            if (*it == "baud_rate") {
                it++;
                baud_rate = *it;
            }
            if (*it == "stop_bits") {
                it++;
                stop_bits = *it;
            }
            if (*it == "data_bits") {
                it++;
                data_bits = *it;
            }
            if (*it == "parity") {
                it++;
                parity = *it;
            }
            if (*it == "response_time") {
                it++;
                response_time = *it;
            }
            if (*it == "adress") {
                it++;
                adress = *it;
            }
        }
        it++;
    }

    QStringList::iterator itt = list.begin();
    count_ = 0;
    while ((itt) != list.end()) {
        if (*itt == "-----") {
            count_++;
        }

        if (count_ >= 4) {
            if (*itt == "-----") {
                if (!_mode.isEmpty()) {
                    Mode << _mode.join(" -- ");
                    //qDebug() << "1" << _mode;
                }
                _mode = QStringList();
            } else {
                if (_mode.empty()) {
                    itt++;
                    itt++;
                    Mode_name << *(itt);
                }
            }
            _mode << *(itt);
        }
        itt++;
    }

    Mode << _mode.join(" -- ");

    //    qDebug("Конфиг файл закрыт");

    // Закрываем файл
    file.close();
    return QString("True");
}

//----------------------------------------------------------------------------

QString Butts::read(QString file_name)
{
    //cоздаем объект
    QFile file(file_name);
    file.open(QIODevice::ReadOnly);
    //    qDebug() << list << "---";
    QTextStream out(stdout);
    //открываем файл в режиме чтения
    if (0) {
        qWarning("Cannot open file for reading"); // если файл не найден, то выводим предупреждение и завершаем выполнение программы
        return 0;
    }

    QStringList list = get_lines(&file);

    // Создаем входящий поток, из которого будут считываться данные, и связываем его с нашим файлом
    QTextStream in(&file);

    QStringList::iterator it = list.begin();
    QStringList _mode;
    int count_ = 0;

    while ((it) != list.end()) {
        QString line = in.readLine();
        if (*it == "-----") {
            count_++;
        }

        //==========При замене порядка заполнения файла заменить на 2==========//
        if (count_ == 2) {
            if (*it == "about_labor") {
                it++;
                it++;
                about_lab = *it;
            }
            if (*it == "start") {
                it++;
                it++;
                b_start = *it;
            }
            if (*it == "stop") {
                it++;
                it++;
                b_stop = *it;
            }
            //-------------------------------------------
            if (*it == "choice_of_mode") {
                it++;
                it++;
                mode_choice = *it;
            }
            if (*it == "scheme_of_connection") {
                it++;
                it++;
                connects = *it;
            }
            if (*it == "blocks") {
                it++;
                it++;
                blocs = *it;
            }
            if (*it == "clues") {
                it++;
                it++;
                clues = *it;
            }
            if (*it == "name") {
                it++;
                it++;
                tr_name = *it;
            }
            if (*it == "serial_number") {
                it++;
                it++;
                tr_serial_num = *it;
            }
            if (*it == "date_of_production") {
                it++;
                it++;
                tr_date_production = *it;
            }
            if (*it == "controller_version") {
                it++;
                it++;
                tr_control_vers = *it;
            }
            if (*it == "default_language") {
                it++;
                it++;
                tr_default_lang = *it;
            }
            if (*it == "device_is_ready") {
                it++;
                it++;
                willingness = *it;
            }
            if (*it == "work") {
                it++;
                it++;
                b_work = *it;
            }
            //-------------------------------------------
        }
        it++;
    }

    // Закрываем файл
    file.close();
    return QString("True");
}

//----------------------------------------------------------------------------

QString Inf_Msg::read(QString file_name)
{
    //cоздаем объект
    QFile file(file_name);
    file.open(QIODevice::ReadOnly);

    QTextStream out(stdout);

    //открываем файл в режиме чтения
    if (0) {
        qWarning("Cannot open file for reading"); // если файл не найден, то выводим предупреждение и завершаем выполнение программы
        return 0;
    }

    QStringList list = get_lines(&file);

    // Создаем входящий поток, из которого будут считываться данные, и связываем его с нашим файлом
    QTextStream in(&file);

    QStringList::iterator it = list.begin();
    QStringList _mode;

    while ((it) != list.end()) {

        if (*it == "VOLTAGE") {
            it++;
            it++;
            voltage = *it;
            it++;
            it++;
            voltage_en = *it;
            it++;
            it++;
            voltage_add = *it;
        }
        if (*it == "CURRENT") {
            it++;
            it++;
            current = *it;
            it++;
            it++;
            current_en = *it;
            it++;
            it++;
            current_add = *it;
        }
        if (*it == "DOORS") {
            it++;
            it++;
            doors = *it;
            it++;
            it++;
            doors_en = *it;
            it++;
            it++;
            doors_add = *it;
        }
        if (*it == "EMERGENCY_BUTTON") {
            it++;
            it++;
            b_emrg = *it;
            it++;
            it++;
            b_emrg_en = *it;
            it++;
            it++;
            b_emrg_add = *it;
        }
        if (*it == "GND") {
            it++;
            it++;
            gnd = *it;
            it++;
            it++;
            gnd_en = *it;
            it++;
            it++;
            gnd_add = *it;
        }
        if (*it == "WORK_GND") {
            it++;
            it++;
            work_gnd = *it;
            it++;
            it++;
            work_gnd_en = *it;
            it++;
            it++;
            work_gnd_add = *it;
        }
        if (*it == "NO_ERROR") {
            it++;
            it++;
            msg_no_error = *it;
            it++;
            it++;
            msg_no_error_en = *it;
            it++;
            it++;
            msg_no_error_add = *it;
        }
        if (*it == "COM_CONNECTION_ERROR") {
            it++;
            it++;
            msg_com_connect_err = *it;
            it++;
            it++;
            msg_com_connect_err_en = *it;
            it++;
            it++;
            msg_com_connect_err_add = *it;
        }
        if (*it == "INVALID_MODBUS_ADDRESS") {
            it++;
            it++;
            msg_invalid_addr = *it;
            it++;
            it++;
            msg_invalid_addr_en = *it;
            it++;
            it++;
            msg_invalid_addr_add = *it;
        }
        if (*it == "INVALID_INPUT_DATA") {
            it++;
            it++;
            msg_invalid_input = *it;
            it++;
            it++;
            msg_invalid_input_en = *it;
            it++;
            it++;
            msg_invalid_input_add = *it;
        }
        if (*it == "INVALID_MODBUS_DATA") {
            it++;
            it++;
            msg_invalid_modbus = *it;
            it++;
            it++;
            msg_invalid_modbus_en = *it;
            it++;
            it++;
            msg_invalid_modbus_add = *it;
        }
        if (*it == "UNKNOWN_ERROR") {
            it++;
            it++;
            msg_unknown = *it;
            it++;
            it++;
            msg_unknown_en = *it;
            it++;
            it++;
            msg_unknown_add = *it;
        }
        if (*it == "INVALID_SERIAL_NUMBER") {
            it++;
            it++;
            msg_serial = *it;
            it++;
            it++;
            msg_serial_en = *it;
            it++;
            it++;
            msg_serial_add = *it;
        }
        if (*it == "INVALID_CONTROLLER_VERSION") {
            it++;
            it++;
            msg_version = *it;
            it++;
            it++;
            msg_version_en = *it;
            it++;
            it++;
            msg_version_add = *it;
        }

        it++;
    }

    //     qDebug("Конфиг файл закрыт");

    // Закрываем файл
    file.close();
    return QString("True");
}

//--------------Чтение режимов----------------------

Mode_chan::Mode_chan(QString file_name, QString list)
{
    QStringList param = list.split(" -- ");

    if (param.length() != len) {
        readed = "Ошибка: Режим не прочитан";
        qWarning("ERROR: Length MODE");
    } else {
        readed = "True";

        QFile file(file_name);
        file.open(QIODevice::ReadOnly);
        QStringList list = get_lines(&file);
        QStringList::iterator iti = list.begin();
        while (iti != list.end()) {
            if (*iti == "default_language") {
                iti++;
                language = *iti;
                //qDebug() << *iti << "---";
            }
            iti++;
        }
        file.close();

        QStringList::iterator it = param.begin(); //замена list на param
        while ((it) != param.end()) {

            // основные параметры
            if (*it == "name") {
                it++;
                it++;
                m_name = *it;
                it++;
                it++;
                m_name_en = *it;
                it++;
                it++;
                m_name_add = *it;
            }
            if (*it == "clue") {
                it++;
                it++;
                clue = *it;
                it++;
                it++;
                clue_en = *it;
                it++;
                it++;
                clue_add = *it;
            }

            //--------------------------------------------------------
            if (*it == "enable") {
                it++;
                m_enable = *it;
            }
            if (*it == "modbus_outputs") {
                it++;
                modbus_out = *it;
            }
            if (*it == "modbus_inputs") {
                it++;
                modbus_in = *it;
            }
            if (*it == "image_path") {
                it++;
                img_path = *it;
            }
            if (*it == "exe_path") {
                it++;
                exe_path = *it;
            }

            it++;
        }
    }
    // Закрываем файл
    //qDebug() << exe_path;
    file.close();
}

//--------------Запись в файл-----------------------

Save_to_config1::Save_to_config1(QString filename)
    : file(filename)
{
    if (file.open(QIODevice::WriteOnly)) {

    } else {
        qWarning("Could not open file");
    }
}

Save_to_config1::~Save_to_config1()
{
    file.close();
}

void Save_to_config1::save_main_param(QString* laba,
    QString* serial, QString* date,
    QString* version, QString* lang,
    QString* com, QString* baud, QString* stop, QString* data,
    QString* parity, QString* response, QString* address,
    QString* add_lang, QString* abbrev)
{

    QTextStream out(&file);
    out.setCodec(QTextCodec::codecForName("UTF-8"));

    out << QString("name") << Qt::endl;
    out << set_str(*laba) << Qt::endl
        << Qt::endl;

    out << QString("serial_number") << Qt::endl;
    out << set_str(*serial) << Qt::endl
        << Qt::endl;

    out << QString("date_of_production") << Qt::endl;
    out << set_str(*date) << Qt::endl
        << Qt::endl;

    out << QString("controller_version") << Qt::endl;
    out << set_str(*version) << Qt::endl
        << Qt::endl;

    out << QString("default_language") << Qt::endl;
    out << set_str(*lang) << Qt::endl
        << Qt::endl;

    out << QString("add_language") << Qt::endl;
    out << set_str(*add_lang) << Qt::endl
        << Qt::endl;

    out << QString("abbreviation") << Qt::endl;
    out << set_str(*abbrev) << Qt::endl
        << Qt::endl;

    // -----
    out << QString("-----") << Qt::endl;
    out << QString("com_port") << Qt::endl;
    out << set_str(*com) << Qt::endl
        << Qt::endl;

    out << QString("baud_rate") << Qt::endl;
    out << set_str(*baud) << Qt::endl
        << Qt::endl;

    out << QString("stop_bits") << Qt::endl;
    out << set_str(*stop) << Qt::endl
        << Qt::endl;

    out << QString("data_bits") << Qt::endl;
    out << set_str(*data) << Qt::endl
        << Qt::endl;

    out << QString("parity") << Qt::endl;
    out << set_str(*parity) << Qt::endl
        << Qt::endl;

    out << QString("response_time") << Qt::endl;
    out << set_str(*response) << Qt::endl
        << Qt::endl;

    out << QString("adress") << Qt::endl;
    out << set_str(*address) << Qt::endl
        << Qt::endl;
}

void Save_to_config1::save_btts(QStringList* source)
{
    QTextStream out(&file);
    out.setCodec(QTextCodec::codecForName("UTF-8"));

    //    out << QString("Данные настроек подключения к устройству управления") <<Qt::endl;
    //    out << set_str(*setting) << Qt::endl << Qt::endl;

    out << QString("-----") << Qt::endl;

    QStringList text = { "about_labor", "start", "stop", "choice_of_mode",
        "scheme_of_connection", "blocks", "clues",
        "name", "serial_number", "date_of_production", "controller_version", "default_language", "device_is_ready", "work" };

//    qDebug() << text.length() << source->length();

    int i = 0;
    QStringList::iterator it1, it2;
    for (it1 = source->begin(), it2 = source->end(); it1 != it2; it1++) {
//        qDebug() << *it1;
        out << QString(text[i++]) << Qt::endl;
        out << QString("Add") << Qt::endl;
        out << set_str(*it1) << Qt::endl
            << Qt::endl;
    }
}

void Save_to_config1::save_inf_msg(QStringList* source)
{
    QTextStream out(&file);
    out.setCodec(QTextCodec::codecForName("UTF-8"));

    out << QString("-----") << Qt::endl;

    QStringList text = { "VOLTAGE", "CURRENT", "DOORS", "EMERGENCY_BUTTON",
        "GND", "WORK_GND", "NO_ERROR", "COM_CONNECTION_ERROR",
        "INVALID_MODBUS_ADDRESS", "INVALID_INPUT_DATA",
        "INVALID_MODBUS_DATA", "UNKNOWN_ERROR", "INVALID_SERIAL_NUMBER", "INVALID_CONTROLLER_VERSION" };

    //    qDebug() << text.length() << source->length();

    int i = 0;
    QStringList::iterator it1, it2;
    for (it1 = source->begin(), it2 = source->end(); it1 + 3 <= it2; it1 += 3) {
        //        qDebug() << *it1;
        out << QString(text[i++]) << Qt::endl;
        out << QString("RU") << Qt::endl;
        out << set_str(*it1) << Qt::endl;
        out << QString("EN") << Qt::endl;
        out << set_str(*(it1 + 1)) << Qt::endl;
        out << QString("Add") << Qt::endl;
        out << set_str(*(it1 + 2)) << Qt::endl
            << Qt::endl;
    }
    //    qDebug() << "stop";
}

void Save_to_config1::save_mode(QString* name_ru, QString* name_en, QString* name_add, QString* valible, QString* m_outputs,
    QString* m_inputs, QString* img_path, QString* exe_path, QString* clue_ru, QString* clue_en, QString* clue_add)
{
    QTextStream out(&file);
    out.setCodec(QTextCodec::codecForName("UTF-8"));

    out << QString("-----") << Qt::endl;
    out << QString("name") << Qt::endl;
    out << QString("RU") << Qt::endl;
    out << set_str(*name_ru) << Qt::endl;
    out << QString("EN") << Qt::endl;
    out << set_str(*name_en) << Qt::endl;
    out << QString("Add") << Qt::endl;
    out << set_str(*name_add) << Qt::endl
        << Qt::endl;
    out << QString("enable") << Qt::endl;
    out << set_str(*valible) << Qt::endl
        << Qt::endl;

    out << QString("modbus_outputs") << Qt::endl;
    out << set_str(*m_outputs) << Qt::endl
        << Qt::endl;

    out << QString("modbus_inputs") << Qt::endl;
    out << set_str(*m_inputs) << Qt::endl
        << Qt::endl;

    out << QString("image_path") << Qt::endl;
    out << set_str(*img_path) << Qt::endl
        << Qt::endl;

    out << QString("exe_path") << Qt::endl;
    out << set_str(*exe_path) << Qt::endl
        << Qt::endl;

    out << QString("clue") << Qt::endl;
    out << QString("RU") << Qt::endl;
    out << set_str(*clue_ru) << Qt::endl;
    out << QString("EN") << Qt::endl;
    out << set_str(*clue_en) << Qt::endl;
    out << QString("Add") << Qt::endl;
    out << set_str(*clue_add) << Qt::endl
        << Qt::endl;
}

QString Save_to_config1::set_str(QString str)
{
    if (str == QString()) {
        //qWarning("The empty place, where it is not necessary");
        return QString("-");
    }
    return str.simplified();
}
