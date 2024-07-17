#ifndef DIGIT_CLOCK_H
#define DIGIT_CLOCK_H

#include <QLCDNumber>
#include <QObject>
#include<QLCDNumber>
#include<QMouseEvent>
class digit_clock : public QLCDNumber
{
    Q_OBJECT
public:
    digit_clock(QWidget *parent=nullptr);
protected:
    void mousePressEvent(QMouseEvent *ev) override;
    void mouseMoveEvent(QMouseEvent *ev) override;
private slots:
    void update_time();
private:
    QPoint pos;
};

#endif // DIGIT_CLOCK_H
