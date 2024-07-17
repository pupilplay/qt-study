#ifndef CONTENT_H
#define CONTENT_H

#include <QFrame>
#include <QObject>
#include<QStackedWidget>
#include"baseinfo.h"
#include"contact.h"
#include"detail.h"

class content : public QFrame
{
    Q_OBJECT
public:
    content(QWidget *parent = nullptr);

public slots:
    void switch_page(int row);

private:
    QVBoxLayout *main_layout;
    QHBoxLayout *btn_layout;
    QStackedWidget *stack;
    baseinfo *baseinfo_page;
    contact *contact_page;
    detail *detail_page;
    QPushButton *ok_btn;
    QPushButton *cancel_btn;
};

#endif // CONTENT_H
