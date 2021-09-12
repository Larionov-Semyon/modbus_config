/********************************************************************************
** Form generated from reading UI file 'mode.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODE_H
#define UI_MODE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Mode
{
public:
    QHBoxLayout *horizontalLayout_3;
    QGridLayout *gridLayout;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineModeFile;
    QLineEdit *lineModeOutput;
    QTextEdit *textMode;
    QLabel *label_12;
    QLabel *label;
    QFrame *line_2;
    QLineEdit *lineModeBlock;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QRadioButton *radioButtonYes;
    QRadioButton *radioButtonNo;
    QLabel *label_4;
    QLineEdit *lineModeNameOt;
    QPushButton *buttonModeImage;
    QLabel *label_2;
    QLabel *label_8;
    QLineEdit *lineModeNameEn;
    QLineEdit *lineModeName;
    QLabel *label_3;
    QFrame *line;
    QFrame *line_3;
    QLabel *label_10;
    QLabel *label_6;
    QLabel *label_9;
    QTextEdit *textModeOT;
    QPushButton *buttonModeFile;
    QLabel *label_7;
    QTextEdit *textModeEN;
    QLineEdit *lineModeImage;
    QLabel *label_5;

    void setupUi(QWidget *Mode)
    {
        if (Mode->objectName().isEmpty())
            Mode->setObjectName(QString::fromUtf8("Mode"));
        Mode->resize(839, 440);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Mode->sizePolicy().hasHeightForWidth());
        Mode->setSizePolicy(sizePolicy);
        Mode->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"	background-color:#ececec;\n"
"}\n"
"QTextEdit {\n"
"	border: 1px; border-radius: 5px;\n"
"	border-style: solid;\n"
"	border-color: rgba(0, 130, 255, 255);\n"
"	padding: 2px 1px 1px 1px;\n"
"}\n"
"QPlainTextEdit {\n"
"	border-width: 1px; border-radius: 4px;\n"
"	border-style: solid;\n"
"	border-color: rgba(0, 130, 255, 255);\n"
"}\n"
"QToolButton {\n"
"	border-style: solid;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(217, 217, 217), stop:1 rgb(227, 227, 227));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(227, 227, 227), stop:1 rgb(217, 217, 217));\n"
"	border-bottom-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	color: rgb(0,0,0);\n"
"	padding: 2"
                        "px;\n"
"	background-color: rgb(255,255,255);\n"
"}\n"
"QToolButton:hover{\n"
"	border-style: solid;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(195, 195, 195), stop:1 rgb(222, 222, 222));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(197, 197, 197), stop:1 rgb(227, 227, 227));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(227, 227, 227), stop:1 rgb(197, 197, 197));\n"
"	border-bottom-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(195, 195, 195), stop:1 rgb(222, 222, 222));\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	color: rgb(0,0,0);\n"
"	padding: 2px;\n"
"	background-color: rgb(255,255,255);\n"
"}\n"
"QToolButton:pressed{\n"
"	border-style: solid;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0, "
                        "y1:0.5, x2:1, y2:0.5, stop:0 rgb(217, 217, 217), stop:1 rgb(227, 227, 227));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(227, 227, 227), stop:1 rgb(217, 217, 217));\n"
"	border-bottom-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	color: rgb(0,0,0);\n"
"	padding: 2px;\n"
"	background-color: rgb(142,142,142);\n"
"}\n"
"QPushButton{\n"
"	border-style: solid;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(217, 217, 217), stop:1 rgb(227, 227, 227));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(227, 227, 227), stop:1 rgb(217, 217, 217));\n"
"	border-bottom-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 "
                        "rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	color: rgb(0,0,0);\n"
"	padding: 2px;\n"
"	background-color: rgb(255,255,255);\n"
"}\n"
"QPushButton::default{\n"
"	border-style: solid;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(217, 217, 217), stop:1 rgb(227, 227, 227));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(227, 227, 227), stop:1 rgb(217, 217, 217));\n"
"	border-bottom-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	color: rgb(0,0,0);\n"
"	padding: 2px;\n"
"	background-color: rgb(255,255,255);\n"
"}\n"
"QPushButton:hover{\n"
"	border-style: solid;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0."
                        "5, y1:1, x2:0.5, y2:0, stop:0 rgb(195, 195, 195), stop:1 rgb(222, 222, 222));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(197, 197, 197), stop:1 rgb(227, 227, 227));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(227, 227, 227), stop:1 rgb(197, 197, 197));\n"
"	border-bottom-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(195, 195, 195), stop:1 rgb(222, 222, 222));\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	color: #FFFFFF;\n"
"	padding: 2px;\n"
"    background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}\n"
"QPushButton:pressed{\n"
"	border-style: solid;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(217, 217, 217), stop:"
                        "1 rgb(227, 227, 227));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(227, 227, 227), stop:1 rgb(217, 217, 217));\n"
"	border-bottom-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	color: #FFFFFF;\n"
"	padding: 2px;\n"
"  	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 88, 212, 255), stop:1 rgba(0, 74, 179, 255));\n"
"}\n"
"QPushButton:disabled{\n"
"	border-style: solid;\n"
"	border-top-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(217, 217, 217), stop:1 rgb(227, 227, 227));\n"
"	border-left-color: qlineargradient(spread:pad, x1:0, y1:0.5, x2:1, y2:0.5, stop:0 rgb(227, 227, 227), stop:1 rgb(217, 217, 217));\n"
"	border-bottom-color: qlineargra"
                        "dient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgb(215, 215, 215), stop:1 rgb(222, 222, 222));\n"
"	border-width: 1px;\n"
"	border-radius: 5px;\n"
"	color: #808086;\n"
"	padding: 2px;\n"
"	background-color: rgb(142,142,142);\n"
"}\n"
"QLineEdit {\n"
"	border-width: 1px; border-radius: 4px;\n"
"	border-style: solid;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}\n"
"QLabel {\n"
"	color: #000000;\n"
"}\n"
"QLCDNumber {\n"
"	color: rgb(0, 113, 255, 255);\n"
"}\n"
"QProgressBar {\n"
"	text-align: center;\n"
"	color: rgb(240, 240, 240);\n"
"	border-width: 1px; \n"
"	border-radius: 10px;\n"
"	border-color: rgb(230, 230, 230);\n"
"	border-style: solid;\n"
"	background-color:rgb(207,207,207);\n"
"}\n"
"QProgressBar::chunk {\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(49, 147, 250, 255), stop:1 rgba(34, 142, 255, 255));\n"
"	border-radius: 10px;\n"
"}\n"
"QMenuBar {\n"
""
                        "	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(207, 209, 207, 255), stop:1 rgba(230, 229, 230, 255));\n"
"}\n"
"QMenuBar::item {\n"
"	color: #000000;\n"
"  	spacing: 3px;\n"
"  	padding: 1px 4px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(207, 209, 207, 255), stop:1 rgba(230, 229, 230, 255));\n"
"}\n"
"\n"
"QMenuBar::item:selected {\n"
"  	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"	color: #FFFFFF;\n"
"}\n"
"QMenu::item:selected {\n"
"	border-style: solid;\n"
"	border-top-color: transparent;\n"
"	border-right-color: transparent;\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"	border-bottom-color: transparent;\n"
"	border-left-width: 2px;\n"
"	color: #000000;\n"
"	padding-left:15px;\n"
"	padding-top:4px;\n"
"	padding-bottom:4px;"
                        "\n"
"	padding-right:7px;\n"
"}\n"
"QMenu::item {\n"
"	border-style: solid;\n"
"	border-top-color: transparent;\n"
"	border-right-color: transparent;\n"
"	border-left-color: transparent;\n"
"	border-bottom-color: transparent;\n"
"	border-bottom-width: 1px;\n"
"	color: #000000;\n"
"	padding-left:17px;\n"
"	padding-top:4px;\n"
"	padding-bottom:4px;\n"
"	padding-right:7px;\n"
"}\n"
"QTabWidget {\n"
"	color:rgb(0,0,0);\n"
"	background-color:#000000;\n"
"}\n"
"QTabWidget::pane {\n"
"		border-color: rgb(223,223,223);\n"
"		background-color:rgb(226,226,226);\n"
"		border-style: solid;\n"
"		border-width: 2px;\n"
"    	border-radius: 6px;\n"
"}\n"
"QTabBar::tab:first {\n"
"	border-style: solid;\n"
"	border-left-width:1px;\n"
"	border-right-width:0px;\n"
"	border-top-width:1px;\n"
"	border-bottom-width:1px;\n"
"	border-top-color: rgb(209,209,209);\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(209, 209, 209, 209), stop:1 rgba(229, 229, 229, 229));\n"
"	border-bottom-color: rg"
                        "b(229,229,229);\n"
"	border-top-left-radius: 4px;\n"
"	border-bottom-left-radius: 4px;\n"
"	color: #000000;\n"
"	padding: 3px;\n"
"	margin-left:0px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(247, 247, 247, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
"QTabBar::tab:last {\n"
"	border-style: solid;\n"
"	border-width:1px;\n"
"	border-top-color: rgb(209,209,209);\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(209, 209, 209, 209), stop:1 rgba(229, 229, 229, 229));\n"
"	border-right-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(209, 209, 209, 209), stop:1 rgba(229, 229, 229, 229));\n"
"	border-bottom-color: rgb(229,229,229);\n"
"	border-top-right-radius: 4px;\n"
"	border-bottom-right-radius: 4px;\n"
"	color: #000000;\n"
"	padding: 3px;\n"
"	margin-left:0px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(247, 247, 247, 255), stop:1 rgba(255, 255, 25"
                        "5, 255));\n"
"}\n"
"QTabBar::tab {\n"
"	border-style: solid;\n"
"	border-top-width:1px;\n"
"	border-bottom-width:1px;\n"
"	border-left-width:1px;\n"
"	border-top-color: rgb(209,209,209);\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(209, 209, 209, 209), stop:1 rgba(229, 229, 229, 229));\n"
"	border-bottom-color: rgb(229,229,229);\n"
"	color: #000000;\n"
"	padding: 3px;\n"
"	margin-left:0px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(247, 247, 247, 255), stop:1 rgba(255, 255, 255, 255));\n"
"}\n"
"QTabBar::tab:selected, QTabBar::tab:last:selected, QTabBar::tab:hover {\n"
"  	border-style: solid;\n"
"  	border-left-width:1px;\n"
"	border-right-color: transparent;\n"
"	border-top-color: rgb(209,209,209);\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(209, 209, 209, 209), stop:1 rgba(229, 229, 229, 229));\n"
"	border-bottom-color: rgb(229,229,229);\n"
"	color: #FFFFFF;\n"
"	pad"
                        "ding: 3px;\n"
"	margin-left:0px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}\n"
"\n"
"QTabBar::tab:selected, QTabBar::tab:first:selected, QTabBar::tab:hover {\n"
"  	border-style: solid;\n"
"  	border-left-width:1px;\n"
"  	border-bottom-width:1px;\n"
"  	border-top-width:1px;\n"
"	border-right-color: transparent;\n"
"	border-top-color: rgb(209,209,209);\n"
"	border-left-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(209, 209, 209, 209), stop:1 rgba(229, 229, 229, 229));\n"
"	border-bottom-color: rgb(229,229,229);\n"
"	color: #FFFFFF;\n"
"	padding: 3px;\n"
"	margin-left:0px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}\n"
"\n"
"QCheckBox {\n"
"	color: #000000;\n"
"	padding: 2px;\n"
"}\n"
"QCheckBox:disabled {\n"
"	color: #808086;\n"
"	padding: 2px;\n"
"}\n"
"\n"
"QCheckBox:hove"
                        "r {\n"
"	border-radius:4px;\n"
"	border-style:solid;\n"
"	padding-left: 1px;\n"
"	padding-right: 1px;\n"
"	padding-bottom: 1px;\n"
"	padding-top: 1px;\n"
"	border-width:1px;\n"
"	border-color: transparent;\n"
"}\n"
"QCheckBox::indicator:checked {\n"
"\n"
"	height: 10px;\n"
"	width: 10px;\n"
"	border-style:solid;\n"
"	border-width: 1px;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"	color: #000000;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}\n"
"QCheckBox::indicator:unchecked {\n"
"\n"
"	height: 10px;\n"
"	width: 10px;\n"
"	border-style:solid;\n"
"	border-width: 1px;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"	color: #000000;\n"
"}\n"
"QRadioButton {\n"
"	color: 000000;\n"
"	padding: 1px;\n"
"}\n"
"QRadioButton::in"
                        "dicator:checked {\n"
"	height: 10px;\n"
"	width: 10px;\n"
"	border-style:solid;\n"
"	border-radius:5px;\n"
"	border-width: 1px;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"	color: #a9b7c6;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}\n"
"QRadioButton::indicator:!checked {\n"
"	height: 10px;\n"
"	width: 10px;\n"
"	border-style:solid;\n"
"	border-radius:5px;\n"
"	border-width: 1px;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"	color: #a9b7c6;\n"
"	background-color: transparent;\n"
"}\n"
"QStatusBar {\n"
"	color:#027f7f;\n"
"}\n"
"QSpinBox {\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 25"
                        "2, 255));\n"
"}\n"
"QDoubleSpinBox {\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}\n"
"QTimeEdit {\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}\n"
"QDateTimeEdit {\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}\n"
"QDateEdit {\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(0, 113, 255, 255), stop:1 rgba(91, 171, 252, 255));\n"
"}\n"
"\n"
"QToolBox {\n"
"	color: #a9b7c6;\n"
"	background-color:#000000;\n"
"}\n"
"QToolBox::tab {\n"
"	color: #a9b7c6;\n"
"	background-color:#000000;\n"
"}\n"
""
                        "QToolBox::tab:selected {\n"
"	color: #FFFFFF;\n"
"	background-color:#000000;\n"
"}\n"
"/*---------QScrollArea--------------*/\n"
"QScrollArea {\n"
"	color: none;\n"
"	background-color:none;\n"
"	border-radius: 4px;\n"
"	border-color:  #d9d9d9;\n"
"	\n"
"}\n"
"/*----------QCoboBox---------------*/\n"
"\n"
"\n"
"\n"
"/* ComboBox menu */\n"
"QComboBox {\n"
"    selection-color: white;\n"
"    selection-background-color: #5e90fa;\n"
"	border: 1px; \n"
"	border-style: solid;\n"
"	\n"
"    border-top-left-radius: 5px;\n"
"    border-bottom-left-radius: 5px;\n"
"border-color: rgba(0, 130, 255, 255);\n"
"	padding: 2px 1px 1px 1px;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    color: #000000; /* same as regular QComboBox color */\n"
"    background-color: transparent;\n"
"    selection-color: white;\n"
"    selection-background-color: #5e90fa;\n"
"    border-width: 5px 0px 5px 0px;\n"
"    border-style: solid;\n"
"    border-color: transparent;\n"
"    margin: 0px -1px 0px 0px; /* temporal: hack for Mac... try i"
                        "t on Windows and Linux */\n"
