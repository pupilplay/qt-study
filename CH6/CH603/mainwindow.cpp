#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "canvas.h"
#include<QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    canvas *board=new canvas();
    this->setCentralWidget(board);
    QLabel *style_label=new QLabel("Style:");
    QComboBox *style_box=new QComboBox();
    style_box->addItem("SolidLine",static_cast<int>(Qt::SolidLine));
    style_box->addItem("DashLine",static_cast<int>(Qt::DashLine));
    style_box->addItem("DotLine",static_cast<int>(Qt::DotLine));
    style_box->addItem("DashDotLine",static_cast<int>(Qt::DashDotLine));
    style_box->addItem("DashDotDotLine",static_cast<int>(Qt::DashDotDotLine));
    QLabel *width_label=new QLabel("Width:");
    QSpinBox *width_box=new QSpinBox();
    width_box->setMinimumSize(80,ui->toolbar->height());
    width_box->setMaximum(100);
    width_box->setMinimum(1);
    width_box->setValue(1);
    QPushButton *color_button=new QPushButton();
    color_button->setAutoFillBackground(true);
    color_button->setPalette(QPalette(Qt::black));
    QPushButton *clear_button=new QPushButton("Clear");
    ui->toolbar->addWidget(style_label);
    ui->toolbar->addWidget(style_box);
    ui->toolbar->addWidget(width_label);
    ui->toolbar->addWidget(width_box);
    ui->toolbar->addWidget(color_button);
    ui->toolbar->addWidget(clear_button);
    connect(style_box,&QComboBox::activated,board,[style_box,board]()->void
    {
        board->set_style(style_box->itemData(style_box->currentIndex()).toInt());
    });
    connect(width_box,&QSpinBox::valueChanged,board,&canvas::set_width);
    connect(color_button,&QPushButton::clicked,this,[color_button,board]()->void
    {
        QColorDialog dlg;
        dlg.adjustSize();
        if(dlg.exec())
        {
            color_button->setPalette(dlg.currentColor());
            board->set_color(dlg.currentColor());
        }
    });
    connect(clear_button,&QPushButton::clicked,board,&canvas::clear);
}

MainWindow::~MainWindow()
{
    delete ui;
}
