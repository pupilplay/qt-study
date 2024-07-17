#include "dialog.h"
#include "./ui_dialog.h"

const static double PI=3.1416;

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

void Dialog::on_calculate_btn_clicked()
{
    bool ok;
    QString temp_str;
    QString value_str=ui->radius_input->text();
    int r=value_str.toInt(&ok);
    double size=r*r*PI;
    ui->size_val_label->setText(temp_str.setNum(size));
}

