#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui
{
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_rotate_slider_valueChanged(int value);

    void on_scale_slider_valueChanged(int value);

    void on_shear_slider_valueChanged(int value);

    void on_translate_slider_valueChanged(int value);

private:
    Ui::Widget *ui;
    int angle;
    qreal scale_value;
    qreal shear_value;
    qreal translate_value;
    QGraphicsScene *scene;
};
#endif // WIDGET_H
