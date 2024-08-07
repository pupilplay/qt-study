#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "worker_thread.h"
#define MAXSIZE 5


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
    void on_start_button_clicked();

    void on_stop_button_clicked();

private:
    Ui::Dialog *ui;
    worker_thread *workers[MAXSIZE];
};
#endif // DIALOG_H
