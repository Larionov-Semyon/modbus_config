#include "mainwindow.h"
#include "mode.h"
#include "ui_mainwindow.h"

#include <QDebug>

// Окно создания конфиг. файла

MainWindow::MainWindow(QWidget* parent):QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("Конфигурационный файл");
    ui->tabWidget->setCurrentIndex(0);

    ui->lineRESPONSEtime->setValidator(new QIntValidator(0, INT_MAX, this));
    ui->lineADDRESS->setValidator(new QIntValidator(0, INT_MAX, this));
    ui->pushModeDelete->setVisible(false);

    set_default_values();
}

MainWindow::~MainWindow()
{
    delete ui;
}

bool MainWindow::check_exit() // Окно выхода
{
    if (!inputs_is_clear()) {
        QMessageBox messageBox(QMessageBox::Question,
            tr("Выход"),
            tr("У вас есть непустые поля. Хотите сохранить изменения?"),
            QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel,
            this);
        messageBox.setDefaultButton(QMessageBox::Save);
        messageBox.setButtonText(QMessageBox::Save, tr("Сохранить"));
        messageBox.setButtonText(QMessageBox::Discard, tr("Не сохранять"));
        messageBox.setButtonText(QMessageBox::Cancel, tr("Отмена"));

        switch (messageBox.exec()) {
        case QMessageBox::Save:
            on_actionSaveHow_triggered();
            return false;
            break;
        case QMessageBox::Discard:
            // Нажата кнопка Discard
            break;
        case QMessageBox::Cancel:
            // Нажата кнопка Cancel
            return false;
            break;
        default:
            return false;
            break;
        }
    }
    return true;
}


void MainWindow::closeEvent(QCloseEvent* event) // Переопределение выхода
{
    if (check_exit()) {
        event->accept();
    } else {
        event->ignore();
    }
}


