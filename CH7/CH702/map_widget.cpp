#include "map_widget.h"

map_widget::map_widget(QWidget *parent)
    :QGraphicsView(parent)
{
    m_image.load(":/image.png");
    this->setMouseTracking(true);
    m_zoom=250;
    m_scene=new QGraphicsScene(this);
    m_scene->setSceneRect(-m_image.width()/2,-m_image.height()/2,m_image.width(),m_image.height());
    setScene(m_scene);
    setCacheMode(QGraphicsView::CacheBackground);
    view_coordinate_label=new QLabel("GraphicsView:");
    view_coordinate_label->setMouseTracking(true);
    view_coordinate_label->setStyleSheet("color:orange;");
    view_coordinate_value=new QLabel();
    view_coordinate_value->setMouseTracking(true);
    view_coordinate_value->setStyleSheet("color:orange;");
    scene_coordinate_label=new QLabel("GraphicsScene:");
    scene_coordinate_label->setMouseTracking(true);
    scene_coordinate_label->setStyleSheet("color:orange;");
    scene_coordinate_value=new QLabel();
    scene_coordinate_value->setMouseTracking(true);
    scene_coordinate_value->setStyleSheet("color:orange;");
    coordinate_inside_layout=new QGridLayout();
    coordinate_inside_layout->addWidget(view_coordinate_label,0,0);
    coordinate_inside_layout->addWidget(view_coordinate_value,0,1);
    coordinate_inside_layout->addWidget(scene_coordinate_label,1,0);
    coordinate_inside_layout->addWidget(scene_coordinate_value,1,1);
    coordinate_inside_layout->setSizeConstraint(QLayout::SetFixedSize);
    QFrame *coordinate_frame=new QFrame();
    coordinate_frame->setMouseTracking(true);
    coordinate_frame->setLayout(coordinate_inside_layout);
    coordinate_outside_layout = new QVBoxLayout();
    coordinate_outside_layout->addWidget(coordinate_frame);
    coordinate_outside_layout->addStretch();
    zoomin_label=new QLabel();
    zoomin_label->setMouseTracking(true);
    zoomin_label->setScaledContents(true);
    zoomin_label->setPixmap(QPixmap(":/zoomin.png"));
    slider = new QSlider(Qt::Vertical);
    slider->setMouseTracking(true);
    slider->setRange(0,500);
    slider->setTickInterval(10);
    slider->setValue(250);
    connect(slider,&QSlider::valueChanged,this,&map_widget::zoom);
    zoomout_label=new QLabel();
    zoomout_label->setMouseTracking(true);
    zoomout_label->setScaledContents(true);
    zoomout_label->setPixmap(QPixmap(":/zoomout.png"));
    zoom_layout=new QVBoxLayout();
    zoom_layout->addWidget(zoomin_label);
    zoom_layout->addWidget(slider);
    zoom_layout->addWidget(zoomout_label);
    main_layout =new QHBoxLayout(this);
    main_layout->addLayout(zoom_layout);
    main_layout->addLayout(coordinate_outside_layout);
    main_layout->addStretch();
}

void map_widget::zoom(int value)
{
    qreal s;
    if(value>m_zoom)
    {
        s=pow(1.01,value-m_zoom);
    }
    else
    {
        s=pow(1/1.01,m_zoom-value);
    }
    scale(s,s);
    m_zoom=value;
}

void map_widget::drawBackground(QPainter *painter, const QRectF &rect)
{
    painter->drawPixmap(sceneRect().topLeft(),m_image);
}

void map_widget::mouseMoveEvent(QMouseEvent *ev)
{
    QPoint view_pos=ev->pos();
    QPoint scene_pos=this->mapToScene(view_pos).toPoint();
    view_coordinate_value->setText(QString::number(view_pos.x())+","+QString::number(view_pos.y()));
    scene_coordinate_value->setText(QString::number(scene_pos.x())+","+QString::number(scene_pos.y()));
}
