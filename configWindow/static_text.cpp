#include <QDate>
#include <QString>

// Значения по умолчанию

const QString default_lineVer = "";
const QString default_lineLaba = "";
const QString default_lineSerial = "";
const QDate default_dateEdit = QDate(2021, 1, 1);
const int default_comboBoxLanguag = 0;
const QString default_lineOtherLang = "";
const QString default_lineLangShort = "";

const QString default_comboCOMport = "";
const int default_lineBAUDrate = 4; //19200
const int default_lineSTOPbits = 0; //1 stop bit
const int default_lineDATAbits = 3; //8 data bits
const QString default_lineRESPONSEtime = "500";
const QString default_lineADDRESS = "";
const int default_comboParity = 4; //No Parity

const QString default_textVolt = "";
const QString default_textCur = "";
const QString default_textDoors = "";
const QString default_textEmergency = "";
const QString default_textGnd = "";
const QString default_textWorkGnd = "";
const QString default_textNoError = "Корректная работа Modbus модуля программы.";
const QString default_textConnect = "Ошибка подключения к COM порту.";
const QString default_textAddress = "COM порт подключен, но устройство не отвечает.";
const QString default_textData = "Некорректная работа Modbus модуля программы.";
const QString default_textInput = "Некорректная передача параметров в Modbus модуль программы.";
const QString default_textUnknown = "Неизвестная ошибка Modbus.";
const QString default_textSerial = "Серийный номер лаборатории, указанный в программе, не совпадает с установленным на данном устройстве";
const QString default_textController = "Версия ПО контроллера, указанная в программе, не совпадает с установленной на данном устройстве";

const QString default_textVolt_EN = "";
const QString default_textCur_EN = "";
const QString default_textDoors_EN = "";
const QString default_textEmergency_EN = "";
const QString default_textGnd_EN = "";
const QString default_textWorkGnd_EN = "";
const QString default_textNoError_EN = "Correct work of the Modbus module.";
const QString default_textConnect_EN = "COM connection error.";
const QString default_textAddress_EN = "The COM port is connected, but the device does not respond.";
const QString default_textData_EN = "Incorrect operation of the Modbus module of the program.";
const QString default_textInput_EN = "Incorrect transmission of parameters to Modbus program module.";
const QString default_textUnknown_EN = "Unknown Modbus error.";
const QString default_textSerial_EN = "The serial number of the laboratory specified in the program does not match the one installed on this device";
const QString default_textController_EN = "The controller software version specified in the program does not match the one installed on this device";

const QString default_text_other = "";

const QString default_lineLangLaba = "";
const QString default_lineLangStart = "";
const QString default_lineLangStop = "";
const QString default_lineLangMode = "";
const QString default_lineLangConnect = "";
const QString default_lineLangBlock = "";
const QString default_lineLangTip = "";
const QString default_lineLangReady = "";
const QString default_lineLangWork = "";
const QString default_lineLangDate = "";
const QString default_lineLangLang = "";
const QString default_lineLangNameLaba = "";
const QString default_lineLangSerial = "";
const QString default_lineLangVersion = "";
