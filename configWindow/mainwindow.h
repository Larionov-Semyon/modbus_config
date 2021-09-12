#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include "configWindow/static_text.cpp"
#include "read_class.h"

#include <QCloseEvent>
#include <QComboBox>
#include <QCompleter>
#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QRadioButton>
#include <QSerialPortInfo>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

private slots:
    void rename_tab(); //слот для изменения названия Tab

    //-------------Кнопки--------------
    void on_pushModeAdd_clicked();    // кнопка добавить режим
    void on_pushModeDelete_clicked(); // удаление режима
    void on_actionOpen_triggered();
    void on_actionSave_triggered();
    void on_actionExit_triggered();
    void on_pushButtonSave_clicked();
    void on_pushButtonDeleteAll_clicked();
    void on_actionSaveHow_triggered();
    void on_actionNew_triggered();
    void on_tabWidget_currentChanged(int index);
    void on_updateCOM_clicked();
    //------------Текстовый ввод-------
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

    void on_comboCOMport_currentTextChanged(const QString& arg1);
    void on_textSerial_textChanged();
    void on_textSerialEN_textChanged();
    void on_textSerialOT_textChanged();
    void on_textController_textChanged();
    void on_textControllerEN_textChanged();
    void on_textControllerOT_textChanged();
    void on_lineRESPONSEtime_editingFinished();
    void on_lineADDRESS_editingFinished();

private:
    Ui::MainWindow* ui;

    Sets* config;
    Save_to_config1* save_conf;
    Inf_Msg* inf_conf;
    Butts* but_conf;

    QString PATH_DEVAULT_SAVE = "";

    const int MAX_NUM_TAB = 12;
    const int MIN_NUM_TAB = 4;
    const int MAX_NUM_TEXT = 425;

    void make_new_tab(QString&);

    void read_config(QString&);
    void delete_all_values();
    void set_default_values();
    void set_value();
    bool inputs_is_clear();

    void set_value_mode(QStringList&);
    bool delete_all_mode();

    bool check_exit();
    void closeEvent(QCloseEvent*);

    void change_textEdit(QTextEdit*);
    void change_lineResponse();
    void change_lineADDRESS();
    void set_list_com_QComboBox(QComboBox*);
};
#endif // MAINWINDOW_H
