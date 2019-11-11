#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_AccountButton_clicked()
{
    QMessageBox::information(this, "Account", "TODO: implement Account ui");
}

void MainWindow::on_LoginButton_clicked()
{
    QString username = ui->lineEdit_username->text();
    QString password = ui->lineEdit_password->text();

    if(username ==  "admin" && password == "admin") {
        QMessageBox::information(this, "Login", "Username and password is correct");
        hide();

        secDialog = new SecDialog(this);
        secDialog->show();
    }
    else {
        QMessageBox::warning(this,"Login", "Username and password is not correct");
    }
}
