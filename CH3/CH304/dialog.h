#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QGridLayout>
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QComboBox>
#include<QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
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

    QHBoxLayout *bottom_layout;
    QPushButton *ok_btn;
    QPushButton *cancel_btn;
};
#endif // DIALOG_H
