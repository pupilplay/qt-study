#ifndef BASEINFO_H
#define BASEINFO_H

#include <QObject>
#include <QWidget>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QGridLayout>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QComboBox>
#include<QTextEdit>

class baseinfo : public QWidget
{
    Q_OBJECT
public:
    explicit baseinfo(QWidget *parent = nullptr);

private:
    QGridLayout *main_layout;

    QGridLayout *left_layout;
    QLabel *username_label;
    QLineEdit *username_input;
    QLabel *nickname_label;
    QLineEdit *nickname_input;
    QLabel *gender_label;
    QComboBox *gender_box;
    QLabel *department_label;
    QTextEdit *department_input;
    QLabel *age_label;
    QLineEdit *age_input;
    QLabel *note_label;

    QVBoxLayout *right_layout;
    QHBoxLayout *profile_layout;
    QLabel *profile_label;
    QLabel *profile_image;
    QPushButton *profile_update_btn;
    QLabel *info_label;
    QTextEdit *info_input;
};

#endif // BASEINFO_H
