#ifndef READ_CLASS_H
#define READ_CLASS_H

#pragma once

//#include <QDebug>
#include <QFile>
#include <QTextCodec>
#include <QTextStream>
#include <iostream>

class read_class {
public:
    read_class();
};

class Sets {
public:
    QFile file;

    QString language; // язык
    QString readed = "True"; // True - False

    QString read(QString); // чтение файла в класс (return get_list()) - или return <name error>
    QStringList get_lines(QFile*);
    //private:
    QString lab_name;
    QString serial_num;
    QString product_date;
    QString vers;

    QString set_str(QString);

    QStringList Mode_name; // название режимов
    QStringList Mode; // конфигурация режимов в виде строки вида <<str> -- <str>>

    QString com_port;
    QString baud_rate;
    QString stop_bits;
    QString data_bits;
    QString parity;
    QString response_time;
    QString adress;
    QString abbrev;
    QString lang_name;
};

class Butts {
public:
    QString read(QString);
    QStringList get_lines(QFile*);
    QString set_str(QString);
    //    explicit Butts(QString);

    QFile file;
    QString lang_name;

    QString abbrev;
    QString about_lab;
    QString b_start;
    QString b_stop;
    QString mode_choice;
    QString connects;
    QString blocs;
    QString clues;
    QString tr_name;
    QString tr_serial_num;
    QString tr_date_production;
    QString tr_control_vers;
    QString tr_default_lang;
    QString willingness;
    QString b_work;
};

class Inf_Msg {
public:
    QFile file;
    QString language;

    QString voltage;
    QString current;
    QString doors;
    QString b_emrg;
    QString gnd;
    QString work_gnd;
    QString msg_no_error;
    QString msg_com_connect_err;
    QString msg_invalid_addr;
    QString msg_invalid_input;
    QString msg_invalid_modbus;
    QString msg_unknown;
    QString msg_serial;
    QString msg_version;

    QString voltage_en;
    QString current_en;
    QString doors_en;
    QString b_emrg_en;
    QString gnd_en;
    QString work_gnd_en;
    QString msg_no_error_en;
    QString msg_com_connect_err_en;
    QString msg_invalid_addr_en;
    QString msg_invalid_input_en;
    QString msg_invalid_modbus_en;
    QString msg_unknown_en;
    QString msg_serial_en;
    QString msg_version_en;

    QString voltage_add;
    QString current_add;
    QString doors_add;
    QString b_emrg_add;
    QString gnd_add;
    QString work_gnd_add;
    QString msg_no_error_add;
    QString msg_com_connect_err_add;
    QString msg_invalid_addr_add;
    QString msg_invalid_input_add;
    QString msg_invalid_modbus_add;
    QString msg_unknown_add;
    QString msg_serial_add;
    QString msg_version_add;

    QString read(QString);
    QStringList get_lines(QFile*);
};

class Mode_chan {
public:
    QFile file;
    QString language;

    const int len = 25; //change from 7 to 25
    QString readed = "True";

    QString m_name;
    QString m_enable;
    QString modbus_out;
    QString modbus_in;
    QString img_path;
    QString exe_path;
    QString clue;

    QString m_name_en;
    QString clue_en;

    QString m_name_add;
    QString clue_add;

    QString read(QString);
    QStringList get_lines(QFile*);

    explicit Mode_chan(QString, QString);
};

class Save_to_config1 {
public:
    QFile file;

    QString setting;
    QString laba;
    QString serial;
    QString date;
    QString version;
    QString language;

    explicit Save_to_config1(QString);
    ~Save_to_config1();

    void save_main_param(QString*, QString*, QString*, QString*, QString*, QString*,
        QString*, QString*, QString*, QString*, QString*, QString*,
        QString*, QString*);
    void save_mode(QString*, QString*, QString*, QString*, QString*, QString*, QString*, QString*, QString*, QString*, QString*);

    void save_inf_msg(QStringList*);
    void save_btts(QStringList*);

private:
    QString set_str(QString); // Замена пустой строки на None
};
#endif // READ_CLASS_H
