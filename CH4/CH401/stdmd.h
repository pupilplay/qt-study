#ifndef STDMD_H
#define STDMD_H

#include <QDialog>

namespace Ui {
class stdmd;
}

class stdmd : public QDialog
{
    Q_OBJECT

public:
    explicit stdmd(QWidget *parent = nullptr);
    ~stdmd();

private slots:
    void on_question_btn_clicked();

    void on_information_btn_clicked();

    void on_warning_btn_clicked();

    void on_critical_btn_clicked();

    void on_about_btn_clicked();

    void on_aboutQT_btn_clicked();

private:
    Ui::stdmd *ui;
};

#endif // STDMD_H
