#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setStatusBar(new QStatusBar());
    tip_label=new QLabel("Current pos:");
    pos_label=new QLabel("");
    statusBar()->addPermanentWidget(tip_label);
    statusBar()->addPermanentWidget(pos_label);
    this->setMouseTracking(true);
    this->centralWidget()->setMouseTracking(true);
    resize(400,200);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *ev)
{
    QString str="("+QString::number(ev->position().x())+","+QString::number(ev->position().y())+")";
    switch(ev->button())
    {
    case Qt::LeftButton:
        statusBar()->showMessage("Left pressed:"+str);
        break;
    case Qt::RightButton:
        statusBar()->showMessage("Right pressed:"+str);
        break;
    case Qt::MiddleButton:
        statusBar()->showMessage("Middle pressed:"+str);
        break;
    default:
        break;
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent *ev)
{
    QString str="("+QString::number(ev->position().x())+","+QString::number(ev->position().y())+")";
    statusBar()->showMessage("Released:"+str);
}

void MainWindow::mouseMoveEvent(QMouseEvent *ev)
{
    pos_label->setText("("+QString::number(ev->position().x())+","+QString::number(ev->position().y())+")");
}
