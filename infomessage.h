#ifndef INFOMESSAGE_H
#define INFOMESSAGE_H

#pragma once

#include <QWidget>

namespace Ui {
class InfoMessage;
}

class InfoMessage : public QWidget
{
    Q_OBJECT

public:
    explicit InfoMessage(QString&, QString&, QWidget *parent = nullptr);
    ~InfoMessage();

    void set_delete_mode();
    void set_not_delete_mode();

private:
    Ui::InfoMessage *ui;
};

#endif // INFOMESSAGE_H
