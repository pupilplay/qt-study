#include "contact.h"
contact::contact(QWidget *parent)
    : QWidget{parent}
{
    main_layout=new QGridLayout(this);

    email_label= new QLabel("email");
    address_label= new QLabel("address");
    mail_label= new QLabel("mail");
    phone_label= new QLabel("phone");
    dial_label= new QLabel("dial");
    email_input=new QLineEdit();
    address_input=new QLineEdit();
    mail_input =new QLineEdit();
    phone_input=new QLineEdit();
    dial_input=new QLineEdit();
    phone_check=new QCheckBox("accept message");

    main_layout->addWidget(email_label,0,0);
    main_layout->addWidget(address_label,1,0);
    main_layout->addWidget(mail_label,2,0);
    main_layout->addWidget(phone_label,3,0);
    main_layout->addWidget(dial_label,4,0);
    main_layout->addWidget(email_input,0,1);
    main_layout->addWidget(address_input,1,1);
    main_layout->addWidget(mail_input,2,1);
    main_layout->addWidget(phone_input,3,1);
    main_layout->addWidget(dial_input,4,1);
    main_layout->addWidget(phone_check,3,2);
}
