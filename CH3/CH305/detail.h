#ifndef DETAIL_H
#define DETAIL_H

#include <QWidget>
#include<QComboBox>
#include<QLabel>
#include<QLineEdit>
#include<QTextEdit>
#include<QGridLayout>

class detail : public QWidget
{
    Q_OBJECT
public:
    explicit detail(QWidget *parent = nullptr);

private:
    QGridLayout *main_layout;
    QLabel *nation_label;
    QLabel *province_label;
    QLabel *city_label;
    QLabel *info_label;
    QComboBox *nation_box;
    QComboBox *province_box;
    QLineEdit *city_input;
    QTextEdit *info_input;
};

#endif // DETAIL_H
