#include "my_graphics_view.h"

my_graphics_view::my_graphics_view(QWidget *parent):QGraphicsView(parent)
{
    this->setMouseTracking(true);
}

my_graphics_view::my_graphics_view(QGraphicsScene *scene, QWidget *parent):QGraphicsView(scene,parent)
{
    this->setMouseTracking(true);
}

void my_graphics_view::mouseMoveEvent(QMouseEvent *ev)
{
    emit pos_signal(mapToScene(ev->pos()).toPoint());
}
