#include "svg_window.h"

svg_window::svg_window(QWidget *parent)
    :QScrollArea(parent)
{
    main_widget=new svg_widget();
    this->setWidget(main_widget);
}

void svg_window::set_file(QString file_name)
{
    main_widget->load(file_name);
    QSvgRenderer *render=main_widget->renderer();
    main_widget->resize(render->defaultSize());
}

void svg_window::mousePressEvent(QMouseEvent *ev)
{
    start_pos=ev->pos();
    horizontal_bar_start_value=horizontalScrollBar()->value();
    vertical_bar_start_value=verticalScrollBar()->value();
    ev->accept();
}

void svg_window::mouseMoveEvent(QMouseEvent *ev)
{
    horizontalScrollBar()->setValue(horizontal_bar_start_value+start_pos.x()-ev->pos().x());
    verticalScrollBar()->setValue(vertical_bar_start_value+start_pos.y()-ev->pos().y());
    horizontalScrollBar()->update();
    verticalScrollBar()->update();
    ev->accept();
}