bool MainWindow::inputs_is_clear() // Проверка на пустые строки
{
    bool sum = true;

    sum = sum & (ui->lineLaba->text() == default_lineLaba);
    sum = sum & (ui->lineSerial->text() == default_lineSerial);
    sum = sum & (ui->lineVer->text() == default_lineVer);
    sum = sum & (ui->dateEdit->date() == default_dateEdit);
    sum = sum & (ui->comboBoxLanguag->currentIndex() == default_comboBoxLanguag);
    sum = sum & (ui->lineOtherLang->text() == default_lineOtherLang);
    sum = sum & (ui->lineLangShort->text() == default_lineLangShort);
//        qDebug() << sum;

    sum = sum & (ui->comboCOMport->currentText() == default_comboCOMport);
    sum = sum & (ui->lineBAUDrate->currentIndex() == default_lineBAUDrate);
    sum = sum & (ui->lineSTOPbits->currentIndex() == default_lineSTOPbits);
    sum = sum & (ui->lineDATAbits->currentIndex() == default_lineDATAbits);
    sum = sum & (ui->lineRESPONSEtime->text() == default_lineRESPONSEtime);
    sum = sum & (ui->lineADDRESS->text() == default_lineADDRESS);
    sum = sum & (ui->comboParity->currentIndex() == default_comboParity);
//        qDebug() << sum;

    sum = sum & (ui->textVolt->toPlainText() == default_textVolt);
    sum = sum & (ui->textCur->toPlainText() == default_textCur);
    sum = sum & (ui->textDoors->toPlainText() == default_textDoors);
    sum = sum & (ui->textEmergency->toPlainText() == default_textEmergency);
    sum = sum & (ui->textGnd->toPlainText() == default_textGnd);
    sum = sum & (ui->textWorkGnd->toPlainText() == default_textWorkGnd);

    sum = sum & (ui->textNoError->toPlainText() == default_textNoError);
    sum = sum & (ui->textConnect->toPlainText() == default_textConnect);
    sum = sum & (ui->textAddress->toPlainText() == default_textAddress);
    sum = sum & (ui->textData->toPlainText() == default_textData);
    sum = sum & (ui->textInput->toPlainText() == default_textInput);
    sum = sum & (ui->textUnknown->toPlainText() == default_textUnknown);

    sum = sum & (ui->textSerial->toPlainText() == default_textSerial);
    sum = sum & (ui->textController->toPlainText() == default_textController);
//        qDebug() << sum;

    sum = sum & (ui->textVoltEN->toPlainText() == default_textVolt_EN);
    sum = sum & (ui->textCurEN->toPlainText() == default_textCur_EN);
    sum = sum & (ui->textDoorsEN->toPlainText() == default_textDoors_EN);
    sum = sum & (ui->textEmergencyEN->toPlainText() == default_textEmergency_EN);
    sum = sum & (ui->textGndEN->toPlainText() == default_textGnd_EN);
    sum = sum & (ui->textWorkGndEN->toPlainText() == default_textWorkGnd_EN);

    sum = sum & (ui->textNoErrorEN->toPlainText() == default_textNoError_EN);
    sum = sum & (ui->textConnectEN->toPlainText() == default_textConnect_EN);
    sum = sum & (ui->textAddressEN->toPlainText() == default_textAddress_EN);
    sum = sum & (ui->textDataEN->toPlainText() == default_textData_EN);
    sum = sum & (ui->textInputEN->toPlainText() == default_textInput_EN);
    sum = sum & (ui->textUnknownEN->toPlainText() == default_textUnknown_EN);

    sum = sum & (ui->textSerialEN->toPlainText() == default_textSerial_EN);
    sum = sum & (ui->textControllerEN->toPlainText() == default_textController_EN);
//        qDebug() << sum;

    sum = sum & (ui->textVoltOt->toPlainText() == default_text_other);
    sum = sum & (ui->textCurOt->toPlainText() == default_text_other);
    sum = sum & (ui->textDoorsOt->toPlainText() == default_text_other);
    sum = sum & (ui->textEmergencyOt->toPlainText() == default_text_other);
    sum = sum & (ui->textGndOt->toPlainText() == default_text_other);
    sum = sum & (ui->textWorkGndOt->toPlainText() == default_text_other);

    sum = sum & (ui->textNoErrorOT->toPlainText() == default_text_other);
    sum = sum & (ui->textConnectOT->toPlainText() == default_text_other);
    sum = sum & (ui->textAddressOT->toPlainText() == default_text_other);
    sum = sum & (ui->textDataOT->toPlainText() == default_text_other);
    sum = sum & (ui->textInputOT->toPlainText() == default_text_other);
    sum = sum & (ui->textUnknownOT->toPlainText() == default_text_other);

    sum = sum & (ui->textSerialOT->toPlainText() == default_text_other);
    sum = sum & (ui->textControllerOT->toPlainText() == default_text_other);
//        qDebug() << sum;

    sum = sum & (ui->lineLangLaba->text() == default_lineLangLaba);
    sum = sum & (ui->lineLangStart->text() == default_lineLangStart);
    sum = sum & (ui->lineLangStop->text() == default_lineLangStop);
    sum = sum & (ui->lineLangBlock->text() == default_lineLangBlock);
    sum = sum & (ui->lineLangConnect->text() == default_lineLangConnect);
    sum = sum & (ui->lineLangMode->text() == default_lineLangMode);
    sum = sum & (ui->lineLangTip->text() == default_lineLangTip);
    sum = sum & (ui->lineLangReady->text() == default_lineLangReady);
    sum = sum & (ui->lineLangWork->text() == default_lineLangWork);

    sum = sum & (ui->lineLangDate->text() == default_lineLangDate);
    sum = sum & (ui->lineLangLang->text() == default_lineLangLang);
    sum = sum & (ui->lineLangNameLaba->text() == default_lineLangNameLaba);
    sum = sum & (ui->lineLangSerial->text() == default_lineLangSerial);
    sum = sum & (ui->lineLangVersion->text() == default_lineLangVersion);
//        qDebug() << sum;

    return (ui->tabWidget->count() <= MIN_NUM_TAB) & sum;
}

