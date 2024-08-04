#include "widget.h"
#include "./ui_widget.h"
#include<QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QStringList args=qApp->arguments();
    QString path;
    if(args.count()>1)
    {
        path=args[1];
    }
    else
    {
        path=QDir::currentPath();
    }
    ui->path_label->setText(path);
    fs_watcher.addPath(path);
    connect(&fs_watcher,&QFileSystemWatcher::directoryChanged,this,[]()->void
    {
        QMessageBox::information(nullptr,"Information","The directory has been changed");
    });
    connect(&fs_watcher,&QFileSystemWatcher::fileChanged,this,[]()->void
    {
        QMessageBox::information(nullptr,"Information","A file has been changed");
    });
}

Widget::~Widget()
{
    delete ui;
}
