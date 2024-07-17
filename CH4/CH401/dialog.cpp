#include "dialog.h"
#include "./ui_dialog.h"
#include<QFileDialog>
#include<QColorDialog>
#include<QFontDialog>
#include<QInputDialog>
#include<QMessageBox>
#include"stdid.h"
#include"stdmd.h"

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



void Dialog::on_file_btn_clicked()
{
    QString str=QFileDialog::getOpenFileName(this,"file dialog","./","All(*);;src(*.c *.cpp *.h);;Cpp(*.cpp);;C(*.c);;header(*.h)");
    if(!str.isEmpty())
    {
        ui->file_edit->setText(str);
    }
}


void Dialog::on_color_btn_clicked()
{
    QColorDialog dlg(Qt::white,this);
    if(dlg.exec() ==QDialog::Accepted)
    {
        ui->color_frame->setPalette(QPalette(dlg.currentColor()));
    }
    // QColor color=QColorDialog::getColor(Qt::white,this);
    // if(color.isValid())
    // {
    //     ui->color_frame->setPalette(QPalette(color));
    // }
}


void Dialog::on_font_btn_clicked()
{
    bool ok;
    QFont font=QFontDialog::getFont(&ok,this);
    if(ok)
    {
        ui->font_edit->setFont(font);
    }
}


void Dialog::on_stdid_btn_clicked()
{
    stdid inputs;
    inputs.exec();
}


void Dialog::on_custom_btn_clicked()
{
    ui->custom_label->setText("custom messagebox");
    QMessageBox msgbox;
    msgbox.setWindowTitle("custom msgbox");
    QPushButton *yes_btn=msgbox.addButton("my_yes",QMessageBox::ActionRole);
    QPushButton *no_btn=msgbox.addButton("my_no",QMessageBox::ActionRole);
    QPushButton *cancel_btn=msgbox.addButton(QMessageBox::Cancel);
    msgbox.setText("it is a custom msgbox");
    msgbox.setIconPixmap(QPixmap(":/icon.png"));
    msgbox.exec();
    if(msgbox.clickedButton()==yes_btn)
    {
        ui->custom_label->setText("custom yes clicked");
    }
    else if(msgbox.clickedButton()==no_btn)
    {
        ui->custom_label->setText("custom no clicked");
    }
    else if(msgbox.clickedButton()==cancel_btn)
    {
        ui->custom_label->setText("custom msgbox: default cancel clicked");
    }
}


void Dialog::on_stdmd_btn_clicked()
{
    stdmd msgboxes;
    msgboxes.exec();
}

