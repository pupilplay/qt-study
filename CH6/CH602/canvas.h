#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>

class canvas : public QWidget
{
    Q_OBJECT
public:
    enum Shape
    {
        Line,
        Rectangle,
        RoundedRect,
        Ellipse,
        Polygon,
        Polyline,
        Points,
        Arc,
        Path,
        Text,
        Pixmap
    };

    explicit canvas(QWidget *parent = nullptr);
    void set_shape(Shape shape);
    void set_pen(QPen pen);
    void set_brush(QBrush brush);
    void set_fill_rule(Qt::FillRule fill_rule);
    QPen pen();
    QBrush brush();
protected:
    void paintEvent(QPaintEvent *ev) override;
private:
    Shape m_shape;
    QPen m_pen;
    QBrush m_brush;
    Qt::FillRule m_fill_rule;
};

#endif // CANVAS_H