void MainWindow::set_value() // установка значений
{
    /// MAIN VALUE : Получение главных настроек
    ui->lineLaba->setText(config->lab_name);
    ui->lineSerial->setText(config->serial_num);
    ui->lineVer->setText(config->vers);
    ui->lineOtherLang->setText(config->lang_name);
    ui->lineLangShort->setText(config->abbrev);

    // Возможное место ошибок с датой !!!

    // Дата: файл - (D-M-Y)  читаем - (Y-M-D)
    QStringList list_date = (config->product_date).split(".");
    //    qDebug() << list_date;
    if (list_date.length() == 3) {
        if ((list_date[2].toInt()) && (list_date[1].toInt()) && (list_date[0].toInt())) {
            QDate date(list_date[2].toInt(), list_date[1].toInt(), list_date[0].toInt());
            ui->dateEdit->setDate(date);
            //            qDebug() << date;
        }
    } else {
        QMessageBox::warning(this, "Ошибка", "Не удалось прочитать дату");
    }

    // Язык (если язык не понят, то добавление нового Item)
    int index_default_language = ui->comboBoxLanguag->findText(config->language);
    if (index_default_language == -1) {
        QMessageBox::warning(this, "Ошибка", "Не удалось прочитать основной язык");
    }
    ui->comboBoxLanguag->setCurrentIndex(index_default_language);

    /// MODBUS : Получение значений с вкладки MODBUS
    ui->comboCOMport->setCurrentText(config->com_port);
    ui->lineBAUDrate->setCurrentText(config->baud_rate);
    ui->lineSTOPbits->setCurrentText(config->stop_bits);
    ui->lineDATAbits->setCurrentText(config->data_bits);
    ui->lineRESPONSEtime->setText(config->response_time);
    ui->lineADDRESS->setText(config->adress);

    QString md = config->parity;
    if (md == "Even parity")
        ui->comboParity->setCurrentIndex(0);
    else if (md == "Odd parity")
        ui->comboParity->setCurrentIndex(1);
    else if (md == "Space parity")
        ui->comboParity->setCurrentIndex(2);
    else if (md == "Mark parity")
        ui->comboParity->setCurrentIndex(3);
    else if (md == "No parity")
        ui->comboParity->setCurrentIndex(4);
    else
        qWarning("Ошибка: не найден режим MODBUS");

    md = config->baud_rate;
    int cur_index = ui->lineBAUDrate->findText(md);
    if (cur_index != -1)
        ui->lineBAUDrate->setCurrentIndex(cur_index);
    else
        qWarning("Ошибка: не найден параметр Baud rate в MODBUS");

    md = config->stop_bits;
    cur_index = ui->lineSTOPbits->findText(md);
    if (cur_index != -1)
        ui->lineSTOPbits->setCurrentIndex(cur_index);
    else
        qWarning("Ошибка: не найден параметр Stop bits в MODBUS");

    md = config->data_bits;
    cur_index = ui->lineDATAbits->findText(md);
    if (cur_index != -1)
        ui->lineDATAbits->setCurrentIndex(cur_index);
    else
        qWarning("Ошибка: не найден параметр Data bits в MODBUS");

    ///
    /// TIPS
    qDebug() << inf_conf->msg_no_error << inf_conf->msg_no_error_en << inf_conf->msg_no_error_add;
    ui->textVolt->setText(inf_conf->voltage);
    ui->textCur->setText(inf_conf->current);
    ui->textDoors->setText(inf_conf->doors);
    ui->textEmergency->setText(inf_conf->b_emrg);
    ui->textGnd->setText(inf_conf->gnd);
    ui->textWorkGnd->setText(inf_conf->work_gnd);

    ui->textNoError->setText(inf_conf->msg_no_error);
    ui->textConnect->setText(inf_conf->msg_com_connect_err);
    ui->textAddress->setText(inf_conf->msg_invalid_addr);
    ui->textData->setText(inf_conf->msg_invalid_modbus);
    ui->textInput->setText(inf_conf->msg_invalid_input);
    ui->textUnknown->setText(inf_conf->msg_unknown);

    ui->textSerial->setText(inf_conf->msg_serial);
    ui->textController->setText(inf_conf->msg_version);

    //
    ui->textVoltEN->setText(inf_conf->voltage_en);
    ui->textCurEN->setText(inf_conf->current_en);
    ui->textDoorsEN->setText(inf_conf->doors_en);
    ui->textEmergencyEN->setText(inf_conf->b_emrg_en);
    ui->textGndEN->setText(inf_conf->gnd_en);
    ui->textWorkGndEN->setText(inf_conf->work_gnd_en);

    ui->textNoErrorEN->setText(inf_conf->msg_no_error_en);
    ui->textConnectEN->setText(inf_conf->msg_com_connect_err_en);
    ui->textAddressEN->setText(inf_conf->msg_invalid_addr_en);
    ui->textDataEN->setText(inf_conf->msg_invalid_modbus_en);
    ui->textInputEN->setText(inf_conf->msg_invalid_input_en);
    ui->textUnknownEN->setText(inf_conf->msg_unknown_en);

    ui->textSerialEN->setText(inf_conf->msg_serial_en);
    ui->textControllerEN->setText(inf_conf->msg_version_en);

    //
    ui->textVoltOt->setText(inf_conf->voltage_add);
    ui->textCurOt->setText(inf_conf->current_add);
    ui->textDoorsOt->setText(inf_conf->doors_add);
    ui->textEmergencyOt->setText(inf_conf->b_emrg_add);
    ui->textGndOt->setText(inf_conf->gnd_add);
    ui->textWorkGndOt->setText(inf_conf->work_gnd_add);

    ui->textNoErrorOT->setText(inf_conf->msg_no_error_add);
    ui->textConnectOT->setText(inf_conf->msg_com_connect_err_add);
    ui->textAddressOT->setText(inf_conf->msg_invalid_addr_add);
    ui->textDataOT->setText(inf_conf->msg_invalid_modbus_add);
    ui->textInputOT->setText(inf_conf->msg_invalid_input_add);
    ui->textUnknownOT->setText(inf_conf->msg_unknown_add);

    ui->textSerialOT->setText(inf_conf->msg_serial_add);
    ui->textControllerOT->setText(inf_conf->msg_version_add);

    /// TRANSLATE
    ui->lineLangLaba->setText(but_conf->about_lab);
    ui->lineLangStart->setText(but_conf->b_start);
    ui->lineLangStop->setText(but_conf->b_stop);
    ui->lineLangBlock->setText(but_conf->blocs);
    ui->lineLangConnect->setText(but_conf->connects);
    ui->lineLangMode->setText(but_conf->mode_choice);
    ui->lineLangTip->setText(but_conf->clues);
    ui->lineLangReady->setText(but_conf->willingness);
    ui->lineLangWork->setText(but_conf->b_work);

    ui->lineLangDate->setText(but_conf->tr_date_production);
    ui->lineLangLang->setText(but_conf->tr_default_lang);
    ui->lineLangNameLaba->setText(but_conf->tr_name);
    ui->lineLangSerial->setText(but_conf->tr_serial_num);
    ui->lineLangVersion->setText(but_conf->tr_control_vers);

    /// MODES : получение  значений режимов
    //    qDebug() << config->Mode;
    if (config->Mode != QStringList("")) {
        //        qDebug() << "Read MODES";
        set_value_mode(config->Mode);
    } else {
        //        qDebug() << "Not read MODES";
    }
}


