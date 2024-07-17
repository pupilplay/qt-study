#include "dialog.h"
#include "./ui_dialog.h"
#include<QHBoxLayout>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    list = new QListWidget();
    list->addItem("label1");
    list->addItem("label2");
    list->addItem("label3");
    label1 = new QLabel("Test1");
    label2 = new QLabel("Test2");
    label3 = new QLabel("Test3");
    stack = new QStackedWidget();
    stack->addWidget(label1);
    stack->addWidget(label2);
    stack->addWidget(label3);
    QHBoxLayout* layout=new QHBoxLayout(this);
    layout->setSpacing(5);
    layout->addWidget(list);
    layout->addWidget(stack,0,Qt::AlignHCenter);
    layout->setStretchFactor(list,1);
    layout->setStretchFactor(stack,1);
    connect(list,SIGNAL(currentRowChanged(int)),stack,SLOT(setCurrentIndex(int)));
}

Dialog::~Dialog()
{
    delete ui;
}
