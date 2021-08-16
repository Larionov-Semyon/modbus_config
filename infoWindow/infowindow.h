#ifndef INFOWINDOW_H
#define INFOWINDOW_H

#pragma once

#include <QMainWindow>
#include <QGroupBox>
#include <QVBoxLayout>
#include <QFileDialog>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QScrollArea>
#include <QTextEdit>

#include "infomessage.h"
#include "ass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class InfoWindow; }
QT_END_NAMESPACE

class InfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit InfoWindow(QWidget *parent = nullptr);
    ~InfoWindow();

    QString PATH_DEVAULT_INFO = "";

    void read(QString);
    void write(QString);

signals:
    void firstWindow();

private:
    Ui::InfoWindow *ui;

    enum {LEN_MESSAGE = 13};

    QVBoxLayout* layout;
    QWidget* widget;
    InfoMessage* message[LEN_MESSAGE];

    QStringList name = {"Подсказка режима 1",
                        "Подсказка режима 2",
                        "Подсказка режима 3",
                        "Подсказка режима 4",
                        "Подсказка режима 5",
                        "Подсказка режима 6",
                        "Подсказка режима 7",
                        "Подсказка режима 8",
                        "Текст состояния при блокировке POWER",
                        "Текст состояния при блокировке DOORS",
                        "Текст состояния при блокировке EMERGENCY_BUTTON",
                        "Текст состояния при блокировке GND",
                        "Текст состояния при блокировке WORK_GND"};

    QStringList text = {
        "Соберите схему по инструкции и проверьте отсутствие блокировок, указанных для данного режима.",
        "Соберите схему по инструкции и проверьте отсутствие блокировок, указанных для данного режима.",
        "Соберите схему по инструкции и проверьте отсутствие блокировок, указанных для данного режима.",
        "Соберите схему по инструкции и проверьте отсутствие блокировок, указанных для данного режима.",
        "Соберите схему по инструкции и проверьте отсутствие блокировок, указанных для данного режима.",
        "Соберите схему по инструкции и проверьте отсутствие блокировок, указанных для данного режима.",
        "Соберите схему по инструкции и проверьте отсутствие блокировок, указанных для данного режима.",
        "Соберите схему по инструкции и проверьте отсутствие блокировок, указанных для данного режима.",
        "Амплитуда напряжения/тока превысила допустимые значения.",
        "Не закрыты изолирующие двери.",
        "Нажата аварийная кнопка.",
        "Не подключено заземление",
        "Не подключено рабочее заземление."
    };

    void set_default_value();
    void check_exit();

    bool inputs_is_clear();

private slots:
    void on_pushButton_clicked();

    void on_exit_triggered();

    void on_actionOpen_triggered();

    void on_buttonDeleteAll_clicked();

    void on_save_triggered();

    void on_saveHow_triggered();

protected:
    void closeEvent(QCloseEvent *event);
};

#endif // INFOWINDOW_H
