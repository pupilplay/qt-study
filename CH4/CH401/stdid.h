#ifndef STDID_H
#define STDID_H

#include <QDialog>

namespace Ui {
class stdid;
}

class stdid : public QDialog
{
    Q_OBJECT

public:
    explicit stdid(QWidget *parent = nullptr);
    ~stdid();

private slots:
    void on_name_btn_clicked();

    void on_gender_btn_clicked();

    void on_age_btn_clicked();

    void on_score_btn_clicked();

private:
    Ui::stdid *ui;
};

#endif // STDID_H
