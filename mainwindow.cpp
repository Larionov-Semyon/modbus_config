#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mode.h"

#include <QDebug>

// Окно создания конфиг. файла

// (?) горячие клавиши
// () в lineEdit можно записывать все
// () проверка на введенные данные
// () плохо в работе с MODE
// () set_value проверка Даты

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Конфигурационный файл");
    ui->tabWidget->setCurrentIndex(0);
    set_default_value();
}


MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::check_exit(){
    if (!inputs_is_clear()){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Выход",
                                      "У вас есть непустые поля. Вы уверены, что хотите выйти?");
        if (reply == QMessageBox::No){
            on_actionSaveHow_triggered();
        }
    }
}


void MainWindow::closeEvent(QCloseEvent *event){
    // нажатие на *крестик*
    qDebug() << "Exit confWindow";

    check_exit();
    emit firstWindow();
    QMainWindow::closeEvent(event);
}


bool MainWindow::inputs_is_clear(){
    // проверка на пустые строки
    bool laba = ui->lineLaba->text().isEmpty();
    bool serial = ui->lineSerial->text().isEmpty();
    bool version = ui->lineVer->text().isEmpty();

    bool comport = ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineCOMport")->text().isEmpty();
    bool baud = ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineBAUDrate")->text().isEmpty();
    bool stopbits = ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineSTOPbits")->text().isEmpty();
    bool databits = ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineDATAbits")->text().isEmpty();
    bool response = ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineRESPONSEtime")->text().isEmpty();
    bool address = ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineADDRESS")->text().isEmpty();

    bool all_fields = laba & serial & version & comport & baud & stopbits & databits & response & address;
    return (ui->tabWidget->count() <= 2) & all_fields;
}


void MainWindow::set_value(){
    // установка значений
    // MAIN VALUE : Получение главных настроек
    ui->lineLaba->setText(config->get_name_laba());
    ui->lineSerial->setText(config->get_serial_nom());
    ui->lineVer->setText(config->get_version());

        // Дата: файл - (D-M-Y)  читаем - (Y-M-D)
    QStringList list_date = (config->get_date()).split(".");
    if (list_date.length() >= 3){
        if ((list_date[2].toInt()) & (list_date[1].toInt()) & (list_date[0].toInt())){
        QDate date(list_date[2].toInt(), list_date[1].toInt(), list_date[0].toInt());
        ui->dateEdit->setDate(date);
        }
    }
    else{
        QMessageBox::warning(this, "Ошибка", "Не удалось прочитать дату");
    }

        // Язык (если язык не понят, то добавление нового Item)
    int index_default_language = ui->comboBoxLanguag->findText(config->get_language());
    if (index_default_language == -1){
        ui->comboBoxLanguag->addItem(config->get_language());
        index_default_language = ui->comboBoxLanguag->findText(config->get_language());
    }
    ui->comboBoxLanguag->setCurrentIndex(index_default_language);

    // MODBUS : Получение значений с вкладки MODBUS
    ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineCOMport")->setText(config->comport);
    ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineBAUDrate")->setText(config->baudrate);
    ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineSTOPbits")->setText(config->stopbits);
    ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineDATAbits")->setText(config->databits);
    ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineRESPONSEtime")->setText(config->responsetime);
    ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineADDRESS")->setText(config->address);

    QString md = config->parity;
    if (md == "Even parity") ui->tabWidget->widget(1)->findChild<QComboBox*>("comboParity")->setCurrentIndex(0);
    else if (md == "Odd parity") ui->tabWidget->widget(1)->findChild<QComboBox*>("comboParity")->setCurrentIndex(1);
    else if (md == "Space parity") ui->tabWidget->widget(1)->findChild<QComboBox*>("comboParity")->setCurrentIndex(2);
    else if (md == "Mark parity") ui->tabWidget->widget(1)->findChild<QComboBox*>("comboParity")->setCurrentIndex(3);
    else qWarning("Ошибка: не найден режим MODBUS");


    // MODES : получение  значений режимов
    qDebug() << config->Mode;
    if (config->Mode != QStringList("")){
        qDebug() << "Read MODES";
        set_value_mode(config->Mode);
    }else{
        qDebug() << "Not read MODES";
    }
}


