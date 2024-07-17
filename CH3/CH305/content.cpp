#include "content.h"

content::content(QWidget *parent):QFrame{parent}

{
    main_layout=new QVBoxLayout(this);
    btn_layout=new QHBoxLayout();
    stack=new QStackedWidget();
    stack->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    baseinfo_page=new baseinfo();
    contact_page=new contact();
    detail_page=new detail();
    stack->addWidget(baseinfo_page);
    stack->addWidget(contact_page);
    stack->addWidget(detail_page);
    main_layout->addWidget(stack);
    main_layout->addLayout(btn_layout);
    ok_btn=new QPushButton("OK");
    cancel_btn=new QPushButton("Cancel");
    btn_layout->addStretch();
    btn_layout->addWidget(ok_btn);
    btn_layout->addWidget(cancel_btn);

    main_layout->setContentsMargins(QMargins(10,10,10,10));
    main_layout->setSpacing(10);
}

void content::switch_page(int row)
{
    stack->setCurrentIndex(row);
}
