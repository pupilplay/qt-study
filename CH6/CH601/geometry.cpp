#include "geometry.h"
#include "./ui_geometry.h"

void Geometry::resizeEvent(QResizeEvent *ev)
{
    update_label();
}

void Geometry::moveEvent(QMoveEvent *ev)
{
    update_label();
}

Geometry::Geometry(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Geometry)
{
    ui->setupUi(this);
}

Geometry::~Geometry()
{
    delete ui;
}

void Geometry::update_label()
{
    ui->x_value->setText(QString::number(this->x()));
    ui->y_value->setText(QString::number(this->y()));
    QString pos_str=QString::number(this->pos().x())+","+QString::number(this->pos().y());
    ui->pos_value->setText(pos_str);
    QRect frame_rect=this->frameGeometry();
    QString frame_str=QString::number(frame_rect.x())+","
    +QString::number(frame_rect.y())+","
    +QString::number(frame_rect.width())+","
    +QString::number(frame_rect.height());
    ui->frame_value->setText(frame_str);
    QRect geo=this->geometry();
    QString geo_str=QString::number(geo.x())+","
    +QString::number(geo.y())+","
    +QString::number(geo.width())+","
    +QString::number(geo.height());
    ui->geometry_value->setText(geo_str);
    ui->width_value->setText(QString::number(this->width()));
    ui->height_value->setText(QString::number(this->height()));
    QRect rect=this->rect();
    QString rect_str=QString::number(rect.x())+","
    +QString::number(rect.y())+","
    +QString::number(rect.width())+","
    +QString::number(rect.height());
    ui->rect_value->setText(rect_str);
    QSize size=this->size();
    QString size_str=QString::number(size.width())+","+QString::number(size.height());
    ui->size_value->setText(size_str);
}
