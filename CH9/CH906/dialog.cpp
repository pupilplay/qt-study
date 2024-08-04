#include "dialog.h"
#include "./ui_dialog.h"
#include<QFileDialog>

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

void Dialog::on_select_button_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,"Open","./","files (*)");
    if(!filename.isEmpty())
    {
        ui->name_edit->setText(filename);
    }
}


void Dialog::on_get_fileinfo_button_clicked()
{
    QFile file(ui->name_edit->text());
    QFileInfo info(file);
    ui->size_edit->setText(QString::number(info.size()));
    ui->created_date_edit->setText(info.birthTime().toString());
    ui->modified_date_edit->setText(info.lastModified().toString());
    ui->accessed_date_edit->setText(info.lastRead().toString());
    ui->dir_box->setChecked(info.isDir());
    ui->file_box->setChecked(info.isFile());
    ui->link_box->setChecked(info.isSymLink());
    ui->hidden_box->setChecked(info.isHidden());
    ui->read_box->setChecked(info.isReadable());
    ui->write_box->setChecked(info.isWritable());
    ui->execute_box->setChecked(info.isExecutable());
}

