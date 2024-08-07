#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QKeyEvent>
#include <QPaintEvent>

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
    void draw_pix();
protected:
    void keyPressEvent(QKeyEvent *ev) override;
    void paintEvent(QPaintEvent *ev) override;
private:
    Ui::Widget *ui;
    QPixmap *pix;
    QImage image;
    int start_x;
    int start_y;
    int width;
    int height;
    int step;
};
#endif // WIDGET_H
