#ifndef EVENT_FILTER_DEMO_H
#define EVENT_FILTER_DEMO_H

#include <QDialog>
#include <QLabel>
#include <QEvent>
#include <QMouseEvent>

namespace Ui
{
class event_filter_demo;
}

class event_filter_demo : public QDialog
{
    Q_OBJECT

public:
    explicit event_filter_demo(QWidget *parent = nullptr);
    ~event_filter_demo();
protected:
    bool eventFilter(QObject *watched,QEvent *event) override;

private:
    Ui::event_filter_demo *ui;
    QImage image;
};

#endif // EVENT_FILTER_DEMO_H
