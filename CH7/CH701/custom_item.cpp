#include "custom_item.h"
#include<QRandomGenerator>

custom_item::custom_item(QObject *parent)
    : QObject{parent}
{
    status=0;
    for(int i=0;i<4;i++)
    {
        pix[i].load(":/"+QString::number(i)+".png");
    }
    startTimer(100);
}

QRectF custom_item::boundingRect() const
{
    qreal adjust=2;
    return QRectF(-pix[status].width()/2-adjust,-pix[status].height()/2-adjust,
                  pix[status].width()+adjust*2,pix[status].height()+adjust*2);
}

void custom_item::timerEvent(QTimerEvent *ev)
{
    const double PI=3.1415926;
    qreal edgeleft=scene()->sceneRect().left()-boundingRect().width()/2;
    qreal edgeright=scene()->sceneRect().right()+boundingRect().width()/2;
    qreal edgetop=scene()->sceneRect().top()-boundingRect().height()/2;
    qreal edgebottom=scene()->sceneRect().bottom()+boundingRect().height()/2;
    if(x()<edgeleft)
    {
        setX(edgeright);
    }
    if(x()>edgeright)
    {
        setX(edgeleft);
    }
    if(y()<edgetop)
    {
        setY(edgebottom);
    }
    if(y()>edgebottom)
    {
        setY(edgetop);
    }
    angle+=(QRandomGenerator::global()->bounded(0,10)/20.0);
    if(angle>PI*2)
    {
        angle-=PI*2;
    }
    qreal dx=sin(angle*PI)*10;
    qreal dy=QRandomGenerator::global()->bounded(-10,20);
    setPos(mapToParent(dx,dy));
}

void custom_item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    status=(status+1)%4;
    painter->drawPixmap(boundingRect().topLeft(),pix[status]);
}
