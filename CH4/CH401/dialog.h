#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

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

    void on_file_btn_clicked();

    void on_color_btn_clicked();

    void on_font_btn_clicked();

    void on_stdid_btn_clicked();

    void on_custom_btn_clicked();

    void on_stdmd_btn_clicked();

private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
