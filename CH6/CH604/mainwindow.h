#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"svg_window.h"

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

private:
    Ui::MainWindow *ui;
    svg_window *main_window;
};
#endif // MAINWINDOW_H
