#include "custom_item.h"
#include<QRandomGenerator>

custom_item::custom_item(QGraphicsItem *parent)
    :QGraphicsItem(parent)
{
    status=0;
    for(int i=0;i<4;i++)
    {
        pix[i].load(":/"+QString::number(i)+".png");
    }
}

QRectF custom_item::boundingRect() const
{
    return QRectF(-pix[status].width()/2,-pix[status].height()/2,
                  pix[status].width(),pix[status].height());
}


void custom_item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    status=(status+1)%4;
    painter->drawPixmap(boundingRect().topLeft(),pix[status]);
}
