#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QGraphicsScene>

QT_BEGIN_NAMESPACE
namespace Ui {
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
    void on_ellipse_action_triggered();

    void on_polygon_action_triggered();

    void on_text_action_triggered();

    void on_rect_action_triggered();

    void on_pixmap_action_triggered();

    void on_clear_action_triggered();

    void on_flashitem_action_triggered();

    void on_animation_action_triggered();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsView *view;
};
#endif // MAINWINDOW_H
