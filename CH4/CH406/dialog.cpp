#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->detail_widget->hide();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_detail_btn_clicked()
{
    if(ui->detail_widget->isHidden())
    {
        ui->detail_widget->show();
    }
    else
    {
        ui->detail_widget->hide();
    }
}

