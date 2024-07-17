#include "widget.h"
#include "./ui_widget.h"
#include<QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setMinimumSize(200,120);
    setMaximumSize(200,120);
    QPushButton *quit=new QPushButton("Quit",this);
    quit->setGeometry(62,40,75,30);
    quit->setFont(QFont("Times",18,QFont::Bold));
    //qApp -> (static_cast<QApplication *>(QCoreApplication::instance()))
    connect(quit,SIGNAL(clicked()),qApp,SLOT(quit()));
}

Widget::~Widget()
{
    delete ui;
}
