#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QLabel>
#include<QLineEdit>
#include <QGridLayout>

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

private slots:
    void calculate_area();

private:
    Ui::Dialog *ui;
    QLabel *radius_label,*size_label,*size_val_label;
    QLineEdit *radius_input;
    QGridLayout *main_layout;
};
#endif // DIALOG_H