void MainWindow::set_value_mode(QStringList& _Mode)
{ // установка значений режимов
    for (int i = 0; i < _Mode.length(); i++) {
        Mode_chan* mode = new Mode_chan(PATH_DEVAULT_SAVE, _Mode[i]);

        if (mode->readed != "True") {
            QMessageBox::warning(this, "Ошибка открытия режима", mode->readed);
        };

        ui->tabWidget->addTab(new Mode(), mode->m_name);
        int ind = ui->tabWidget->count() - 1;

        //        qDebug() << ui->tabWidget->widget(ind)->children();
        ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeName")->setText(mode->m_name);
        ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeNameEn")->setText(mode->m_name_en);
        ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeNameOt")->setText(mode->m_name_add);

        ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeFile")->setText(mode->exe_path);
        ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeBlock")->setText(mode->modbus_in); // !!! ????
        ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeOutput")->setText(mode->modbus_out);
        ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeImage")->setText(mode->img_path);

        ui->tabWidget->widget(ind)->findChild<QTextEdit*>("textMode")->setText(mode->clue);
        ui->tabWidget->widget(ind)->findChild<QTextEdit*>("textModeEN")->setText(mode->clue_en);
        ui->tabWidget->widget(ind)->findChild<QTextEdit*>("textModeOT")->setText(mode->clue_add);

        QString radiobuttonTrue = "1", radiobuttonFalse = "0";
        if (radiobuttonTrue.indexOf(mode->m_enable) != -1) {
            ui->tabWidget->widget(ind)->findChild<QRadioButton*>("radioButtonYes")->setChecked(true);
        } else if (radiobuttonFalse.indexOf(mode->m_enable) != -1) {
            ui->tabWidget->widget(ind)->findChild<QRadioButton*>("radioButtonNo")->setChecked(true);
        }
        delete mode;
    }
}

