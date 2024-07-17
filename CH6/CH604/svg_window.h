#ifndef SVG_WINDOW_H
#define SVG_WINDOW_H

#include <QScrollArea>
#include <QWidget>
#include<QMouseEvent>
#include"svg_widget.h"
class svg_window : public QScrollArea
{
    Q_OBJECT
public:
    svg_window(QWidget *parent = nullptr);
    void set_file(QString file_name);
protected:
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;
private:
    svg_widget *main_widget;
    QPoint start_pos;
    int horizontal_bar_start_value;
    int vertical_bar_start_value;
};

#endif // SVG_WINDOW_H
