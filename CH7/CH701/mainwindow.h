#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "custom_item.h"
#include<QGraphicsScene>
#include<QMouseEvent>
#include<QLabel>
#include "my_graphics_view.h"

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
public slots:
    void pos_update(QPoint pos);
private:
    Ui::MainWindow *ui;
    QLabel *pos_label;
};
#endif // MAINWINDOW_H
