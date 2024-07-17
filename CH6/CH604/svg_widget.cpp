#include "svg_widget.h"

void svg_widget::wheelEvent(QWheelEvent *ev)
{
    const double diff=0.1;
    QSize size=render->defaultSize();
    int width=size.width();
    int height=size.height();
    if(ev->angleDelta().y()>0)
    {
        width=this->width()+this->width()*diff;
        height=this->height()+this->height()*diff;
    }
    else
    {
        width=this->width()-this->width()*diff;
        height=this->height()-this->height()*diff;
    }
    resize(width,height);
}

svg_widget::svg_widget(QWidget *parent)
    :QSvgWidget(parent)
{
    render=this->renderer();
}
