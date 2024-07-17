#ifndef CONTACT_H
#define CONTACT_H

#include <QWidget>
#include<QCheckBox>
#include<QLabel>
#include<QLineEdit>
#include<QGridLayout>

class contact : public QWidget
{
    Q_OBJECT
public:
    explicit contact(QWidget *parent = nullptr);


private:
    QGridLayout *main_layout;
    QLabel *email_label;
    QLabel *address_label;
    QLabel *mail_label;
    QLabel *phone_label;
    QLabel *dial_label;
    QLineEdit *email_input;
    QLineEdit *address_input;
    QLineEdit *mail_input;
    QLineEdit *phone_input;
    QLineEdit *dial_input;
    QCheckBox *phone_check;
};

#endif // CONTACT_H
