#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->start_button->setEnabled(true);
    ui->stop_button->setEnabled(false);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_start_button_clicked()
{
    for(int i=0;i<MAXSIZE;i++)
    {
        workers[i]=new worker_thread();
    }
    for(int i=0;i<MAXSIZE;i++)
    {
        workers[i]->start();
    }
    ui->start_button->setEnabled(false);
    ui->stop_button->setEnabled(true);
}
void Dialog::on_stop_button_clicked()
{
    for(int i=0;i<MAXSIZE;i++)
    {
        workers[i]->terminate();
        workers[i]->wait();
    }
    ui->start_button->setEnabled(true);
    ui->stop_button->setEnabled(false);
}

