#ifndef PAINTER_DEMO_H
#define PAINTER_DEMO_H

#include <QWidget>
#include "canvas.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class painter_demo;
}
QT_END_NAMESPACE

class painter_demo : public QWidget
{
    Q_OBJECT

public:
    painter_demo(QWidget *parent = nullptr);
    ~painter_demo();
private slots:

    void on_shape_box_activated(int index);

    void on_pen_color_box_clicked();

    void on_brush_color_box_clicked();

    void on_pen_width_box_valueChanged(int width);

    void on_pen_capstyle_box_activated(int index);

    void on_pen_joinstyle_box_activated(int index);

    void on_fill_rule_box_activated(int index);

    void on_spread_box_activated(int index);

    void on_brush_style_box_activated(int index);

private:
    Ui::painter_demo *ui;

    QGradient::Spread spread;
};
#endif // PAINTER_DEMO_H
