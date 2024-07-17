#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include<QComboBox>

QT_BEGIN_NAMESPACE
namespace Ui
{
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
    void on_window_box_activated(int index);

    void on_windowtext_box_activated(int index);

    void on_button_box_activated(int index);

    void on_buttontext_box_activated(int index);

    void on_base_box_activated(int index);

private:
    void fill_colorlist(QComboBox* box);
    QStringList color_list;
    Ui::Dialog *ui;
};
#endif // DIALOG_H
