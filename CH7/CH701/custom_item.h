#ifndef CUSTOM_ITEM_H
#define CUSTOM_ITEM_H

#include <QObject>
#include<QGraphicsItem>
#include<QPainter>
#include<QGraphicsScene>
#include<QGraphicsView>

class custom_item : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit custom_item(QObject *parent = nullptr);
    QRectF boundingRect() const override;
protected:
    void timerEvent(QTimerEvent *ev) override;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget) override;
signals:
private:
    int status;
    QPixmap pix[4];
    qreal angle;
};

#endif // CUSTOM_ITEM_H
