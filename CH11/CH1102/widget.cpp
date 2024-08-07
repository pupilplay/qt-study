#include "widget.h"
#include "./ui_widget.h"
#include <QPalette>
#include<QPainter>


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setAutoFillBackground(true);
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window,Qt::white);
    setPalette(palette);
    width=512;
    height=256;
    setFixedSize(width,height);
    pix=new QPixmap(this->size());
    pix->fill(Qt::white);
    image.load(":/image.png");
    start_x=100;
    start_y=100;
    step=20;
    draw_pix();
    resize(512,256);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::draw_pix()
{
    pix->fill(Qt::white);
    QPen pen(Qt::DotLine);
    QPainter painter(pix);
    painter.setPen(pen);
    for(int i=step;i<width;i+=step)
    {
        painter.drawLine(QPoint(i,0),QPoint(i,height));
    }
    for(int j=step;j<height;j+=step)
    {
        painter.drawLine(QPoint(0,j),QPoint(width,j));
    }
    painter.drawImage(start_x,start_y,image);
    painter.end();
}

void Widget::keyPressEvent(QKeyEvent *ev)
{
    if(ev->modifiers()==Qt::ControlModifier)
    {
        switch(ev->key())
        {
        case Qt::Key_Left:
            start_x=start_x-1<0?start_x:start_x-1;
            break;
        case Qt::Key_Right:
            start_x=start_x+1+image.width()>width?start_x:start_x+1;
            break;
        case Qt::Key_Up:
            start_y=start_y-1<0?start_y:start_y-1;
            break;
        case Qt::Key_Down:
            start_y=start_y+1+image.height()>height?start_y:start_y+1;
            break;
        }
    }
    else
    {
        start_x=start_x-start_x%step;
        start_y=start_y-start_y%step;
        switch(ev->key())
        {
        case Qt::Key_Left:
            start_x=start_x-step<0?start_x:start_x-step;
            break;
        case Qt::Key_Right:
            start_x=start_x+step+image.width()>width?start_x:start_x+step;
            break;
        case Qt::Key_Up:
            start_y=start_y-step<0?start_y:start_y-step;
            break;
        case Qt::Key_Down:
            start_y=start_y+step+image.height()>height?start_y:start_y+step;
            break;
        case Qt::Key_Home:
            start_x=0;
            start_y=0;
            break;
        case Qt::Key_End:
            start_x=width-image.width();
            start_y=height-image.height();
            break;
        }
    }
    draw_pix();
    update();
}

void Widget::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,*pix);
    painter.end();
}
