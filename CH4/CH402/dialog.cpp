#include "dialog.h"
#include "./ui_dialog.h"
#include "drawer.h"
#include<QVBoxLayout>
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    drawer *my_drawer=new drawer();
    QVBoxLayout *layout=new QVBoxLayout(this);
    layout->addWidget(my_drawer);
    layout->addStretch();
}

Dialog::~Dialog()
{
    delete ui;
}
