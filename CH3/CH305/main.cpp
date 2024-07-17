#include"content.h"
#include<QSplitter>
#include<QListWidget>
#include<QObject>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplitter* splitter= new QSplitter(Qt::Horizontal);
    QListWidget* list=new QListWidget(splitter);
    list->addItem("baseinfo");
    list->addItem("contact");
    list->addItem("detail");
    content c(splitter);
    QObject::connect(list,SIGNAL(currentRowChanged(int)),&c,SLOT(switch_page(int)));
    splitter->show();
    a.exec();
    splitter->deleteLater();
    return 0;
}