void MainWindow::set_value_mode(QStringList &_Mode){ // установка значений режимов
    for(int i = 0; i < _Mode.length(); i++){
        Worker mode = Worker(_Mode[i]);

        if (mode.readed != "True"){
            QMessageBox::warning(this, "Ошибка открытия режима", mode.readed);
        };

        ui->tabWidget->addTab(new Mode(), mode.name);
        int ind = ui->tabWidget->count() - 1;

//        qDebug() << ui->tabWidget->widget(ind)->children();
        ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeName")->setText(mode.name);
        ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeFile")->setText(mode.file_exe);
        ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeBlock")->setText(mode.block);
        ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeOutput")->setText(mode.outputs);
        ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeImage")->setText(mode.image);

        QStringList radiobuttonTrue, radiobuttonFalse;
        radiobuttonTrue << "Доступен" << "Да" << "Yes";
        radiobuttonFalse << "Недоступен" << "Нет" << "No";
        if (radiobuttonTrue.indexOf(mode.valible) != -1){
            ui->tabWidget->widget(ind)->findChild<QRadioButton*>("radioButtonYes")->setChecked(true);
        }
        else if (radiobuttonFalse.indexOf(mode.valible) != -1){
            ui->tabWidget->widget(ind)->findChild<QRadioButton*>("radioButtonNo")->setChecked(true);
        }
    }
}


void MainWindow::read_config(QString &file){
    // чтение конфиг файла в приложение
    config = new Conf(file);
    qDebug() << "Open " << file;

    if (config->readed != QString("True")){
        ui->statusbar->showMessage(QString("Ошибка открытия: ") + file);
        QMessageBox::warning(this, "Ошибка", config->readed);
    }
    else{
        ui->statusbar->showMessage(QString("Работаем с ") + file);
        delete_all_mode();
        set_value();
    }

    delete config;
}


void MainWindow::delete_all_mode(){
    int len = ui->tabWidget->count();
    if (len > 2){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Удаление вкладок",
                                      "Можно удалить ранее открытые вкладки режимов?");
        if (reply == QMessageBox::Yes){
            for (int i = 2; i < len; i++){
                ui->tabWidget->removeTab(2);
            }
        }
    }
}


void MainWindow::make_new_tab(QString tab_name){
    if (ui->tabWidget->count() < MAX_COUNT_TAB){
        Mode *mode = new Mode();
        int index_tab = ui->tabWidget->addTab(mode, tab_name);
        ui->tabWidget->setCurrentIndex(index_tab);

        ui->tabWidget->widget(index_tab)->findChild<QLineEdit*>("lineModeName")->setText(tab_name);

        connect(mode->findChild<QLineEdit*>("lineModeName"), SIGNAL(editingFinished()),
                this, SLOT(rename_tab()));
    }
}


void MainWindow::on_pushModeAdd_clicked(){
    // кнопка добавить режим
    QString tab_name = QString("Режим %0").arg(ui->tabWidget->count() - 1);
    make_new_tab(tab_name);
}


void MainWindow::rename_tab(){
    //слот для изменения названия Tab
    int index = ui->tabWidget->currentIndex();
    QString text = ui->tabWidget->widget(index)->findChild<QLineEdit*>("lineModeName")->text();
    ui->tabWidget->setTabText(index, text);
}


void MainWindow::on_pushModeDelete_clicked(){
    // удаление режима
    int index = ui->tabWidget->currentIndex();
    if ((index != 0) & (index != 1) ){
        QString name_tab = ui->tabWidget->tabText(index);
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, ("Удаление вкладки"),
                                      QString("Можно удалить режим '%0' ?").arg(name_tab));
        if (reply == QMessageBox::Yes){
                ui->tabWidget->removeTab(index);
        }
    }
}


void MainWindow::on_actionOpen_triggered(){
    PATH_DEVAULT_SAVE = QFileDialog::getOpenFileName(this, "Открыть конфигурационный файл...", QDir::currentPath());
    read_config(PATH_DEVAULT_SAVE);
}


