#include "widget.h"
#include "./ui_widget.h"
#include<QPainter>
#include<QLabel>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
    , pix(":/image.png",nullptr,Qt::AvoidDither|Qt::ThresholdDither|Qt::ThresholdAlphaDither)
{
    ui->setupUi(this);
    resize(pix.size());
    this->setMask(pix.mask());
    QLabel *label=new QLabel("It's a\nshaped\nwidget",this);
    QFont font=label->font();
    font.setPointSize(16);
    label->setFont(font);
    label->move(width()/8,height()/4);
    label->show();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::mousePressEvent(QMouseEvent *ev)
{
    switch(ev->button())
    {
    case Qt::LeftButton:
        pos=ev->globalPosition().toPoint()-this->frameGeometry().topLeft();
        break;
    case Qt::RightButton:
        close();
        break;
    default:
        break;
    }
}

void Widget::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons() & Qt::LeftButton)
    {
        move(ev->globalPosition().toPoint()-pos);
    }
    ev->accept();
}

void Widget::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,pix);
}
