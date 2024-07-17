#include "dialog.h"
#include "./ui_dialog.h"

const static double PI=3.1416;

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    this->radius_label=new QLabel();
    this->radius_label->setText("radius");
    this->size_label=new QLabel();
    this->size_label->setText("size");
    this->radius_input=new QLineEdit();
    this->size_val_label=new QLabel();
    main_layout=new QGridLayout(this);
    main_layout->addWidget(this->radius_label,0,0);
    main_layout->addWidget(this->radius_input,0,1);
    main_layout->addWidget(this->size_label,1,0);
    main_layout->addWidget(this->size_val_label,1,1);
    connect(this->radius_input,SIGNAL(textChanged(QString)),this,SLOT(calculate_area()));
}
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::calculate_area()
{
    bool ok;
    QString temp_str;
    QString value_str=this->radius_input->text();
    int r=value_str.toInt(&ok);
    double size=r*r*PI;
    this->size_val_label->setText(temp_str.setNum(size));
}
