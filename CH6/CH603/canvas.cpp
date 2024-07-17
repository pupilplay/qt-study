#include "canvas.h"

canvas::canvas(QWidget *parent)
    : QWidget{parent}
{
    setAutoFillBackground(true);
    setPalette(QPalette(Qt::white));
    clear();
}

void canvas::mousePressEvent(QMouseEvent *ev)
{
    start_pos=ev->pos();
}

void canvas::mouseMoveEvent(QMouseEvent *ev)
{
    QPainter painter(&pix);
    painter.setPen(m_pen);
    painter.drawLine(start_pos,ev->pos());
    start_pos=ev->pos();
    update();
}

void canvas::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    painter.drawPixmap(0,0,pix);
}

void canvas::resizeEvent(QResizeEvent *ev)
{
    if(width()>pix.width()||height()>pix.height())
    {
        QPixmap newpix(this->size());
        newpix.fill(Qt::white);
        QPainter painter(&newpix);
        painter.drawPixmap(0,0,pix);
        pix=newpix;
    }
    QWidget::resizeEvent(ev);
}

void canvas::set_style(int style)
{
    m_pen.setStyle(static_cast<Qt::PenStyle>(style));
}

void canvas::set_width(int width)
{
    m_pen.setWidth(width);
}

void canvas::set_color(QColor color)
{
    m_pen.setColor(color);
}

void canvas::clear()
{
    pix=QPixmap(this->size());
    pix.fill(Qt::white);
    update();
}