void MainWindow::on_actionSave_triggered(){
    on_pushButtonSave_clicked();
}


void MainWindow::on_actionExit_triggered(){
    qDebug() << "Close the InfoWindow";
    emit firstWindow();
    this->close();
}


void MainWindow::on_pushButtonSave_clicked(){
    if (PATH_DEVAULT_SAVE == ""){
        PATH_DEVAULT_SAVE = QFileDialog::getSaveFileName(this, "Сохранить конфигурационный файл...",
                                                         QDir::currentPath(), "Text files (*.txt)");
        if (PATH_DEVAULT_SAVE == "") {
            QMessageBox::warning(this, "Ошибка", "Нет названия");
            ui->statusbar->showMessage(QString("Ошибка"));
            return;
        }
    }

    QString laba = ui->lineLaba->text();
    QString serial = ui->lineSerial->text();
    QString date = ui->dateEdit->text();
    QString version = ui->lineVer->text();
    QString language = ui->comboBoxLanguag->currentText();

    QString comport = ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineCOMport")->text();
    QString baud = ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineBAUDrate")->text();
    QString stopbits = ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineSTOPbits")->text();
    QString databits = ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineDATAbits")->text();
    QString parity = ui->tabWidget->widget(1)->findChild<QComboBox*>("comboParity")->currentText();
    QString response = ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineRESPONSEtime")->text();
    QString address = ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineADDRESS")->text();

    save_conf = new Save_to_config(PATH_DEVAULT_SAVE);
    save_conf->save_main_param(laba, serial, date, version,
                               language, comport, baud, stopbits,
                               databits, parity, response, address);


    QString name, file, block, output, valible, image;
    for (int ind = 2; ind < ui->tabWidget->count(); ind++){
        name = ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeName")->text();
        file = ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeFile")->text();
        block = ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeBlock")->text();
        output = ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeOutput")->text();
        image = ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeImage")->text();

        if (ui->tabWidget->widget(ind)->findChild<QRadioButton*>("radioButtonYes")->isChecked()){
            valible = "Доступен";
        }else if (ui->tabWidget->widget(ind)->findChild<QRadioButton*>("radioButtonNo")->isChecked()){
            valible = "Недоступен";
        }else{
            valible = "None";
        }
        save_conf->save_mode(name, valible, block, output, image, file);
    }

    delete save_conf;

    ui->statusbar->showMessage(QString("Работаем с ") + PATH_DEVAULT_SAVE);
    QMessageBox::information(this, "Сохранение", "Файл сохранился");
}


void MainWindow::set_default_value(){
    delete_all_mode();

    ui->lineVer->setText("");
    ui->lineLaba->setText("");
    ui->lineSerial->setText("");
    ui->dateEdit->setDate(QDate(2020, 1, 1));
    ui->comboBoxLanguag->setCurrentIndex(0);

    ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineCOMport")->setText("");
    ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineBAUDrate")->setText("");
    ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineSTOPbits")->setText("");
    ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineDATAbits")->setText("");
    ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineRESPONSEtime")->setText("");
    ui->tabWidget->widget(1)->findChild<QLineEdit*>("lineADDRESS")->setText("");
    ui->tabWidget->widget(1)->findChild<QComboBox*>("comboParity")->setCurrentIndex(0);
}

void MainWindow::on_pushButtonDeleteAll_clicked(){
    set_default_value();
}


void MainWindow::on_actionSaveHow_triggered(){
    PATH_DEVAULT_SAVE = "";
    on_pushButtonSave_clicked();
    ui->statusbar->showMessage("");
}


void MainWindow::on_actionNew_triggered(){
    PATH_DEVAULT_SAVE = "";
    set_default_value();
    ui->statusbar->showMessage("");
}


void MainWindow::on_tabWidget_currentChanged(int index){
    // кнопки режима Удалить и Добавить
    if ((index == 0) | (index == 1))
        ui->pushModeDelete->setVisible(false);
    else
        ui->pushModeDelete->setVisible(true);

    if (ui->tabWidget->count() < MAX_COUNT_TAB)
        ui->pushModeAdd->setVisible(true);
    else
        ui->pushModeAdd->setVisible(false);

}

