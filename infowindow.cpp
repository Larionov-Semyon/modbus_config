#include "infowindow.h"
#include "ui_infowindow.h"
#include <QDebug>

// Окно информационных сообщений

// https://web-answers.ru/c/qscrollarea-s-dinamicheski-dobavlennym-vidzhetom.html
// https://www.cyberforum.ru/qt/thread1147499.html

InfoWindow::InfoWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::InfoWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Информационные сообщения");

    layout = new QVBoxLayout;
    widget = new QWidget;

    widget->setLayout(layout);
    ui->scrollArea->setWidget(widget);

    //    int len_message = 10;
    //    InfoMessage* message[len_message];
    for (int i = 0; i < LEN_MESSAGE; i++) {
        message[i] = new InfoMessage(name[i], text[i]);
        layout->addWidget(message[i]);
    }
}

InfoWindow::~InfoWindow(){
    delete ui;
}


void InfoWindow::closeEvent(QCloseEvent* event){
    qDebug() << "Exit InfoWindow";
    emit firstWindow();
    QMainWindow::closeEvent(event);
}


void InfoWindow::read(QString filename){
    ui->statusbar->showMessage(QString("Работаем с ") + filename);

    InfoParser* file = new InfoParser(filename);

    QStringList list = file->read();

    if (list[0] != "") {
        QMessageBox::warning(this, "Ошибка чтения", list[0]);
        ui->statusbar->showMessage(QString("Ошибка с ") + filename);
        return;
    }

    QString value;
//    QString key;
    for (int i = 1; i < list.count() / 2 + 1; i++) {
//        key = list[2 * i - 1];
        value = list[2 * i];
//        message[i - 1]->findChild<QLineEdit*>("lineEdit")->setText(key);
        message[i - 1]->findChild<QTextEdit*>("textEdit")->setText(value);
    }
}

void InfoWindow::write(QString filename){
    ui->statusbar->showMessage(QString("Работаем с ") + filename);

    InfoParser* file = new InfoParser(filename);

    if (!file->write()) {
        QMessageBox::warning(this, "Ошибка", "Ошибка записи");
        ui->statusbar->showMessage(QString("Ошибка с ") + filename);
        return;
    }

    //    qDebug() << message[1]->findChild<QLineEdit*>("lineEdit")->text();

    QString key, value;
    for (int i = 0; i < LEN_MESSAGE; i++) {
//        key = message[i]->findChild<QLineEdit*>("lineEdit")->text();
        key = name[i];
        value = message[i]->findChild<QTextEdit*>("textEdit")->toPlainText();

        if ((key == "") & (value == "")) {
            continue;
        } else if (key == "") {
            key = "None";
        } else if (value == "") {
            value = "None";
        }

        file->set_lines(key, value);
    }

    QMessageBox::information(this, "Сохранение", "Файл сохранён");
    delete file;
}

void InfoWindow::on_pushButton_clicked(){
    // кнопка *записать файл*
    if (PATH_DEVAULT_INFO == "") {
        PATH_DEVAULT_INFO = QFileDialog::getSaveFileName(this, "Сохранить конфигурационный файл...",
                                                         QDir::homePath(), "Text files (*.txt)");
        if (PATH_DEVAULT_INFO == "") {
            QMessageBox::warning(this, "Ошибка", "Нет названия");
            ui->statusbar->showMessage(QString("Ошибка"));
            return;
        }
    }

    write(PATH_DEVAULT_INFO);
}

void InfoWindow::on_actionOpen_triggered()
{
    PATH_DEVAULT_INFO = QFileDialog::getOpenFileName(this, "Открыть конфигурационный файл...", QDir::homePath());
    read(PATH_DEVAULT_INFO);
}

void InfoWindow::on_exit_triggered()
{
    qDebug() << "Close the InfoWindow";
    emit firstWindow();
    this->close();
}

void InfoWindow::on_buttonDeleteAll_clicked(){
    for (int i = 0; i < LEN_MESSAGE; i++) {
//        message[i]->findChild<QLineEdit*>("lineEdit")->setText("");
        message[i]->findChild<QTextEdit*>("textEdit")->setText("");
    }
}


void InfoWindow::on_save_triggered(){
    on_pushButton_clicked();
}


void InfoWindow::on_saveHow_triggered(){
    PATH_DEVAULT_INFO = "";
    on_pushButton_clicked();
}