"	border: 1px;     border-top-left-radius: 5px;\n"
"    border-bottom-left-radius: 5px;\n"
"	border-style: solid;\n"
"	border-color: rgba(0, 130, 255, 255);\n"
"	padding: 2px 1px 1px 1px;\n"
"}\n"
"	/*QComboBox::drop-down {\n"
"  background-color: #d2d2d2;\n"
"    subcontrol-origin: border; \n"
"    subcontrol-position: top right;\n"
"    width: 20px;\n"
"    border-top-right-radius: 3px;\n"
"    border-bottom-right-radius: 3px;\n"
"border-radius: 2px;\n"
"\n"
"}*/\n"
"\n"
"/*--------------------------------------*/\n"
"/*QSlider::groove:horizontal {\n"
"	height: 5px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(49, 147, 250, 255), stop:1 rgba(34, 142, 255, 255));\n"
"}\n"
"QSlider::groove:vertical {\n"
"	width: 5px;\n"
"	background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(49, 147, 250, 255), stop:1 rgba(34, 142, 255, 255));\n"
"}\n"
"QSlider::handle:horizontal {\n"
"	background: rgb(253,253,253);\n"
"	"
                        "border-style: solid;\n"
"	border-width: 1px;\n"
"	border-color: rgb(207,207,207);\n"
"	min-width: 5px;\n"
"	margin: -5px 0;\n"
"	border-radius: 7px;\n"
"}\n"
"QSlider::handle:vertical {\n"
"	background: rgb(253,253,253);\n"
"	border-style: solid;\n"
"	border-width: 1px;\n"
"	border-color: rgb(207,207,207);\n"
"	min-height: 5px;\n"
"	margin: 0 -5px;\n"
"	border-radius: 7px;\n"
"}\n"
"QSlider::add-page:horizontal {\n"
"    background: rgb(181,181,181);\n"
"}\n"
"QSlider::add-page:vertical {\n"
"    background: rgb(181,181,181);\n"
"}\n"
"QSlider::sub-page:horizontal {\n"
"    background-color: qlineargradient(spread:pad, x1:0.5, y1:1, x2:0.5, y2:0, stop:0 rgba(49, 147, 250, 255), stop:1 rgba(34, 142, 255, 255));\n"
"}\n"
"QSlider::sub-page:vertical {\n"
"    background-color: qlineargradient(spread:pad, y1:0.5, x1:1, y2:0.5, x2:0, stop:0 rgba(49, 147, 250, 255), stop:1 rgba(34, 142, 255, 255));\n"
"}\n"
"*/\n"
"/* --------- Scroll bar -----------*/\n"
"QScrollBar:horizontal {\n"
"	background: #263238;				/* Back"
                        "ground where slider is not */\n"
