#include "mode.h"
#include "ui_mode.h"
#include <QFileInfo>

#include <QDebug>


Mode::Mode(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Mode)
{
    ui->setupUi(this);
}

Mode::~Mode()
{
    delete ui;
}

void Mode::on_buttonModeFile_clicked(){
    QString file_name = QFileDialog::getOpenFileName(this, "Открыть файл...",
                                                     QDir::homePath());
    if (!file_name.isEmpty()){
//        QStringList file = file_name.split("/", QString::SkipEmptyParts);
        ui->lineModeFile->setText(file_name);
    }
}


void Mode::on_buttonModeImage_clicked(){
    // нет проверки что действительно загружено изображение !!! что вообще с ним делать???
    QString file_name = QFileDialog::getOpenFileName(this, "Открыть изображение...",
                                                     QDir::homePath());
    if (!file_name.isEmpty()){
        QStringList file = file_name.split("/", QString::SkipEmptyParts);
        ui->lineModeImage->setText(file.last());
    }
}