void MainWindow::read_config(QString& file) // чтение конфиг файла в приложение
{
    config = new Sets();
    inf_conf = new Inf_Msg();
    but_conf = new Butts();

    config->read(file);
    but_conf->read(file);
    inf_conf->read(file);

    if (config->readed != QString("True")) {
        ui->statusbar->showMessage(QString("Ошибка открытия: ") + file);
        QMessageBox::warning(this, "Ошибка", config->readed);
    } else {
        if (delete_all_mode()) {
            ui->statusbar->showMessage(QString("Работаем с ") + file);
            set_value();
        } else
            QMessageBox::information(this, "Файл не открыт", "Вы отказались открыть файл");
    }

    delete config;
    delete inf_conf;
    delete but_conf;
}

bool MainWindow::delete_all_mode() // удаление всех вкладок режимов
{
    int len = ui->tabWidget->count();
    if (len > MIN_NUM_TAB) {
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Удаление вкладок",
            "Открыть файл и удалить ранее используемые данные?");
        if (reply == QMessageBox::Yes) {
            for (int i = MIN_NUM_TAB; i < len; i++) {
                ui->tabWidget->removeTab(MIN_NUM_TAB);
            }
            return true;
        }
        if (reply == QMessageBox::No)
            return false;
    }
    return true;
}

void MainWindow::make_new_tab(QString &tab_name) // создание новой вкладки режима
{
    if (ui->tabWidget->count() < MAX_NUM_TAB) {

        Mode* mode = new Mode();
        int index_tab = ui->tabWidget->addTab(mode, tab_name);
        ui->tabWidget->setCurrentIndex(index_tab);

        ui->tabWidget->widget(index_tab)->findChild<QLineEdit*>("lineModeName")->setText(tab_name);

        connect(mode, SIGNAL(change_textModeName()), this, SLOT(rename_tab()));
    }
}


void MainWindow::on_pushModeAdd_clicked() // нажатие кнопки Добавить вкладку режима
{
    QString tab_name = QString("Режим %0").arg(ui->tabWidget->count() - MIN_NUM_TAB + 1);
    make_new_tab(tab_name);
}

void MainWindow::rename_tab() //слот для изменения названия Tab
{
    int index = ui->tabWidget->currentIndex();
    QString text = ui->tabWidget->widget(index)->findChild<QLineEdit*>("lineModeName")->text();
    if (text == "")
        text = QString("Режим %0").arg(index - MIN_NUM_TAB + 1);
    ui->tabWidget->setTabText(index, text);
    //    qDebug() << text;
}

void MainWindow::on_pushModeDelete_clicked() // нажатие кнопки Удаление вкладки режима
{
    int index = ui->tabWidget->currentIndex();
    if (index >= MIN_NUM_TAB) {
        QString name_tab = ui->tabWidget->tabText(index);
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, ("Удаление вкладки"),
            QString("Можно удалить режим '%0' ?").arg(name_tab));
        if (reply == QMessageBox::Yes) {
            ui->tabWidget->removeTab(index);
        }
    }
}


void MainWindow::on_actionOpen_triggered() // нажатие кнопки Открыть файл
{
    PATH_DEVAULT_SAVE = QFileDialog::getOpenFileName(this, "Открыть конфигурационный файл...", QDir::currentPath());
    if (!PATH_DEVAULT_SAVE.isEmpty() && !PATH_DEVAULT_SAVE.isNull()) {
        read_config(PATH_DEVAULT_SAVE);
    } else {
        //        qDebug() << "Отмена";
        ui->statusbar->showMessage(QString("Отмена"));
    }
}


void MainWindow::on_actionSave_triggered() // нажатие кнопки Сохранить
{
    on_pushButtonSave_clicked();
}

void MainWindow::on_actionExit_triggered() // нажатие кнопки Выход
{
    //    qDebug() << "Close the MainWindow";
    this->close();
}


