#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QPainter>
#include<QMouseEvent>

class canvas : public QWidget
{
    Q_OBJECT
public:
    explicit canvas(QWidget *parent = nullptr);
protected:

    void mousePressEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;
    void paintEvent(QPaintEvent *ev) override;
    void resizeEvent(QResizeEvent *ev) override;

signals:
public slots:
    void set_style(int style);
    void set_width(int width);
    void set_color(QColor color);
    void clear();
private:
    QPixmap pix;
    QPen m_pen;
    QPoint start_pos;
    QPoint end_pos;
};

#endif // CANVAS_H
