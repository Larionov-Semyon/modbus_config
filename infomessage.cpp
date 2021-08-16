#include "infomessage.h"
#include "ui_infomessage.h"

InfoMessage::InfoMessage(QString &name, QString &text, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InfoMessage)
{
    ui->setupUi(this);
    ui->label->setText(name);
    ui->label->setWordWrap(true);

    ui->textEdit->setText(text);

    set_not_delete_mode();
}

InfoMessage::~InfoMessage()
{
    delete ui;
}

void InfoMessage::set_delete_mode(){
    ui->checkBox->setVisible(true);
    ui->pushButton->setVisible(true);
}

void InfoMessage::set_not_delete_mode(){
    ui->checkBox->setVisible(false);
    ui->pushButton->setVisible(false);
}
