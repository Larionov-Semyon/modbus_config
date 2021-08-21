#ifndef FILE_H
#define FILE_H

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
    QStringList Mode_name; // РЅР°Р·РІР°РЅРёРµ СЂРµР¶РёРјРѕРІ
    QStringList Mode; // РєРѕРЅС„РёРіСѓСЂР°С†РёСЏ СЂРµР¶РёРјРѕРІ <<str> -- <str>>

    explicit Conf(const QString&); // РєРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ
    ~Conf();

    QString read(); // С‡С‚РµРЅРёРµ С„Р°Р№Р»Р° РІ РєР»Р°СЃСЃ (return get_list()) - РёР»Рё return <name error>

private:
    //head
    QString setting;
    QString name_laba;
    QString serial_nom;
    QString date;
    QString version;
    QString language;

     QStringList get_lines(); // С‡С‚РµРЅРёРµ С„Р°Р№Р»Р° -- <СЃРїРёСЃРѕРє СЃС‚СЂРѕРє>
     QString set_str(QString); // Р—Р°РјРµРЅР° РїСѓСЃС‚РѕР№ СЃС‚СЂРѕРєРё РЅР° None
};

// -----------------------------------

class Worker
{
public:
    const int len = 6;
    QString readed;

    QString name = "No name";
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
    QString set_str(QString); // Р—Р°РјРµРЅР° РїСѓСЃС‚РѕР№ СЃС‚СЂРѕРєРё РЅР° None
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
