#ifndef CUSTOM_ITEM_H
#define CUSTOM_ITEM_H

#include<QGraphicsItem>
#include<QPainter>

class custom_item : public QGraphicsItem
{
public:
    explicit custom_item(QGraphicsItem *parent = nullptr);
    QRectF boundingRect() const override;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) override;
signals:
private:
    int status;
    QPixmap pix[4];
};

#endif // CUSTOM_ITEM_H
