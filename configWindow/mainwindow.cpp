#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mode.h"

#include <QDebug>

// Окно создания конфиг. файла

// (?) горячие клавиши
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

    ui->comboCOMport->setValidator(new QIntValidator(0, 100, this));
    ui->pushModeDelete->setVisible(false);

    set_default_values();
}


MainWindow::~MainWindow(){
    delete ui;
}


bool MainWindow::check_exit(){
    if (!inputs_is_clear()){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Выход",
                                      "У вас есть непустые поля. Хотите сохранить изменения?");
        if (reply == QMessageBox::Yes){
            on_actionSaveHow_triggered();
            return false;
        }
    }
    return true;
}


void MainWindow::closeEvent (QCloseEvent *event)
{
    if (check_exit()){
        event->accept();
    }else{
        event->ignore();
    }
}


bool MainWindow::inputs_is_clear(){
    // проверка на пустые строки
    bool sum = true;

    bool laba = (ui->lineLaba->text() == default_lineLaba);
    bool serial = (ui->lineSerial->text() == default_lineSerial);
    bool version = (ui->lineVer->text() == default_lineVer);
    bool date = (ui->dateEdit->date() == default_dateEdit);
    bool combo_1 = (ui->comboBoxLanguag->currentIndex() == default_comboBoxLanguag);
    bool other_lang = (ui->lineOtherLang->text() == default_lineOtherLang);
    bool other_short_lang = (ui->lineLangShort->text() == default_lineLangShort);
    sum = laba & serial & version & date & combo_1 & other_lang & other_short_lang;
//    qDebug() << sum;

    bool comport = (ui->comboCOMport->currentText() == default_comboCOMport);
    bool baud = (ui->lineBAUDrate->text() == default_lineBAUDrate);
    bool stopbits = (ui->lineSTOPbits->text() == default_lineSTOPbits);
    bool databits = (ui->lineDATAbits->text() == default_lineDATAbits);
    bool response = (ui->lineRESPONSEtime->text() == default_lineRESPONSEtime);
    bool address = (ui->lineADDRESS->text() == default_lineADDRESS);
    bool combo_2 = (ui->comboParity->currentIndex() == default_comboParity);
    sum = sum & comport & baud & stopbits & databits & response & address & combo_2;
//    qDebug() << sum;

    bool power = (ui->textVolt->toPlainText() == default_textVolt);
    bool cur = (ui->textCur->toPlainText() == default_textCur);
    bool doors = (ui->textDoors->toPlainText() == default_textDoors);
    bool emer = (ui->textEmergency->toPlainText() == default_textEmergency);
    bool gnd = (ui->textGnd->toPlainText() == default_textGnd);
    bool gnd_1 = (ui->textWorkGnd->toPlainText() == default_textWorkGnd);
    sum = sum & power & doors & emer & gnd & gnd_1 & cur;
//    qDebug() << sum;

    bool en_power = (ui->textVoltEN->toPlainText() == default_textVolt_EN);
    bool en_cur = (ui->textCurEN->toPlainText() == default_textCur_EN);
    bool en_doors = (ui->textDoorsEN->toPlainText() == default_textDoors_EN);
    bool en_emer = (ui->textEmergencyEN->toPlainText() == default_textEmergency_EN);
    bool en_gnd = (ui->textGndEN->toPlainText() == default_textGnd_EN);
    bool en_gnd_1 = (ui->textWorkGndEN->toPlainText() == default_textWorkGnd_EN);
    sum = sum & en_power & en_doors & en_emer & en_gnd & en_gnd_1 & en_cur;
//    qDebug() << sum;

    bool ot_power = (ui->textVoltOt->toPlainText() == default_text_other);
    bool ot_cur = (ui->textCurOt->toPlainText() == default_text_other);
    bool ot_doors = (ui->textDoorsOt->toPlainText() == default_text_other);
    bool ot_emer = (ui->textEmergencyOt->toPlainText() == default_text_other);
    bool ot_gnd = (ui->textGndOt->toPlainText() == default_text_other);
    bool ot_gnd_1 = (ui->textWorkGndOt->toPlainText() == default_text_other);
    sum = sum & ot_power & ot_doors & ot_emer & ot_gnd & ot_gnd_1 & ot_cur;
//    qDebug() << sum;

    bool l_laba = (ui->lineLangLaba->text() == default_lineLangLaba);
    bool l_start = (ui->lineLangStart->text() == default_lineLangStart);
    bool l_stop = (ui->lineLangStop->text() == default_lineLangStop);
    bool l_block = (ui->lineLangBlock->text() == default_lineLangBlock);
    bool l_connect = (ui->lineLangConnect->text() == default_lineLangConnect);
    bool l_mode = (ui->lineLangMode->text() == default_lineLangMode);
    bool l_tip = (ui->lineLangTip->text() == default_lineLangTip);
    bool l_ready = (ui->lineLangReady->text() == default_lineLangReady);
    bool l_work = (ui->lineLangWork->text() == default_lineLangWork);
    sum = sum & l_laba & l_start & l_block & l_connect & l_mode & l_tip & l_stop & l_ready & l_work;
//    qDebug() << sum;

    return (ui->tabWidget->count() <= MIN_NUM_TAB) & sum;
}


