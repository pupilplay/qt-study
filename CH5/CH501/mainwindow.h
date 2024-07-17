#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QTextCharFormat>
#include<QImage>
#include<QLabel>
#include<QMenu>
#include<QMenuBar>
#include<QAction>
#include<QComboBox>
#include<QSpinBox>
#include<QToolBar>
#include<QFontComboBox>
#include<QToolButton>
#include<QActionGroup>
#include"workspace.h"

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

    void create_actions();
    void create_menus();
    void create_toolbars();
    void create_font_buttons();
    void create_list_items();
public slots:
    void print_text();
    void print_image();
    void zoomin();
    void zoomout();
    void rotate90();
    void rotate180();
    void rotate270();
    void mirror_horizontal();
    void mirror_vertical();
    void update_info();

private:
    Ui::MainWindow *ui;
    QMenu *file_menu;
    QMenu *zoom_menu;
    QMenu *rotate_menu;
    QMenu *mirror_menu;
    QImage image;
    QString file_name;
    workspace *edit_space;
    QAction *open_file_action;
    QAction *new_file_action;
    QAction *print_text_action;
    QAction *print_image_action;
    QAction *exit_action;
    QAction *copy_action;
    QAction *cut_action;
    QAction *paste_action;
    QAction *about_action;
    QAction *zoomin_action;
    QAction *zoomout_action;
    QAction *rotate90_action;
    QAction *rotate180_action;
    QAction *rotate270_action;
    QAction *mirror_vertical_action;
    QAction *mirror_horizontal_action;
    QAction *undo_action;
    QAction *redo_action;
    QToolBar *file_tool;
    QToolBar *zoom_tool;
    QToolBar *rotate_tool;
    QToolBar *mirror_tool;
    QToolBar *do_toolbar;

    QLabel *font_type_label;
    QFontComboBox *font_box;
    QLabel *font_size_label;
    QComboBox *size_box;
    QToolButton *bold_btn;
    QToolButton *italic_btn;
    QToolButton *underline_btn;
    QToolButton *color_btn;
    QToolBar *font_toolbar;

    QLabel *list_label;
    QComboBox *list_box;
    QActionGroup *act_group;
    QAction *left_action;
    QAction *right_action;
    QAction *center_action;
    QAction *justify_action;
    QToolBar *list_toolbar;
};
#endif // MAINWINDOW_H
