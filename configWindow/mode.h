#ifndef MODE_H
#define MODE_H

#pragma once

#include <QFileDialog>
#include <QTextEdit>
#include <QWidget>
#include <QFileInfo>

namespace Ui {
class Mode;
}

class Mode : public QWidget {
    Q_OBJECT

signals:
    void change_textModeName();

public:
    explicit Mode(QWidget* parent = nullptr);
    ~Mode();

private slots:
    void on_buttonModeFile_clicked();
    void on_buttonModeImage_clicked();
    void on_textMode_textChanged();
    void on_textModeEN_textChanged();
    void on_textModeOT_textChanged();
    void change_textEdit(QTextEdit*);
    void on_lineModeName_textChanged(const QString&);

private:
    Ui::Mode* ui;

    const int MAX_NUM_TEXT = 425;
};

#endif // MODE_H
