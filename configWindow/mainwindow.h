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

    void set_list_com_QComboBox(QComboBox* com_box);

private slots:
    void rename_tab(); //слот для изменения названия Tab
    //    void about();

    //-------------Кнопки--------------
    void on_pushModeAdd_clicked(); // кнопка добавить режим
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

private:
    Ui::MainWindow* ui;

    Sets* config;
    Save_to_config1* save_conf;
    Inf_Msg* inf_conf;
    Butts* but_conf;
    //    Mode_chan* mode;

    QString PATH_DEVAULT_SAVE = "";

    const int MAX_NUM_TAB = 12;
    const int MIN_NUM_TAB = 4;
    const int MAX_NUM_TEXT = 200;

    void read_config(QString&);
    void set_value_mode(QStringList&);
    bool delete_all_mode();
    void set_value();
    void make_new_tab(QString);
    bool check_exit();
    void delete_all_values();
    void set_default_values();
    void closeEvent(QCloseEvent* event);
    bool inputs_is_clear();
    void change_textEdit(QTextEdit*);
};
#endif // MAINWINDOW_H
