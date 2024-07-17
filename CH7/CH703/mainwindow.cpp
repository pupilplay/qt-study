#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QGraphicsView>
#include<QGraphicsItem>
#include<QRandomGenerator>
#include<QFileDialog>
#include "flash_item.h"
#include "custom_item.h"
#include<QGraphicsItemAnimation>
#include<QTimeLine>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    centralWidget()->deleteLater();
    view =new QGraphicsView();
    setCentralWidget(view);
    scene=new QGraphicsScene(QRectF(-200,-200,400,400),this);
    view->setScene(scene);
    view->setMinimumSize(400,400);
    resize(550,450);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ellipse_action_triggered()
{
    QGraphicsEllipseItem *item=new QGraphicsEllipseItem(QRectF(0,0,80,60));
    item->setPen(Qt::NoPen);
    item->setBrush(QColor(QRandomGenerator::global()->bounded(0,256),
                          QRandomGenerator::global()->bounded(0,256),
                          QRandomGenerator::global()->bounded(0,256)));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos(QRandomGenerator::global()->bounded(static_cast<int>(scene->sceneRect().left()),static_cast<int>(scene->sceneRect().right())),
                 QRandomGenerator::global()->bounded(static_cast<int>(scene->sceneRect().top()),static_cast<int>(scene->sceneRect().right())));
}


void MainWindow::on_polygon_action_triggered()
{
    QList<QPointF>points{QPoint(30,-15),QPoint(0,-30),QPoint(-30,-15),QPoint(-30,15),QPoint(0,30),QPoint(30,15)};
    QGraphicsPolygonItem *item=new QGraphicsPolygonItem(QPolygonF(points));
    item->setBrush(QColor(QRandomGenerator::global()->bounded(0,256),
                          QRandomGenerator::global()->bounded(0,256),
                          QRandomGenerator::global()->bounded(0,256)));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos(QRandomGenerator::global()->bounded(static_cast<int>(scene->sceneRect().left()),static_cast<int>(scene->sceneRect().right())),
                 QRandomGenerator::global()->bounded(static_cast<int>(scene->sceneRect().top()),static_cast<int>(scene->sceneRect().right())));
}


void MainWindow::on_text_action_triggered()
{
    QGraphicsTextItem *item=new QGraphicsTextItem("Hello QT");
    item->setFont(QFont("Times",16));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos(QRandomGenerator::global()->bounded(static_cast<int>(scene->sceneRect().left()),static_cast<int>(scene->sceneRect().right())),
                 QRandomGenerator::global()->bounded(static_cast<int>(scene->sceneRect().top()),static_cast<int>(scene->sceneRect().right())));
}


void MainWindow::on_rect_action_triggered()
{
    QGraphicsRectItem *item=new QGraphicsRectItem(QRectF(0,0,60,60));
    QPen pen;
    pen.setWidth(3);
    pen.setColor(QColor(QRandomGenerator::global()->bounded(0,256),
                        QRandomGenerator::global()->bounded(0,256),
                        QRandomGenerator::global()->bounded(0,256)));
    item->setPen(pen);
    item->setBrush(QColor(QRandomGenerator::global()->bounded(0,256),
                          QRandomGenerator::global()->bounded(0,256),
                          QRandomGenerator::global()->bounded(0,256)));
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos(QRandomGenerator::global()->bounded(static_cast<int>(scene->sceneRect().left()),static_cast<int>(scene->sceneRect().right())),
                 QRandomGenerator::global()->bounded(static_cast<int>(scene->sceneRect().top()),static_cast<int>(scene->sceneRect().right())));
}


void MainWindow::on_pixmap_action_triggered()
{
    QString file_name=QFileDialog::getOpenFileName(this,"Pixmap","./","All(*);;Image(*.png *.jpg *.jpeg");
    if(!file_name.isEmpty())
    {
        QGraphicsPixmapItem *item=new QGraphicsPixmapItem(QPixmap(file_name));
        scene->addItem(item);
        item->setFlag(QGraphicsItem::ItemIsMovable);
        item->setPos(QRandomGenerator::global()->bounded(static_cast<int>(scene->sceneRect().left()),static_cast<int>(scene->sceneRect().right())),
                     QRandomGenerator::global()->bounded(static_cast<int>(scene->sceneRect().top()),static_cast<int>(scene->sceneRect().right())));
    }
}


void MainWindow::on_clear_action_triggered()
{
    scene->deleteLater();
    scene=new QGraphicsScene(QRectF(-200,-200,400,400));
    view->setScene(scene);
}


void MainWindow::on_flashitem_action_triggered()
{
    flash_item *item=new flash_item();
    item->setFlag(QGraphicsItem::ItemIsMovable);
    scene->addItem(item);
    item->setPos(QRandomGenerator::global()->bounded(static_cast<int>(scene->sceneRect().left()),static_cast<int>(scene->sceneRect().right())),
                 QRandomGenerator::global()->bounded(static_cast<int>(scene->sceneRect().top()),static_cast<int>(scene->sceneRect().right())));
}


void MainWindow::on_animation_action_triggered()
{
    custom_item *item=new custom_item();
    QGraphicsItemAnimation *animation=new QGraphicsItemAnimation(scene);
    animation->setItem(item);
    QTimeLine *time_line=new QTimeLine(1000,animation);
    time_line->setEasingCurve(QEasingCurve(QEasingCurve::SineCurve));
    time_line->setLoopCount(0);
    animation->setTimeLine(time_line);
    int y=QRandomGenerator::global()->bounded(static_cast<int>(scene->sceneRect().top()),static_cast<int>(scene->sceneRect().bottom()));
    for(int i=0;i<400;i++)
    {
        animation->setPosAt(i/400.0,QPointF(i-200,y));
    }
    time_line->start();
    scene->addItem(item);
}