void MainWindow::set_value(){
    // установка значений
    /// MAIN VALUE : Получение главных настроек
    ui->lineLaba->setText(config->get_name_laba());
    ui->lineSerial->setText(config->get_serial_nom());
    ui->lineVer->setText(config->get_version());
    ui->lineOtherLang->setText("!!!");
    ui->lineLangShort->setText("!!!");


   // Возможное место ошибок с датой !!!

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
        QMessageBox::warning(this, "Ошибка", "Не удалось прочитать основной язык");
    }
    ui->comboBoxLanguag->setCurrentIndex(index_default_language);

    /// MODBUS : Получение значений с вкладки MODBUS
    ui->comboCOMport->setCurrentText(config->comport);
    ui->lineBAUDrate->setText(config->baudrate);
    ui->lineSTOPbits->setText(config->stopbits);
    ui->lineDATAbits->setText(config->databits);
    ui->lineRESPONSEtime->setText(config->responsetime);
    ui->lineADDRESS->setText(config->address);

    QString md = config->parity;
    if (md == "Even parity") ui->comboParity->setCurrentIndex(0);
    else if (md == "Odd parity") ui->comboParity->setCurrentIndex(1);
    else if (md == "Space parity") ui->comboParity->setCurrentIndex(2);
    else if (md == "Mark parity") ui->comboParity->setCurrentIndex(3);
    else if (md == "No parity") ui->comboParity->setCurrentIndex(4);
    else qWarning("Ошибка: не найден режим MODBUS");
    ///
    /// TIPS
    ui->textVolt->setText("!!!");
    ui->textCur->setText("!!!");
    ui->textDoors->setText("!!!");
    ui->textEmergency->setText("!!!");
    ui->textGnd->setText("!!!");
    ui->textWorkGnd->setText("!!!");

    ui->textVoltEN->setText("!!!");
    ui->textCurEN->setText("!!!");
    ui->textDoorsEN->setText("!!!");
    ui->textEmergencyEN->setText("!!!");
    ui->textGndEN->setText("!!!");
    ui->textWorkGndEN->setText("!!!");

    ui->textVoltOt->setText("!!!");
    ui->textCurOt->setText("!!!");
    ui->textDoorsOt->setText("!!!");
    ui->textEmergencyOt->setText("!!!");
    ui->textGndOt->setText("!!!");
    ui->textWorkGndOt->setText("!!!");

    /// TRANSLATE
    ui->lineLangLaba->setText("!!!");
    ui->lineLangStart->setText("!!!");
    ui->lineLangStop->setText("!!!");
    ui->lineLangBlock->setText("!!!");
    ui->lineLangConnect->setText("!!!");
    ui->lineLangMode->setText("!!!");
    ui->lineLangTip->setText("!!!");
    ui->lineLangReady->setText("!!!");
    ui->lineLangWork->setText("!!!");

    /// MODES : получение  значений режимов
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
        if (delete_all_mode()){
            ui->statusbar->showMessage(QString("Работаем с ") + file);
            set_value();
        }
        else QMessageBox::information(this, "Файл не открыт", "Вы отказались открыть файл");
    }

    delete config;
}


bool MainWindow::delete_all_mode(){
    int len = ui->tabWidget->count();
    if (len > MIN_NUM_TAB){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Удаление вкладок",
                                      "Открыть файл и удалить ранее используемые данные?");
        if (reply == QMessageBox::Yes){
            for (int i = MIN_NUM_TAB; i < len; i++){
                ui->tabWidget->removeTab(MIN_NUM_TAB);
            }
            return true;
        }
        if (reply == QMessageBox::No)
            return false;
    }
    return true;
}


