#include "widget.h"
#include "./ui_widget.h"
#include "custom_item.h"
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    angle=0;
    scale_value=5;
    shear_value=5;
    translate_value=50;
    scene=new QGraphicsScene(QRectF(-200,-200,400,400),this);
    ui->view->setScene(scene);
    ui->rotate_slider->setValue(angle);
    ui->rotate_slider->setRange(0,360);
    ui->scale_slider->setRange(0,scale_value*2);
    ui->scale_slider->setValue(scale_value);
    ui->shear_slider->setRange(0,shear_value*2);
    ui->shear_slider->setValue(shear_value);
    ui->translate_slider->setRange(0,translate_value*2);
    ui->translate_slider->setValue(translate_value);
    custom_item *item=new custom_item();
    scene->addItem(item);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_rotate_slider_valueChanged(int value)
{
    ui->view->rotate(value-angle);
    angle=value;
}


void Widget::on_scale_slider_valueChanged(int value)
{
    qreal s;
    if(value>scale_value)
    {
        s=pow(1.1,value-scale_value);
    }
    else
    {
        s=pow(1/1.1,scale_value-value);
    }
    ui->view->scale(s,s);
    scale_value=value;
}


void Widget::on_shear_slider_valueChanged(int value)
{
    ui->view->shear((value-shear_value)/2.0,0);
    shear_value=value;
}


void Widget::on_translate_slider_valueChanged(int value)
{
    qDebug()<<value;
    ui->view->translate(value-translate_value,value-translate_value);
    translate_value=value;
}

