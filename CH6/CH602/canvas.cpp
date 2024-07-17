#include "canvas.h"
#include<QPainterPath>

canvas::canvas(QWidget *parent)
    : QWidget{parent}
{
    setPalette(QPalette(Qt::white));
    setAutoFillBackground(true);
    setMinimumSize(400,400);
}

void canvas::set_shape(Shape shape)
{
    m_shape=shape;
    update();
}

void canvas::set_pen(QPen pen)
{
    m_pen=pen;
    update();
}

void canvas::set_brush(QBrush brush)
{
    m_brush=brush;
    update();
}

void canvas::set_fill_rule(Qt::FillRule fill_rule)
{
    m_fill_rule=fill_rule;
    update();
}

QPen canvas::pen()
{
    return m_pen;
}

QBrush canvas::brush()
{
    return m_brush;
}
enum Shape
{
    Line,
    Rectangle,
    RoundRect,
    Ellipse,
    Polygon,
    Polyline,
    Points,
    Arc,
    Path,
    Text,
    Pixmap
};

void canvas::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    painter.setPen(m_pen);
    painter.setBrush(m_brush);
    QRect rect(50,100,300,200);
    QPoint points[4]=
    {
        QPoint(150,100),
        QPoint(300,150),
        QPoint(350,250),
        QPoint(100,300)
    };
    int start_angle=30*16;
    int end_angle=120*16;
    QPainterPath path;
    path.addRect(150,150,100,100);
    path.moveTo(100,100);
    path.cubicTo(300,100,200,200,300,300);
    path.cubicTo(100,300,200,200,100,100);
    path.setFillRule(m_fill_rule);
    switch(m_shape)
    {
    case Line:
        painter.drawLine(rect.topLeft(),rect.bottomRight());
        break;
    case Rectangle:
        painter.drawRect(rect);
        break;
    case RoundedRect:
        painter.drawRoundedRect(rect,15,15,Qt::RelativeSize);
        break;
    case Ellipse:
        painter.drawEllipse(rect);
        break;
    case Polygon:
        painter.drawPolygon(points,4,m_fill_rule);
        break;
    case Polyline:
        painter.drawPolyline(points,4);
        break;
    case Points:
        painter.drawPoints(points,4);
        break;
    case Arc:
        painter.drawArc(rect,start_angle,end_angle);
        break;
    case Path:
        painter.drawPath(path);
        break;
    case Text:
        painter.drawText(rect,"Hello QT!");
        break;
    case Pixmap:
        painter.drawPixmap(rect,QPixmap(":/image.png"));
        break;
    default:
        break;
    }
}