void MainWindow::make_new_tab(QString tab_name){
    if (ui->tabWidget->count() < MAX_NUM_TAB){

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
    QString tab_name = QString("Режим %0").arg(ui->tabWidget->count() - MIN_NUM_TAB + 1);
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
    if (index >= MIN_NUM_TAB){
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
    if(!PATH_DEVAULT_SAVE.isEmpty()&& !PATH_DEVAULT_SAVE.isNull()){
        read_config(PATH_DEVAULT_SAVE);
    }
    else{
        qDebug() << "Отмена";
        ui->statusbar->showMessage(QString("Отмена"));
    }
}


void MainWindow::on_actionSave_triggered(){
    on_pushButtonSave_clicked();
}


void MainWindow::on_actionExit_triggered(){
    qDebug() << "Close the MainWindow";
    this->close();
}


void MainWindow::on_pushButtonSave_clicked(){
    if (PATH_DEVAULT_SAVE == ""){
        PATH_DEVAULT_SAVE = QFileDialog::getSaveFileName(this, "Сохранить конфигурационный файл...",
                                                         QDir::currentPath(), "Text files (*.txt)");
        qDebug() << PATH_DEVAULT_SAVE;
        if (PATH_DEVAULT_SAVE == "") {
//            QMessageBox::warning(this, "Ошибка", "Нет названия");
            ui->statusbar->showMessage(QString("Отмена"));
            return;
        }
    }

    QString laba = ui->lineLaba->text();
    QString serial = ui->lineSerial->text();
    QString date = ui->dateEdit->text();
    QString version = ui->lineVer->text();
    QString language = ui->comboBoxLanguag->currentText();
    QString other_short_lang = ui->lineLangShort->text();

    QString comport = ui->comboCOMport->currentText();
    QString baud = ui->lineBAUDrate->text();
    QString stopbits = ui->lineSTOPbits->text();
    QString databits = ui->lineDATAbits->text();
    QString parity = ui->comboParity->currentText();
    QString response = ui->lineRESPONSEtime->text();
    QString address = ui->lineADDRESS->text();

    QString power = ui->textVolt->toPlainText();
    QString cur = ui->textCur->toPlainText();
    QString doors = ui->textDoors->toPlainText();
    QString emer = ui->textEmergency->toPlainText();
    QString gnd = ui->textGnd->toPlainText();
    QString gnd_1 = ui->textWorkGnd->toPlainText();

    QString en_power = ui->textVoltEN->toPlainText();
    QString en_cur = ui->textCurEN->toPlainText();
    QString en_doors = ui->textDoorsEN->toPlainText();
    QString en_emer = ui->textEmergencyEN->toPlainText();
    QString en_gnd = ui->textGndEN->toPlainText();
    QString en_gnd_1 = ui->textWorkGndEN->toPlainText();

    QString ot_power = ui->textVoltOt->toPlainText();
    QString ot_cur = ui->textCurOt->toPlainText();
    QString ot_doors = ui->textDoorsOt->toPlainText();
    QString ot_emer = ui->textEmergencyOt->toPlainText();
    QString ot_gnd = ui->textGndOt->toPlainText();
    QString ot_gnd_1 = ui->textWorkGndOt->toPlainText();

    QString l_laba = ui->lineLangLaba->text();
    QString l_start = ui->lineLangStart->text();
    QString l_stop = ui->lineLangStop->text();
    QString l_block = ui->lineLangBlock->text();
    QString l_connect = ui->lineLangConnect->text();
    QString l_mode = ui->lineLangMode->text();
    QString l_tip = ui->lineLangTip->text();
    QString l_ready = ui->lineLangReady->text();
    QString l_work = ui->lineLangWork->text();


    save_conf = new Save_to_config(PATH_DEVAULT_SAVE);
    save_conf->save_main_param(laba, serial, date, version,
                               language, comport, baud, stopbits,
                               databits, parity, response, address);


    QString name, file, block, output, valible, image;
    for (int ind = MIN_NUM_TAB; ind < ui->tabWidget->count(); ind++){
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


void MainWindow::set_default_values(){
    ui->lineVer->setText(default_lineVer);
    ui->lineLaba->setText(default_lineLaba);
    ui->lineSerial->setText(default_lineSerial);
    ui->dateEdit->setDate(default_dateEdit);
    ui->comboBoxLanguag->setCurrentIndex(default_comboBoxLanguag);
    ui->lineOtherLang->setText(default_lineOtherLang);
    ui->lineLangShort->setText(default_lineLangShort);
//
    ui->comboCOMport->setCurrentText(default_comboCOMport);
    ui->lineBAUDrate->setText(default_lineBAUDrate);
    ui->lineSTOPbits->setText(default_lineSTOPbits);
    ui->lineDATAbits->setText(default_lineDATAbits);
    ui->lineRESPONSEtime->setText(default_lineRESPONSEtime);
    ui->lineADDRESS->setText(default_lineADDRESS);
    ui->comboParity->setCurrentIndex(default_comboParity);
//
    ui->textVolt->setText(default_textVolt);
    ui->textCur->setText(default_textCur);
    ui->textDoors->setText(default_textDoors);
    ui->textEmergency->setText(default_textEmergency);
    ui->textGnd->setText(default_textGnd);
    ui->textWorkGnd->setText(default_textWorkGnd);

    ui->textVoltEN->setText(default_textVolt_EN);
    ui->textCurEN->setText(default_textCur_EN);
    ui->textDoorsEN->setText(default_textDoors_EN);
    ui->textEmergencyEN->setText(default_textEmergency_EN);
    ui->textGndEN->setText(default_textGnd_EN);
    ui->textWorkGndEN->setText(default_textWorkGnd_EN);

    ui->textVoltOt->setText(default_text_other);
    ui->textCurOt->setText(default_text_other);
    ui->textDoorsOt->setText(default_text_other);
    ui->textEmergencyOt->setText(default_text_other);
    ui->textGndOt->setText(default_text_other);
    ui->textWorkGndOt->setText(default_text_other);
//
    ui->lineLangLaba->setText(default_lineLangLaba);
    ui->lineLangStart->setText(default_lineLangStart);
    ui->lineLangStop->setText(default_lineLangStop);
    ui->lineLangBlock->setText(default_lineLangBlock);
    ui->lineLangConnect->setText(default_lineLangConnect);
    ui->lineLangMode->setText(default_lineLangMode);
    ui->lineLangTip->setText(default_lineLangTip);
    ui->lineLangReady->setText(default_lineLangReady);
    ui->lineLangWork->setText(default_lineLangWork);
}


void MainWindow::delete_all_values(){
    if (inputs_is_clear() == false){
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Удаление",
                                      "Вы уверены, что хотите все очистить?");
        qDebug()<< "set default value - ответ" << reply;
        if (reply == QMessageBox::No){
            return;
        }
    }

    int len = ui->tabWidget->count();
    if (len > MIN_NUM_TAB){
        for (int i = MIN_NUM_TAB; i < len; i++){
            ui->tabWidget->removeTab(MIN_NUM_TAB);
        }
    }

    set_default_values();
}

void MainWindow::on_pushButtonDeleteAll_clicked(){
    delete_all_values();
}


void MainWindow::on_actionSaveHow_triggered(){
    PATH_DEVAULT_SAVE = "";
    on_pushButtonSave_clicked();
    ui->statusbar->showMessage("");
}


void MainWindow::on_actionNew_triggered(){
    PATH_DEVAULT_SAVE = "";
    delete_all_values();
    ui->statusbar->showMessage("");
}


void MainWindow::on_tabWidget_currentChanged(int index){
    // кнопки режима Удалить и Добавить
    if (index < MIN_NUM_TAB)
        ui->pushModeDelete->setVisible(false);
    else
        ui->pushModeDelete->setVisible(true);

    if (ui->tabWidget->count() < MAX_NUM_TAB)
        ui->pushModeAdd->setVisible(true);
    else
        ui->pushModeAdd->setVisible(false);

}

void MainWindow::change_textEdit(QTextEdit *text){
    QString textContent = text->toPlainText();

    int length = textContent.count();

    if (length > MAX_NUM_TEXT)
    {
        int position = text->textCursor().position();
        QTextCursor textCursor = text->textCursor();
        textContent.remove(position - (length - MAX_NUM_TEXT), length - MAX_NUM_TEXT);
        text->setText(textContent);
        textCursor.setPosition(position - (length - MAX_NUM_TEXT));
        text->setTextCursor(textCursor);
    }
}
