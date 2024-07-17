#ifndef FLASH_ITEM_H
#define FLASH_ITEM_H

#include <QGraphicsItem>
#include<QTimerEvent>
#include<QPainter>
class flash_item : public QObject,public QGraphicsItem
{
    Q_OBJECT
public:
    flash_item(QGraphicsItem *parent = nullptr);
public:
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
protected:
    void timerEvent(QTimerEvent *ev) override;
private:
    QTimer *timer;
    bool flash;
};

#endif // FLASH_ITEM_H
