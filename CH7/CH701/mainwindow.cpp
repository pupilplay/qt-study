#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pos_label=new QLabel();
    ui->statusbar->addWidget(pos_label);
    pos_label->show();
    QGraphicsScene *scene=new QGraphicsScene();
    scene->setSceneRect(-200,-200,400,400);
    custom_item *item=new custom_item();
    item->setPos(0,0);
    scene->addItem(item);
    my_graphics_view *view=new my_graphics_view();
    setCentralWidget(view);
    view->setScene(scene);
    view->resize(400,400);
    connect(view,&my_graphics_view::pos_signal,this,&MainWindow::pos_update);
    view->show();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pos_update(QPoint pos)
{
    pos_label->setText(QString::number(pos.x())+","+QString::number(pos.y()));
}

