#include "dialog.h"
#include "./ui_dialog.h"
#include "server.h"
#include "client.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_server_button_clicked()
{
    close();
    server s;
    s.exec();
    qDebug()<<"here";
}


void Dialog::on_client_button_clicked()
{
    close();
    client c;
    c.exec();
}

