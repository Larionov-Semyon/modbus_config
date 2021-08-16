#ifndef ASS_H
#define ASS_H

#pragma once

#include <QFile>
#include <QTextStream>
#include <QTextCodec>
#include <iostream>


class Conf
{
public:
    QFile file;

    QString get_name_laba();
    QString get_serial_nom();
    QString get_date();
    QString get_version();
    QString get_language();

    QString comport;
    QString baudrate;
    QString stopbits;
    QString databits;
    QString parity;
    QString responsetime;
    QString address;

    const int head_len = 12;

    QString readed = ""; // True - False
    QStringList Mode_name; // название режимов
    QStringList Mode; // конфигурация режимов <<str> -- <str>>

    explicit Conf(const QString&); // конструктор
    ~Conf();

    QString read(); // чтение файла в класс (return get_list()) - или return <name error>

private:
    //head
    QString setting;
    QString name_laba;
    QString serial_nom;
    QString date;
    QString version;
    QString language;

     QStringList get_lines(); // чтение файла -- <список строк>
     QString set_str(QString); // Замена пустой строки на None
};

// -----------------------------------

class Worker
{
public:
    const int len = 6;
    QString readed;

    QString name;
    QString valible;
    QString block;
    QString outputs;
    QString image;
    QString file_exe;

    explicit Worker(const QString&);

};

//------------------------------------

class Save_to_config
{
public:
    QFile file;

    QString setting;
    QString laba;
    QString serial;
    QString date;
    QString version;
    QString language;

    explicit Save_to_config(const QString&);
    ~Save_to_config();

    void save_main_param(const QString&,const QString&,const QString&,const QString&,
                         const QString&,const QString&,const QString&,const QString&,
                         const QString&,const QString&,const QString&,const QString&);

    void save_mode(const QString&,const QString&,const QString&,
                   const QString&,const QString&,const QString&);

private:
    QString set_str(QString); // Замена пустой строки на None
};

// ---------------------------------------

class InfoParser
{
public:
    QFile file;

    explicit InfoParser(const QString&);
    ~InfoParser();

    QStringList read();
    QStringList get_lines();

    bool write();
    void set_lines(const QString&, const QString&);
};

#endif // ASS_H
