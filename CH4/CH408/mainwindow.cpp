#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QThread::sleep(3);
}

MainWindow::~MainWindow()
{
    delete ui;
}
