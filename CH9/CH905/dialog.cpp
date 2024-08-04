#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->file_edit,&QLineEdit::returnPressed,this,&Dialog::update_dir);
    connect(ui->file_list,&QListWidget::itemDoubleClicked,this,&Dialog::unfold_dir);
    update_dir();
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::update_fileinfo_list(QFileInfoList list)
{
    ui->file_list->clear();
    for(unsigned int i=0;i<list.count();i++)
    {
        QFileInfo info=list[i];
        if(info.isDir())
        {
            QIcon icon(":/folder.png");
            QString filename=info.fileName();
            QListWidgetItem *item=new QListWidgetItem(icon,filename);
            ui->file_list->addItem(item);
        }
        else if(info.isFile())
        {
            QIcon icon(":/file.png");
            QString filename=info.fileName();
            QListWidgetItem *item=new QListWidgetItem(icon,filename);
            ui->file_list->addItem(item);
        }
    }
}

void Dialog::update_dir()
{
    QFileInfoList list=QDir(ui->file_edit->text()).entryInfoList();
    update_fileinfo_list(list);
    return;
}

void Dialog::unfold_dir(QListWidgetItem *item)
{
    QDir dir(ui->file_edit->text());
    dir.cd(item->text());
    ui->file_edit->setText(dir.absolutePath());
    update_dir();
    return;
}
