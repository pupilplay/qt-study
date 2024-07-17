#ifndef SVG_WIDGET_H
#define SVG_WIDGET_H

#include<QtSvgWidgets/QtSvgWidgets>
#include <QWidget>
#include<QWheelEvent>
class svg_widget : public QSvgWidget
{
    Q_OBJECT
public:
    svg_widget(QWidget *parent = nullptr);
protected:
    void wheelEvent(QWheelEvent *ev) override;

private:
    QSvgRenderer *render;
};

#endif // SVG_WIDGET_H
