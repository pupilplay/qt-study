#ifndef MAP_WIDGET_H
#define MAP_WIDGET_H

#include <QGraphicsView>
#include<QPixmap>
#include<QLabel>
#include<QPainter>
#include<QMouseEvent>
#include<QSlider>
#include<QGridLayout>
#include<QGraphicsScene>
class map_widget : public QGraphicsView
{
    Q_OBJECT
public:
    map_widget(QWidget *parent = nullptr);
public slots:
    void zoom(int value);
protected:
    void drawBackground(QPainter *painter,const QRectF &rect) override;
    void mouseMoveEvent(QMouseEvent *ev) override;
private:
    QPixmap m_image;
    qreal m_zoom;
    QLabel *view_coordinate_label;
    QLabel *view_coordinate_value;
    QLabel *scene_coordinate_label;
    QLabel *scene_coordinate_value;
    QLabel *zoomin_label;
    QSlider *slider;
    QLabel *zoomout_label;
    QGridLayout *coordinate_inside_layout;
    QVBoxLayout *coordinate_outside_layout;
    QVBoxLayout *zoom_layout;
    QHBoxLayout *main_layout;
    QGraphicsScene *m_scene;
};

#endif // MAP_WIDGET_H
