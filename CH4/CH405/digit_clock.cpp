#include "digit_clock.h"
#include<QTimer>
#include<QTime>
digit_clock::digit_clock(QWidget *parent):QLCDNumber(parent)
{
    QPalette p=this->palette();
    p.setColor(QPalette::Window,Qt::blue);
    setPalette(p);
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);
    setWindowOpacity(0.5);
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(update_time()));
    timer->setSingleShot(false);
    timer->start(1000);
    update_time();
}

void digit_clock::mousePressEvent(QMouseEvent *ev)
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

void digit_clock::mouseMoveEvent(QMouseEvent *ev)
{
    if(ev->buttons() & Qt::LeftButton)
    {
        move(ev->globalPosition().toPoint()-pos);
    }
    ev->accept();
}

void digit_clock::update_time()
{
    QTime time=QTime::currentTime();
    QString text=time.toString("hh:mm");
    this->display(text);
}
