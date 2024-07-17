#include "dialog.h"
#include "./ui_dialog.h"
#include<QRegularExpression>
#include<QRegularExpressionValidator>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->ok_btn,&QPushButton::clicked,this,&QDialog::accept);
    connect(ui->cancel_btn,&QPushButton::clicked,this,&QDialog::reject);
    QRegularExpression reg_exp("[a-zA-z][1-9]\\d{0,2}");
    ui->line_edit->setValidator(new QRegularExpressionValidator(reg_exp,this));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_line_edit_textChanged(const QString &arg1)
{
    ui->ok_btn->setEnabled(ui->line_edit->hasAcceptableInput());
}