void MainWindow::on_pushButtonSave_clicked() // нажатие кнопки Сохранить
{
    if (PATH_DEVAULT_SAVE == "") {
        PATH_DEVAULT_SAVE = QFileDialog::getSaveFileName(this, "Сохранить конфигурационный файл...",
            QDir::currentPath(), "Text files (*.txt)");
        //        qDebug() << PATH_DEVAULT_SAVE;
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
    QString other_language = ui->lineOtherLang->text();
    QString other_short_lang = ui->lineLangShort->text();

    QString comport = ui->comboCOMport->currentText();
    QString res = "";
    for (int iter = 0; iter < comport.size(); iter++) {
        if (comport[iter].isDigit()) {
            res += comport[iter];
        }
    }
    comport = res;
    res = "";

    QString baud = ui->lineBAUDrate->currentText();
    QString stopbits = ui->lineSTOPbits->currentText();
    QString databits = ui->lineDATAbits->currentText();
    QString parity = ui->comboParity->currentText();
    QString response = ui->lineRESPONSEtime->text();
    QString address = ui->lineADDRESS->text();

    save_conf = new Save_to_config1(PATH_DEVAULT_SAVE);
    save_conf->save_main_param(&laba, &serial, &date, &version,
        &language, &comport, &baud, &stopbits,
        &databits, &parity, &response, &address, &other_language, &other_short_lang);

    QStringList line_lang;
    line_lang << ui->lineLangLaba->text();
    line_lang << ui->lineLangStart->text();
    line_lang << ui->lineLangStop->text();
    line_lang << ui->lineLangMode->text();
    line_lang << ui->lineLangConnect->text();
    line_lang << ui->lineLangBlock->text();
    line_lang << ui->lineLangTip->text();

    line_lang << ui->lineLangNameLaba->text();
    line_lang << ui->lineLangSerial->text();
    line_lang << ui->lineLangDate->text();
    line_lang << ui->lineLangVersion->text();
    line_lang << ui->lineLangLang->text();
    line_lang << ui->lineLangReady->text();
    line_lang << ui->lineLangWork->text();

    save_conf->save_btts(&line_lang);

    QStringList source;
    source << ui->textVolt->toPlainText();
    source << ui->textVoltEN->toPlainText();
    source << ui->textVoltOt->toPlainText();

    source << ui->textCur->toPlainText();
    source << ui->textCurEN->toPlainText();
    source << ui->textCurOt->toPlainText();

    source << ui->textDoors->toPlainText();
    source << ui->textDoorsEN->toPlainText();
    source << ui->textDoorsOt->toPlainText();

    source << ui->textEmergency->toPlainText();
    source << ui->textEmergencyEN->toPlainText();
    source << ui->textEmergencyOt->toPlainText();

    source << ui->textGnd->toPlainText();
    source << ui->textGndEN->toPlainText();
    source << ui->textGndOt->toPlainText();

    source << ui->textWorkGnd->toPlainText();
    source << ui->textWorkGndEN->toPlainText();
    source << ui->textWorkGndOt->toPlainText();

    source << ui->textNoError->toPlainText();
    source << ui->textNoErrorEN->toPlainText();
    source << ui->textNoErrorOT->toPlainText();

    source << ui->textConnect->toPlainText();
    source << ui->textConnectEN->toPlainText();
    source << ui->textConnectOT->toPlainText();

    source << ui->textAddress->toPlainText();
    source << ui->textAddressEN->toPlainText();
    source << ui->textAddressOT->toPlainText();

    source << ui->textInput->toPlainText();
    source << ui->textInputEN->toPlainText();
    source << ui->textInputOT->toPlainText();

    source << ui->textData->toPlainText();
    source << ui->textDataEN->toPlainText();
    source << ui->textDataOT->toPlainText();

    source << ui->textUnknown->toPlainText();
    source << ui->textUnknownEN->toPlainText();
    source << ui->textUnknownOT->toPlainText();

    source << ui->textSerial->toPlainText();
    source << ui->textSerialEN->toPlainText();
    source << ui->textSerialOT->toPlainText();

    source << ui->textController->toPlainText();
    source << ui->textControllerEN->toPlainText();
    source << ui->textControllerOT->toPlainText();

    qDebug() << source;
    save_conf->save_inf_msg(&source);

    QString name, name_en, name_ot, file, block, output, valible, image, tip, tip_en, tip_ot;
    for (int ind = MIN_NUM_TAB; ind < ui->tabWidget->count(); ind++) {
        name = ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeName")->text();
        name_en = ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeNameEn")->text();
        name_ot = ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeNameOt")->text();
        file = ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeFile")->text();
        block = ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeBlock")->text();
        output = ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeOutput")->text();
        image = ui->tabWidget->widget(ind)->findChild<QLineEdit*>("lineModeImage")->text();
        tip = ui->tabWidget->widget(ind)->findChild<QTextEdit*>("textMode")->toPlainText();
        tip_en = ui->tabWidget->widget(ind)->findChild<QTextEdit*>("textModeEN")->toPlainText();
        tip_ot = ui->tabWidget->widget(ind)->findChild<QTextEdit*>("textModeOT")->toPlainText();

        if (ui->tabWidget->widget(ind)->findChild<QRadioButton*>("radioButtonYes")->isChecked()) {
            valible = "1";
        } else if (ui->tabWidget->widget(ind)->findChild<QRadioButton*>("radioButtonNo")->isChecked()) {
            valible = "0";
        } else {
            valible = "-";
        }
        save_conf->save_mode(&name, &name_en, &name_ot, &valible, &output, &block, &image, &file, &tip, &tip_en, &tip_ot); //???
    }

    delete save_conf;

    ui->statusbar->showMessage(QString("Работаем с ") + PATH_DEVAULT_SAVE);
    QMessageBox::information(this, "Сохранение", "Файл сохранился");
}


void MainWindow::set_list_com_QComboBox(QComboBox* com_box) // ввод COM port во вкладке MODBUS
{
    const auto port_info = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo& info : port_info) {
        QString port_description = info.description();
        QString port_manufacturer = info.manufacturer();
        QString port_name = info.portName();
        com_box->addItem(port_name
                + (!port_description.isEmpty() ? " (" + port_description : "")
                + (!port_manufacturer.isEmpty() ? ", " + port_manufacturer + ")" : ""),
            port_name);
    }
}

