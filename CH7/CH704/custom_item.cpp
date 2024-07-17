#include "custom_item.h"
#include<QRandomGenerator>

custom_item::custom_item(QGraphicsItem *parent)
    : QGraphicsItem(parent)
{
    status=0;
    for(int i=0;i<4;i++)
    {
        pix[i].load(":/"+QString::number(i)+".png");
    }
}

QRectF custom_item::boundingRect() const
{
    qreal adjust=2;
    return QRectF(-pix[status].width()/2-adjust,-pix[status].height()/2-adjust,
                  pix[status].width()+adjust*2,pix[status].height()+adjust*2);
}

void custom_item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    status=(status+1)%4;
    painter->drawPixmap(boundingRect().topLeft(),pix[status]);
}
