#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QDomDocument>
#include <QSqlRelationalTableModel>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(const QString &manufactory_table,const QString &car_table,QFile *car_details,QWidget *parent = nullptr);
    ~MainWindow();
private slots:
    void on_exit_action_triggered();
    void on_add_action_triggered();
    void on_remove_action_triggered();

    void update_manufactory(const QModelIndex &index);
    void update_car_detail(const QModelIndex &index);
    void update_manufactory_profile(const QModelIndex &index);

private:
    QModelIndex manufactory_index(const QString &manufactory);
    void update_detail_list(QDomNode car);
    void remove_car_from_file(int id);
    void remove_car_from_database(const QModelIndex &index);
    void decrease_car_count(const QModelIndex &index);
    Ui::MainWindow *ui;
    QFile *file;
    QDomDocument data;
    QSqlRelationalTableModel *car_model;
    QSqlTableModel *manufactory_model;

};
#endif // MAINWINDOW_H
