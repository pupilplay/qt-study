#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QTextEdit>
#include<QDockWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("DockWindows");
    QTextEdit *main_text=new QTextEdit(this);
    main_text->setText("Main Window");
    main_text->setAlignment(Qt::AlignCenter);
    setCentralWidget(main_text);

    QDockWidget* dock1=new QDockWidget("DockWindow1",this);
    dock1->setFeatures(QDockWidget::DockWidgetMovable);
    dock1->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
    QTextEdit *text1=new QTextEdit(this);
    text1->setText("movable");
    text1->setAlignment(Qt::AlignCenter);
    dock1->setWidget(text1);
    addDockWidget(Qt::RightDockWidgetArea,dock1);

    QDockWidget* dock2=new QDockWidget("DockWindow2",this);
    dock2->setFeatures(QDockWidget::DockWidgetFloatable|QDockWidget::DockWidgetClosable);
    QTextEdit *text2=new QTextEdit(this);
    text2->setText("floatable,closable");
    text2->setAlignment(Qt::AlignCenter);
    dock2->setWidget(text2);
    addDockWidget(Qt::RightDockWidgetArea,dock2);

    QDockWidget* dock3=new QDockWidget("DockWindow3",this);
    dock3->setFeatures(QDockWidget::DockWidgetMovable|QDockWidget::DockWidgetClosable|QDockWidget::DockWidgetFloatable);
    QTextEdit *text3=new QTextEdit(this);
    text3->setText("closable, movable, floatable");
    text3->setAlignment(Qt::AlignCenter);
    dock3->setWidget(text3);
    addDockWidget(Qt::RightDockWidgetArea,dock3);
}

MainWindow::~MainWindow()
{
    delete ui;
}
