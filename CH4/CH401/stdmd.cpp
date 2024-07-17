#include "stdmd.h"
#include "ui_stdmd.h"
#include<QMessageBox>

stdmd::stdmd(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::stdmd)
{
    ui->setupUi(this);
}

stdmd::~stdmd()
{
    delete ui;
}

void stdmd::on_question_btn_clicked()
{
    ui->label->setText("question");
    switch(QMessageBox::question(this,"Question","yes or no",QMessageBox::Ok|QMessageBox::Cancel,QMessageBox::Ok))
    {
    case QMessageBox::Ok:
        ui->label->setText("question/ok");
    case QMessageBox::Cancel:
        ui->label->setText("question/cancel");
    default:
        break;
    }
}


void stdmd::on_information_btn_clicked()
{
    ui->label->setText("information");
    QMessageBox::information(this,"Information","it is a information");
}


void stdmd::on_warning_btn_clicked()
{
    ui->label->setText("warning");
    switch(QMessageBox::warning(this,"Warning","it is a warning!",QMessageBox::Save|QMessageBox::Discard|QMessageBox::Cancel))
    {
    case QMessageBox::Save:
        ui->label->setText("warning/save");
        break;
    case QMessageBox::Discard:
        ui->label->setText("warning/discard");
        break;
    case QMessageBox::Cancel:
        ui->label->setText("warning/cancel");
        break;
    default:
        break;
    }
}


void stdmd::on_critical_btn_clicked()
{
    ui->label->setText("critical");
    QMessageBox::critical(this,"Critical","it is a critical");
}


void stdmd::on_about_btn_clicked()
{
    ui->label->setText("about");
    QMessageBox::about(this,"About","it is an about");
}


void stdmd::on_aboutQT_btn_clicked()
{
    ui->label->setText("about QT");
    QMessageBox::aboutQt(this,"About QT");
}

