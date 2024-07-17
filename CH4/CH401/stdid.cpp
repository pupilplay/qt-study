#include "stdid.h"
#include "ui_stdid.h"
#include<QInputDialog>

stdid::stdid(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::stdid)
{
    ui->setupUi(this);
}

stdid::~stdid()
{
    delete ui;
}

void stdid::on_name_btn_clicked()
{
    bool ok;
    QString name=QInputDialog::getText(this,"set name","enter the name:",QLineEdit::Normal,ui->name_value->text(),&ok);
    if(ok && !name.isEmpty())
    {
        ui->name_value->setText(name);
    }
}


void stdid::on_gender_btn_clicked()
{
    bool ok;
    QString gender=QInputDialog::getItem(this,"set gender","gender:",QStringList{"Male","Female"},0,false,&ok);
    if(ok && !gender.isEmpty())
    {
        ui->gender_value->setText(gender);
    }
}


void stdid::on_age_btn_clicked()
{
    bool ok;
    int num=QInputDialog::getInt(this,"set age","age:",ui->age_value->text().toInt(),0,100,1,&ok);
    if(ok)
    {
        ui->age_value->setText(QString("%1").arg(num));
    }
}


void stdid::on_score_btn_clicked()
{
    bool ok;
    double num=QInputDialog::getDouble(this,"set score","score:",ui->score_value->text().toInt(),0,100,1,&ok);
    if(ok)
    {
        ui->score_value->setText(QString::number(num));
    }
}

