#ifndef EDIT_DIALOG_H
#define EDIT_DIALOG_H

#include <QDialog>
#include<QSqlRelationalTableModel>
#include<QSqlTableModel>
#include<QDomDocument>
#include<QFile>

namespace Ui
{
class edit_dialog;
}

class edit_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit edit_dialog(QSqlRelationalTableModel *car_model,
        QSqlTableModel *manufactory_model,QDomDocument data,
        QFile *file,QWidget *parent = nullptr);
    ~edit_dialog();

private slots:
    void on_submit_button_clicked();

    void on_rever_button_clicked();

private:
    int new_manufactory(const QString &manufactory,const QString &address);
    int new_car(const QString &name,int manufactory_id);
    int get_manufactory_id(const QString &manufactory);
    void write_detail(int car_id,QStringList details);
    Ui::edit_dialog *ui;
    QFile *file;
    QDomDocument data;
    QSqlRelationalTableModel *car_model;
    QSqlTableModel *manufactory_model;
};

#endif // EDIT_DIALOG_H
