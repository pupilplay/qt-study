#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    main_window=new svg_window();
    setCentralWidget(main_window);
    connect(ui->open_action,&QAction::triggered,this,[this]()->void
    {
        QString file_name=QFileDialog::getOpenFileName(this,"Open","./","All(*);;Svg(*.svg)");
        if(!file_name.isEmpty())
        {
            main_window->set_file(file_name);
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
