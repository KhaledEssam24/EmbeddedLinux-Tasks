#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "Server.h"

extern Server server;

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

void MainWindow::on_FB_clicked()
{
    if (server.Server_is_accepted() >= 0)
        server.Server_send("facebook");   
}

void MainWindow::on_YT_clicked()
{
    if (server.Server_is_accepted() >= 0)
        server.Server_send("youtube");
}

void MainWindow::on_LIN_clicked()
{
    if (server.Server_is_accepted() >= 0)
        server.Server_send("linkedin");
}

void MainWindow::on_GPT_clicked()
{
    if (server.Server_is_accepted() >= 0)
        server.Server_send("chatgpt");
}

void MainWindow::on_Enter_clicked()
{
    QString command = ui->Command_txt->text();
    if (server.Server_is_accepted() >= 0)
        server.Server_send(command.toStdString().c_str());
    ui->Command_txt->clear();
}
