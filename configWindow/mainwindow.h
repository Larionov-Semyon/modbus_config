#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include "ass.h"

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>
#include <QRadioButton>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void firstWindow();

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

private:
    Ui::MainWindow *ui;

    Conf *config;
    Save_to_config *save_conf;

    QString PATH_DEVAULT_SAVE = "";

    enum {MAX_COUNT_TAB = 10};

    void read_config(QString&);
    void set_value_mode(QStringList&);
    void delete_all_mode();
    void set_value();
    void make_new_tab(QString);
    void check_exit();
    void set_default_value();

    bool inputs_is_clear();

protected:
    void closeEvent(QCloseEvent *event);

};
#endif // MAINWINDOW_H
