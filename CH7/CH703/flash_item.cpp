#include "flash_item.h"
#include<QRandomGenerator>

flash_item::flash_item(QGraphicsItem *parent)
    :QGraphicsItem(parent)
{
    flash=true;
    startTimer(1000);
}

QRectF flash_item::boundingRect() const
{
    return QRectF(-10,-10,43,43);
}

void flash_item::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::NoPen);
    painter->setBrush(Qt::darkGray);
    painter->drawEllipse(-7,-7,40,40);
    painter->setPen(QPen(Qt::black,0));
    painter->setBrush(QColor(flash?(Qt::red):(Qt::yellow)));
    painter->drawEllipse(-10,-10,40,40);
}

void flash_item::timerEvent(QTimerEvent *ev)
{
    flash=!flash;
    update();
}
