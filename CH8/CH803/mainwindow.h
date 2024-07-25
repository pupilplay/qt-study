#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include <QTableView>
#include <QStandardItemModel>
#include <QItemSelectionModel>
#include "histogram_view.h"

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
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_open_action_triggered();

private:
    Ui::MainWindow *ui;
    QSplitter *splitter;
    QTableView *table;
    histogram_view *histogram;
    QStandardItemModel *model;
    QItemSelectionModel *selection;
};
#endif // MAINWINDOW_H
