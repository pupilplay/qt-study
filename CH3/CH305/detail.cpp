#include "detail.h"

detail::detail(QWidget *parent)
    : QWidget{parent}
{
    main_layout=new QGridLayout(this);

    nation_label=new QLabel("nation");
    province_label=new QLabel("province");
    city_label=new QLabel("city");
    info_label=new QLabel("info");
    nation_box=new QComboBox();
    nation_box->addItem("a");
    nation_box->addItem("b");
    nation_box->addItem("c");
    province_box=new QComboBox();
    province_box->addItem("a");
    province_box->addItem("b");
    province_box->addItem("c");
    city_input=new QLineEdit();
    info_input=new QTextEdit();

    main_layout->addWidget(nation_label,0,0);
    main_layout->addWidget(province_label,1,0);
    main_layout->addWidget(city_label,2,0);
    main_layout->addWidget(info_label,3,0);
    main_layout->addWidget(nation_box,0,1);
    main_layout->addWidget(province_box,1,1);
    main_layout->addWidget(city_input,2,1);
    main_layout->addWidget(info_input,3,1);
}