void MainWindow::on_updateCOM_clicked() // обновление списка COM port
{
    ui->comboCOMport->clear();
    set_list_com_QComboBox(ui->comboCOMport);
    ui->comboCOMport->setCurrentText(default_comboCOMport);
}


void MainWindow::set_default_values() // Установка значений по умолчанию
{
    ///---------MAIN---------
    ui->lineVer->setText(default_lineVer);
    ui->lineLaba->setText(default_lineLaba);
    ui->lineSerial->setText(default_lineSerial);
    ui->dateEdit->setDate(default_dateEdit);
    ui->comboBoxLanguag->setCurrentIndex(default_comboBoxLanguag);
    ui->lineOtherLang->setText(default_lineOtherLang);
    ui->lineLangShort->setText(default_lineLangShort);

    on_updateCOM_clicked();

    ///--------Modbus---------
    ui->lineBAUDrate->setCurrentIndex(default_lineBAUDrate);
    ui->lineSTOPbits->setCurrentIndex(default_lineSTOPbits);
    ui->lineDATAbits->setCurrentIndex(default_lineDATAbits);
    ui->lineRESPONSEtime->setText(default_lineRESPONSEtime);
    ui->lineADDRESS->setText(default_lineADDRESS);
    ui->comboParity->setCurrentIndex(default_comboParity);

    ///--------Block-----------
    ui->textVolt->setText(default_textVolt);
    ui->textCur->setText(default_textCur);
    ui->textDoors->setText(default_textDoors);
    ui->textEmergency->setText(default_textEmergency);
    ui->textGnd->setText(default_textGnd);
    ui->textWorkGnd->setText(default_textWorkGnd);
    ui->textNoError->setText(default_textNoError);
    ui->textConnect->setText(default_textConnect);
    ui->textAddress->setText(default_textAddress);
    ui->textInput->setText(default_textInput);
    ui->textData->setText(default_textData);
    ui->textUnknown->setText(default_textUnknown);
    ui->textSerial->setText(default_textSerial);
    ui->textController->setText(default_textController);

    ui->textVoltEN->setText(default_textVolt_EN);
    ui->textCurEN->setText(default_textCur_EN);
    ui->textDoorsEN->setText(default_textDoors_EN);
    ui->textEmergencyEN->setText(default_textEmergency_EN);
    ui->textGndEN->setText(default_textGnd_EN);
    ui->textWorkGndEN->setText(default_textWorkGnd_EN);
    ui->textNoErrorEN->setText(default_textNoError_EN);
    ui->textConnectEN->setText(default_textConnect_EN);
    ui->textAddressEN->setText(default_textAddress_EN);
    ui->textInputEN->setText(default_textInput_EN);
    ui->textDataEN->setText(default_textData_EN);
    ui->textUnknownEN->setText(default_textUnknown_EN);
    ui->textSerialEN->setText(default_textSerial_EN);
    ui->textControllerEN->setText(default_textController_EN);

    ui->textVoltOt->setText(default_text_other);
    ui->textCurOt->setText(default_text_other);
    ui->textDoorsOt->setText(default_text_other);
    ui->textEmergencyOt->setText(default_text_other);
    ui->textGndOt->setText(default_text_other);
    ui->textWorkGndOt->setText(default_text_other);
    ui->textNoErrorOT->setText(default_text_other);
    ui->textConnectOT->setText(default_text_other);
    ui->textAddressOT->setText(default_text_other);
    ui->textInputOT->setText(default_text_other);
    ui->textDataOT->setText(default_text_other);
    ui->textUnknownOT->setText(default_text_other);
    ui->textSerialOT->setText(default_text_other);
    ui->textControllerOT->setText(default_text_other);

    ///---------Translate-------
    ui->lineLangLaba->setText(default_lineLangLaba);
    ui->lineLangStart->setText(default_lineLangStart);
    ui->lineLangStop->setText(default_lineLangStop);
    ui->lineLangMode->setText(default_lineLangMode);
    ui->lineLangConnect->setText(default_lineLangConnect);
    ui->lineLangBlock->setText(default_lineLangBlock);
    ui->lineLangTip->setText(default_lineLangTip);

    ui->lineLangDate->setText(default_lineLangDate);
    ui->lineLangLang->setText(default_lineLangLang);
    ui->lineLangNameLaba->setText(default_lineLangNameLaba);
    ui->lineLangSerial->setText(default_lineLangSerial);
    ui->lineLangVersion->setText(default_lineLangVersion);

    ui->lineLangReady->setText(default_lineLangReady);
    ui->lineLangWork->setText(default_lineLangWork);
}


