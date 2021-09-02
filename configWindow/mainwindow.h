#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include "file.h"

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QRadioButton>
#include <QDate>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

//signals:
//    void firstWindow();

private slots:
    void on_pushModeAdd_clicked(); // кнопка добавить режим
    void on_pushModeDelete_clicked(); // удаление режима
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionExit_triggered();
    void on_pushButtonSave_clicked();
    void on_pushButtonDeleteAll_clicked();
    void on_actionSaveHow_triggered();
    void on_actionNew_triggered();
    void rename_tab(); //слот для изменения названия Tab
    void on_tabWidget_currentChanged(int index);

    void on_textEmergencyOt_textChanged();

    void on_textCur_textChanged();

    void on_textCurEN_textChanged();

    void on_textCurOt_textChanged();

    void on_textDoors_textChanged();

    void on_textDoorsEN_textChanged();

    void on_textDoorsOt_textChanged();

    void on_textEmergency_textChanged();

    void on_textEmergencyEN_textChanged();

    void on_textGnd_textChanged();

    void on_textGndEN_textChanged();

    void on_textGndOt_textChanged();

    void on_textVolt_textChanged();

    void on_textVoltEN_textChanged();

    void on_textVoltOt_textChanged();

    void on_textWorkGnd_textChanged();

    void on_textWorkGndEN_textChanged();

    void on_textWorkGndOt_textChanged();

private:
    Ui::MainWindow *ui;

    Conf *config;
    Save_to_config *save_conf;

    QString PATH_DEVAULT_SAVE = "";

    const int MAX_NUM_TAB = 10;
    const int MIN_NUM_TAB = 4;
    const int MAX_NUM_TEXT = 200;

    const QString default_lineVer = "";
    const QString default_lineLaba = "";
    const QString default_lineSerial = "";
    const QDate default_dateEdit = QDate(2021, 1, 1);
    const int default_comboBoxLanguag = 0;
    const QString default_lineOtherLang = "";
    const QString default_lineLangShort = "";

    const QString default_comboCOMport= "";
    const QString default_lineBAUDrate = "";
    const QString default_lineSTOPbits = "";
    const QString default_lineDATAbits = "";
    const QString default_lineRESPONSEtime = "";
    const QString default_lineADDRESS = "";
    const int default_comboParity = 0;

    const QString default_textVolt = "Амплитуда напряжения/тока превысила допустимые значения.";
    const QString default_textCur = "Амплитуда напряжения/тока превысила допустимые значения.";
    const QString default_textDoors = "Не закрыты изолирующие двери.";
    const QString default_textEmergency = "Нажата аварийная кнопка.";
    const QString default_textGnd = "Не подключено заземление";
    const QString default_textWorkGnd = "Не подключено рабочее заземление.";

    const QString default_textVolt_EN = "Амплитуда напряжения/тока превысила допустимые значения.";
    const QString default_textCur_EN = "Амплитуда напряжения/тока превысила допустимые значения.";
    const QString default_textDoors_EN = "Не закрыты изолирующие двери.";
    const QString default_textEmergency_EN = "Нажата аварийная кнопка.";
    const QString default_textGnd_EN = "Не подключено заземление";
    const QString default_textWorkGnd_EN = "Не подключено рабочее заземление.";

    const QString default_text_other = "";

    const QString default_lineLangLaba = "";
    const QString default_lineLangStart = "";
    const QString default_lineLangStop = "";
    const QString default_lineLangMode = "";
    const QString default_lineLangConnect = "";
    const QString default_lineLangBlock = "";
    const QString default_lineLangTip = "";
    const QString default_lineLangReady = "";
    const QString default_lineLangWork = "";

    void read_config(QString&);
    void set_value_mode(QStringList&);
    bool delete_all_mode();
    void set_value();
    void make_new_tab(QString);
    void check_exit();
    void delete_all_values();
    void set_default_values();
    void closeEvent(QCloseEvent *event);
    bool inputs_is_clear();
    void change_textEdit(QTextEdit*);

//protected:
//    void closeEvent(QCloseEvent *event);

};
#endif // MAINWINDOW_H
