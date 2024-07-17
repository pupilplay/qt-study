#ifndef DRAWER_H
#define DRAWER_H

#include <QObject>
#include <QToolBox>
#include<QToolButton>

class drawer : public QToolBox
{
    Q_OBJECT
public:
    explicit drawer(QWidget *parent=nullptr);

private:
    QToolButton *tool_btn11;
    QToolButton *tool_btn12;
    QToolButton *tool_btn13;
    QToolButton *tool_btn21;
    QToolButton *tool_btn22;
    QToolButton *tool_btn31;

};

#endif // DRAWER_H
