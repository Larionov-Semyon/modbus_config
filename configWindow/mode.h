#ifndef MODE_H
#define MODE_H

#pragma once

#include <QWidget>
#include <QFileDialog>
#include <QTextEdit>

namespace Ui {
class Mode;
}

class Mode : public QWidget
{
    Q_OBJECT

public:
    explicit Mode(QWidget *parent = nullptr);
    ~Mode();

private slots:
    void on_buttonModeFile_clicked();

    void on_buttonModeImage_clicked();

    void on_textMode_textChanged();

    void on_textModeEN_textChanged();

    void on_textModeOT_textChanged();

    void change_textEdit(QTextEdit*);

private:
    Ui::Mode *ui;

    const int MAX_NUM_TEXT = 200;
};

#endif // MODE_H
