#include "mainmenu.h"
#include "ui_mainmenu.h"

// Главное меню

//
// https://progi.pro/qdialog-kak-ispolzovat-knopku-voprosa-10076569 (про знак вопроса на главном окне)
//

MainMenu::MainMenu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainMenu)
{
    ui->setupUi(this);
    this->setWindowTitle("Главное меню");
    // отключение знака вопроса рядом с *крестиком*
    this->setWindowFlags (this->windowFlags() & ~Qt::WindowContextHelpButtonHint);

    // cоединение с окном создания конфиг файл
//    confWindow = new MainWindow();
//    connect(confWindow, &MainWindow::firstWindow, this, &MainMenu::show);

    // соединение с окном создания информ файл
    infoWindow = new InfoWindow();
    connect(infoWindow, &InfoWindow::firstWindow, this, &MainMenu::show);
}


MainMenu::~MainMenu()
{
    delete ui;
}


void MainMenu::on_confButton_clicked()
{
    confWindow->show();
    this->close();
}


void MainMenu::on_infoButton_clicked()
{
    infoWindow->show();
    this->close();
}


void MainMenu::on_aboutButton_clicked()
{
    QMessageBox::about(this, "Информация о программе", information);
}


void MainMenu::on_exitButton_clicked()
{
    QApplication::quit();
}