"	height: 10px;\n"
"	margin: 0;\n"
"}\n"
"\n"
"QScrollBar:vertical {\n"
"	background: rgb(167, 167, 167);\n"
"    border-top-right-radius: 4px;			/* Background where slider is not */\n"
"    border-top-left-radius: 4px;\n"
"    border-bottom-left-radius: 4px;\n"
"	border-bottom-right-radius: 4px;\n"
"	width: 12px;\n"
"	height: 55px;\n"
"	/*margin: 0;*/\n"
"}\n"
"\n"
"QScrollBar::handle:horizontal {\n"
"    background: #37474F;					/* Slider color */\n"
"    min-width: 16px;\n"
"	border-radius: 5px;\n"
"height: 5px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical {\n"
"    background: rgba(34, 142, 255, 255);				/* Slider color */\n"
"   /* min-height: 5px;*/\n"
"	border-radius: 4px;\n"
"	min-width: 10px;\n"
"height: 20px;\n"
"}\n"
"\n"
"QScrollBar::handle:vertical:pressed {\n"
"    background-color: #305da1;				/* Slider color */\n"
"    /*min-height: 5px;*/\n"
"	border-radius: 3px;\n"
"	min-width: 10px;\n"
"height: 20px;\n"
"}\n"
"\n"
"QScrollBar::add-page:horizontal, QScrollBar::s"
                        "ub-page:horizontal,\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"	background: none;												/* Removes the dotted background */\n"
