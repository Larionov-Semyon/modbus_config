#ifndef MODE_H
#define MODE_H

#pragma once

#include <QWidget>
#include <QFileDialog>

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

private:
    Ui::Mode *ui;
};

#endif // MODE_H
