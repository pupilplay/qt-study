#ifndef MY_GRAPHICS_VIEW_H
#define MY_GRAPHICS_VIEW_H

#include <QGraphicsView>
#include<QMouseEvent>
class my_graphics_view : public QGraphicsView
{
    Q_OBJECT
public:
    my_graphics_view(QWidget *parent=nullptr);
    my_graphics_view(QGraphicsScene *scene,QWidget *parent=nullptr);
signals:
    void pos_signal(QPoint pos);
protected:
    void mouseMoveEvent(QMouseEvent *ev) override;
};

#endif // MY_GRAPHICS_VIEW_H
