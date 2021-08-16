#ifndef MAINMENU_H
#define MAINMENU_H

#pragma once

#include "mainwindow.h"
#include "infowindow.h"


namespace Ui {
class MainMenu;
}

class MainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_confButton_clicked();

    void on_infoButton_clicked();

    void on_exitButton_clicked();

    void on_aboutButton_clicked();

private:
    Ui::MainMenu *ui;

    MainWindow *confWindow;
    InfoWindow *infoWindow;

    QString information =
"<b>Информация о программе</b> <hr>"
"<p>Программа для работы с MODBUS</p>"
"<p><b>Конфигурационный файл</b> - файл для настроек работы "
"основной программы, настройки MODBUS, описание режимов работы.</p>"
"<p><b>Информационные сообщения</b> - сообщения, показывающиеся "
"при возникновении ошибок.</p>";

};

#endif // MAINMENU_H