"}\n"
"\n"
"QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal,\n"
"QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {	/* Hides the slider arrows */\n"
"      border: none;\n"
"      background: none;\n"
"}"));
        horizontalLayout_3 = new QHBoxLayout(Mode);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(20);
        gridLayout->setVerticalSpacing(10);
        gridLayout->setContentsMargins(-1, 20, 30, 0);
        label_11 = new QLabel(Mode);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QFont font;
        font.setPointSize(12);
        label_11->setFont(font);
        label_11->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_11, 3, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        lineModeFile = new QLineEdit(Mode);
        lineModeFile->setObjectName(QString::fromUtf8("lineModeFile"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lineModeFile->sizePolicy().hasHeightForWidth());
        lineModeFile->setSizePolicy(sizePolicy1);
        lineModeFile->setFont(font);

        horizontalLayout->addWidget(lineModeFile);


        gridLayout->addLayout(horizontalLayout, 10, 1, 1, 1);

        lineModeOutput = new QLineEdit(Mode);
        lineModeOutput->setObjectName(QString::fromUtf8("lineModeOutput"));
        sizePolicy1.setHeightForWidth(lineModeOutput->sizePolicy().hasHeightForWidth());
        lineModeOutput->setSizePolicy(sizePolicy1);
        lineModeOutput->setFont(font);

        gridLayout->addWidget(lineModeOutput, 7, 1, 1, 2);

        textMode = new QTextEdit(Mode);
        textMode->setObjectName(QString::fromUtf8("textMode"));
        sizePolicy.setHeightForWidth(textMode->sizePolicy().hasHeightForWidth());
        textMode->setSizePolicy(sizePolicy);
        textMode->setMinimumSize(QSize(0, 30));
        textMode->setMaximumSize(QSize(16777215, 16777215));
        textMode->setFont(font);
        textMode->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(textMode, 12, 1, 1, 2);

        label_12 = new QLabel(Mode);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font);
        label_12->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_12, 4, 0, 1, 1);

        label = new QLabel(Mode);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 2, 0, 1, 1);

        line_2 = new QFrame(Mode);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_2, 5, 0, 1, 3);

        lineModeBlock = new QLineEdit(Mode);
        lineModeBlock->setObjectName(QString::fromUtf8("lineModeBlock"));
        sizePolicy1.setHeightForWidth(lineModeBlock->sizePolicy().hasHeightForWidth());
        lineModeBlock->setSizePolicy(sizePolicy1);
        lineModeBlock->setFont(font);

        gridLayout->addWidget(lineModeBlock, 8, 1, 1, 2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        radioButtonYes = new QRadioButton(Mode);
        radioButtonYes->setObjectName(QString::fromUtf8("radioButtonYes"));
        radioButtonYes->setFont(font);

        horizontalLayout_2->addWidget(radioButtonYes);

        radioButtonNo = new QRadioButton(Mode);
        radioButtonNo->setObjectName(QString::fromUtf8("radioButtonNo"));
        radioButtonNo->setFont(font);

        horizontalLayout_2->addWidget(radioButtonNo);


        gridLayout->addLayout(horizontalLayout_2, 6, 1, 1, 1);

        label_4 = new QLabel(Mode);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_4, 6, 0, 1, 1);

        lineModeNameOt = new QLineEdit(Mode);
        lineModeNameOt->setObjectName(QString::fromUtf8("lineModeNameOt"));
        lineModeNameOt->setFont(font);

        gridLayout->addWidget(lineModeNameOt, 4, 1, 1, 2);

        buttonModeImage = new QPushButton(Mode);
        buttonModeImage->setObjectName(QString::fromUtf8("buttonModeImage"));
        buttonModeImage->setFont(font);

        gridLayout->addWidget(buttonModeImage, 9, 2, 1, 1);

        label_2 = new QLabel(Mode);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 10, 0, 1, 1);

        label_8 = new QLabel(Mode);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);
        label_8->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_8, 12, 0, 1, 1);

        lineModeNameEn = new QLineEdit(Mode);
        lineModeNameEn->setObjectName(QString::fromUtf8("lineModeNameEn"));
        lineModeNameEn->setFont(font);

        gridLayout->addWidget(lineModeNameEn, 3, 1, 1, 2);

        lineModeName = new QLineEdit(Mode);
        lineModeName->setObjectName(QString::fromUtf8("lineModeName"));
        sizePolicy1.setHeightForWidth(lineModeName->sizePolicy().hasHeightForWidth());
        lineModeName->setSizePolicy(sizePolicy1);
        lineModeName->setFont(font);

        gridLayout->addWidget(lineModeName, 2, 1, 1, 2);

        label_3 = new QLabel(Mode);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 8, 0, 1, 1);

        line = new QFrame(Mode);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line, 1, 0, 1, 3);

        line_3 = new QFrame(Mode);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        gridLayout->addWidget(line_3, 11, 0, 1, 3);

        label_10 = new QLabel(Mode);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setFont(font);
        label_10->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_10, 14, 0, 1, 1);

        label_6 = new QLabel(Mode);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_6, 7, 0, 1, 1);

        label_9 = new QLabel(Mode);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font);
        label_9->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_9, 13, 0, 1, 1);

        textModeOT = new QTextEdit(Mode);
        textModeOT->setObjectName(QString::fromUtf8("textModeOT"));
        sizePolicy.setHeightForWidth(textModeOT->sizePolicy().hasHeightForWidth());
        textModeOT->setSizePolicy(sizePolicy);
        textModeOT->setMinimumSize(QSize(0, 30));
        textModeOT->setMaximumSize(QSize(16777215, 16777215));
        textModeOT->setFont(font);
        textModeOT->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(textModeOT, 14, 1, 1, 2);

        buttonModeFile = new QPushButton(Mode);
        buttonModeFile->setObjectName(QString::fromUtf8("buttonModeFile"));
        buttonModeFile->setFont(font);

        gridLayout->addWidget(buttonModeFile, 10, 2, 1, 1);

        label_7 = new QLabel(Mode);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_7, 9, 0, 1, 1);

        textModeEN = new QTextEdit(Mode);
        textModeEN->setObjectName(QString::fromUtf8("textModeEN"));
        sizePolicy.setHeightForWidth(textModeEN->sizePolicy().hasHeightForWidth());
        textModeEN->setSizePolicy(sizePolicy);
        textModeEN->setMinimumSize(QSize(0, 30));
        textModeEN->setMaximumSize(QSize(16777215, 16777215));
        textModeEN->setFont(font);
        textModeEN->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout->addWidget(textModeEN, 13, 1, 1, 2);

        lineModeImage = new QLineEdit(Mode);
        lineModeImage->setObjectName(QString::fromUtf8("lineModeImage"));
        sizePolicy1.setHeightForWidth(lineModeImage->sizePolicy().hasHeightForWidth());
        lineModeImage->setSizePolicy(sizePolicy1);
        lineModeImage->setFont(font);

        gridLayout->addWidget(lineModeImage, 9, 1, 1, 1);

        label_5 = new QLabel(Mode);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy2);
        label_5->setMaximumSize(QSize(16777215, 50));
        QFont font1;
        font1.setPointSize(16);
        font1.setBold(true);
        font1.setWeight(75);
        label_5->setFont(font1);
        label_5->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(label_5, 0, 0, 1, 3);

        gridLayout->setRowStretch(0, 4);
        gridLayout->setColumnStretch(0, 3);
        gridLayout->setColumnStretch(1, 2);
        gridLayout->setColumnStretch(2, 1);

        horizontalLayout_3->addLayout(gridLayout);

        QWidget::setTabOrder(lineModeName, lineModeFile);
        QWidget::setTabOrder(lineModeFile, radioButtonYes);

        retranslateUi(Mode);

        QMetaObject::connectSlotsByName(Mode);
    } // setupUi

    void retranslateUi(QWidget *Mode)
    {
        Mode->setWindowTitle(QCoreApplication::translate("Mode", "Form", nullptr));
        label_11->setText(QCoreApplication::translate("Mode", "\320\275\320\260 \320\260\320\275\320\263\320\273\320\270\320\271\321\201\320\272\320\276\320\274", nullptr));
        label_12->setText(QCoreApplication::translate("Mode", "\320\275\320\260 \320\264\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\320\276\320\274", nullptr));
        label->setText(QCoreApplication::translate("Mode", "\320\235\320\260\320\267\320\262\320\260\320\275\320\270\320\265 \321\200\320\265\320\266\320\270\320\274\320\260 \320\275\320\260 \321\200\321\203\321\201\321\201\320\272\320\276\320\274", nullptr));
        radioButtonYes->setText(QCoreApplication::translate("Mode", "\320\224\320\260", nullptr));
        radioButtonNo->setText(QCoreApplication::translate("Mode", "\320\235\320\265\321\202", nullptr));
        label_4->setText(QCoreApplication::translate("Mode", "\320\224\320\276\321\201\321\202\321\203\320\277\320\275\320\276\321\201\321\202\321\214 \321\200\320\265\320\266\320\270\320\274\320\260 \320\262 \320\264\320\260\320\275\320\275\320\276\320\271 \320\272\320\276\320\275\321\204\320\270\320\263\321\203\321\200\320\260\321\206\320\270\320\270", nullptr));
        buttonModeImage->setText(QCoreApplication::translate("Mode", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("Mode", "\320\244\320\260\320\271\320\273 \320\264\320\273\321\217 \320\267\320\260\320\277\321\203\321\201\320\272\320\260 \321\201\321\202\320\276\321\200\320\276\320\275\320\275\320\265\320\263\320\276 \320\277\321\200\320\270\320\273\320\276\320\266\320\265\320\275\320\270\321\217", nullptr));
        label_8->setText(QCoreApplication::translate("Mode", "\320\237\320\276\320\264\321\201\320\272\320\260\320\267\320\272\320\260 \321\200\320\265\320\266\320\270\320\274\320\260 \320\275\320\260 \321\200\321\203\321\201\321\201\320\272\320\276\320\274", nullptr));
        label_3->setText(QCoreApplication::translate("Mode", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\265\321\200\320\265\321\207\320\265\320\275\321\214 \320\277\321\200\320\276\320\262\320\265\321\200\321\217\320\265\320\274\321\213\321\205 \320\261\320\273\320\276\320\272\320\270\321\200\320\276\320\262\320\276\320\272 \321\207\320\265\321\200\320\265\320\267 \320\277\321\200\320\276\320\261\320\265\320\273", nullptr));
        label_10->setText(QCoreApplication::translate("Mode", "\320\275\320\260 \320\264\320\276\320\277\320\276\320\273\320\275\320\270\321\202\320\265\320\273\321\214\320\275\320\276\320\274", nullptr));
        label_6->setText(QCoreApplication::translate("Mode", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\277\320\265\321\200\320\265\321\207\320\265\320\275\321\214 \320\262\321\213\320\277\320\276\320\273\320\275\321\217\320\265\320\274\321\213\321\205 \320\264\320\265\320\271\321\201\321\202\320\262\320\270\320\271 \321\207\320\265\321\200\320\265\320\267 \320\277\321\200\320\276\320\261\320\265\320\273", nullptr));
        label_9->setText(QCoreApplication::translate("Mode", "\320\275\320\260 \320\260\320\275\320\263\320\273\320\270\320\271\321\201\320\272\320\276\320\274", nullptr));
        buttonModeFile->setText(QCoreApplication::translate("Mode", "\320\222\321\213\320\261\321\200\320\260\321\202\321\214", nullptr));
        label_7->setText(QCoreApplication::translate("Mode", "\320\230\320\267\320\276\320\261\321\200\320\260\320\266\320\265\320\275\320\270\320\265 \321\201\321\205\320\265\320\274\321\213 \320\277\320\276\320\264\320\272\320\273\321\216\321\207\320\265\320\275\320\270\321\217", nullptr));
        label_5->setText(QCoreApplication::translate("Mode", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270 \321\200\320\265\320\266\320\270\320\274\320\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Mode: public Ui_Mode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODE_H
