#include "mode.h"
#include "ui_mode.h"
//#include <QDebug>

// () нет проверки что действительно загружено изображение

Mode::Mode(QWidget* parent):QWidget(parent), ui(new Ui::Mode)
{
    ui->setupUi(this);
}


Mode::~Mode()
{
    delete ui;
}


void Mode::on_buttonModeFile_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Открыть файл...",
        QDir::homePath());
    if (!file_name.isEmpty()) {
        //        QStringList file = file_name.split("/", QString::SkipEmptyParts);
        ui->lineModeFile->setText(file_name);
    }
}


void Mode::on_buttonModeImage_clicked()
{
    QString file_name = QFileDialog::getOpenFileName(this, "Открыть изображение...",
        QDir::homePath());
    if (!file_name.isEmpty()) {
        QStringList file = file_name.split("/", QString::SkipEmptyParts);
        ui->lineModeImage->setText(file.last());
    }
}


void Mode::change_textEdit(QTextEdit* text)
{
    QString textContent = text->toPlainText();

    int length = textContent.count();

    if (length > MAX_NUM_TEXT) {
        int position = text->textCursor().position();
        QTextCursor textCursor = text->textCursor();
        textContent.remove(position - (length - MAX_NUM_TEXT), length - MAX_NUM_TEXT);
        text->setText(textContent);
        textCursor.setPosition(position - (length - MAX_NUM_TEXT));
        text->setTextCursor(textCursor);
    }
}


void Mode::on_lineModeName_textChanged(const QString& arg1)
{
    emit change_textModeName();
}


void Mode::on_textMode_textChanged()
{
    change_textEdit(ui->textMode);
}


void Mode::on_textModeEN_textChanged()
{
    change_textEdit(ui->textModeEN);
}


void Mode::on_textModeOT_textChanged()
{
    change_textEdit(ui->textModeOT);
}
