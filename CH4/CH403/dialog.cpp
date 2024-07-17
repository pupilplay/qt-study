#include "dialog.h"
#include "./ui_dialog.h"
#include<QProgressDialog>

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

void Dialog::on_start_btn_clicked()
{
    bool ok;
    int num=ui->count_edit->text().toInt();
    switch(ui->type_box->currentIndex())
    {
    case 0:
        ui->progressBar->setRange(0,num);
        for(int i=1;i<=num;i++)
        {
            ui->progressBar->setValue(i);
        }
        break;
    case 1:
    {
        QProgressDialog *dlg=new QProgressDialog(this);
        dlg->setFont(QFont("ZYSong18030",12));
        dlg->setWindowModality(Qt::WindowModal);
        dlg->setMinimumDuration(5);
        dlg->setWindowTitle("Please wait...");
        dlg->setLabelText("counting...");
        dlg->setCancelButtonText("my_cancel");
        dlg->setRange(0,num);
        for(int i=1;i<=num;i++)
        {
            dlg->setValue(i);
            if(dlg->wasCanceled())
            {
                return;
            }
        }
        break;
    }
    default:
        break;
    }
}