void MainWindow::delete_all_values() // Очищение всех полей (выставление значений по умолчанию)
{
    if (inputs_is_clear() == false) {
        QMessageBox messageBox(QMessageBox::Question,
            tr("Удаление"),
            tr("Вы уверены, что хотите все очистить?"),
            QMessageBox::Yes | QMessageBox::No,
            this);
        messageBox.setButtonText(QMessageBox::Yes, tr("Да"));
        messageBox.setButtonText(QMessageBox::No, tr("Нет"));

        if (messageBox.exec() == QMessageBox::No) {
            return;
        }
    }

    int len = ui->tabWidget->count();
    if (len > MIN_NUM_TAB) {
        for (int i = MIN_NUM_TAB; i < len; i++) {
            ui->tabWidget->removeTab(MIN_NUM_TAB);
        }
    }

    set_default_values();
}


void MainWindow::on_pushButtonDeleteAll_clicked() // кнопка Удаление всех значений
{
    delete_all_values();
}


void MainWindow::on_actionSaveHow_triggered() // кнопка Сохранить как
{
    PATH_DEVAULT_SAVE = "";
    on_pushButtonSave_clicked();
    ui->statusbar->showMessage("");
}

void MainWindow::on_actionNew_triggered() // кнопка Создать новый
{
    PATH_DEVAULT_SAVE = "";
    delete_all_values();
    ui->statusbar->showMessage("");
}

void MainWindow::on_tabWidget_currentChanged(int index) // Скрытие-показ кнопки Удалить и Добавить режим
{
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

void MainWindow::change_textEdit(QTextEdit* text) // Обработка текстового ввода (ограничение ввода символов)
{
    QString textContent = (text->toPlainText()).simplified();

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

void MainWindow::on_comboCOMport_currentTextChanged(const QString& arg1)
{
    QString com_port = (arg1.split(" "))[0];
    ui->comboCOMport->setCurrentText(com_port);
}


void MainWindow::on_lineRESPONSEtime_editingFinished()
{
    change_lineResponse();
}


void MainWindow::change_lineResponse() // Обработка ввода Response во вкладке MODBUS
{
    int num = ui->lineRESPONSEtime->text().toInt();
    if (num < 50){
        QMessageBox::warning(this, "Ошибка", "Значение не может быть меньше 50");
        ui->lineRESPONSEtime->setText("50");
    }
}

void MainWindow::on_lineADDRESS_editingFinished()
{
    change_lineADDRESS();
}


void MainWindow::change_lineADDRESS() // Обработка ввода Address во вкладке MODBUS
{
    int num = ui->lineADDRESS->text().toInt();
    if (num > 247){
        QMessageBox::warning(this, "Ошибка", "Значение не может быть больше 247");
        ui->lineADDRESS->setText("247");
    }
}


