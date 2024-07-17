#include "painter_demo.h"
#include "./ui_painter_demo.h"
#include<QColorDialog>

painter_demo::painter_demo(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::painter_demo)
{
    ui->setupUi(this);
    ui->pen_color_box->setPalette(QPalette(Qt::black));
    ui->pen_color_box->setAutoFillBackground(true);
    ui->brush_color_box->setPalette(QPalette(Qt::black));
    ui->brush_color_box->setAutoFillBackground(true);

    ui->shape_box->addItem("Line",canvas::Shape::Line);
    ui->shape_box->addItem("Rectangle",canvas::Shape::Rectangle);
    ui->shape_box->addItem("RoundedRect",canvas::Shape::RoundedRect);
    ui->shape_box->addItem("Ellipse",canvas::Shape::Ellipse);
    ui->shape_box->addItem("Polygon",canvas::Shape::Polygon);
    ui->shape_box->addItem("Polyline",canvas::Shape::Polyline);
    ui->shape_box->addItem("Points",canvas::Shape::Points);
    ui->shape_box->addItem("Arc",canvas::Shape::Arc);
    ui->shape_box->addItem("Path",canvas::Shape::Path);
    ui->shape_box->addItem("Text",canvas::Shape::Text);
    ui->shape_box->addItem("Pixmap",canvas::Shape::Pixmap);

    ui->pen_capstyle_box->addItem("FlatCap",Qt::FlatCap);
    ui->pen_capstyle_box->addItem("SquareCap",Qt::SquareCap);
    ui->pen_capstyle_box->addItem("RoundCap",Qt::RoundCap);

    ui->pen_joinstyle_box->addItem("MiterJoin",Qt::MiterJoin);
    ui->pen_joinstyle_box->addItem("BevelJoin",Qt::BevelJoin);
    ui->pen_joinstyle_box->addItem("RoundJoin",Qt::RoundJoin);
    ui->pen_joinstyle_box->addItem("SvgMiterJoin",Qt::SvgMiterJoin);

    ui->fill_rule_box->addItem("OddEvenFill",Qt::OddEvenFill);
    ui->fill_rule_box->addItem("WindingFill",Qt::WindingFill);

    ui->spread_box->addItem("PadSpread",QGradient::PadSpread);
    ui->spread_box->addItem("RepeatSpread",QGradient::RepeatSpread);
    ui->spread_box->addItem("ReflectSpread",QGradient::ReflectSpread);

    ui->brush_style_box->addItem("NoBrush",static_cast<int>(Qt::NoBrush));
    ui->brush_style_box->addItem("SolidPattern",static_cast<int>(Qt::SolidPattern));
    ui->brush_style_box->addItem("Dense1Pattern",static_cast<int>(Qt::Dense1Pattern));
    ui->brush_style_box->addItem("Dense2Pattern",static_cast<int>(Qt::Dense2Pattern));
    ui->brush_style_box->addItem("Dense3Pattern",static_cast<int>(Qt::Dense3Pattern));
    ui->brush_style_box->addItem("Dense4Pattern",static_cast<int>(Qt::Dense4Pattern));
    ui->brush_style_box->addItem("Dense5Pattern",static_cast<int>(Qt::Dense5Pattern));
    ui->brush_style_box->addItem("Dense6Pattern",static_cast<int>(Qt::Dense6Pattern));
    ui->brush_style_box->addItem("Dense7Pattern",static_cast<int>(Qt::Dense7Pattern));
    ui->brush_style_box->addItem("HorPattern",static_cast<int>(Qt::HorPattern));
    ui->brush_style_box->addItem("VerPattern",static_cast<int>(Qt::VerPattern));
    ui->brush_style_box->addItem("CrossPattern",static_cast<int>(Qt::CrossPattern));
    ui->brush_style_box->addItem("BDiagPattern",static_cast<int>(Qt::BDiagPattern));
    ui->brush_style_box->addItem("FDiagPattern",static_cast<int>(Qt::FDiagPattern));
    ui->brush_style_box->addItem("DiagCrossPattern",static_cast<int>(Qt::DiagCrossPattern));
    ui->brush_style_box->addItem("LinearGradientPattern",static_cast<int>(Qt::LinearGradientPattern));
    ui->brush_style_box->addItem("ConicalGradientPattern",static_cast<int>(Qt::ConicalGradientPattern));
    ui->brush_style_box->addItem("RadialGradientPattern",static_cast<int>(Qt::RadialGradientPattern));
}

painter_demo::~painter_demo()
{
    delete ui;
}

void painter_demo::on_pen_color_box_clicked()
{
    QColorDialog dlg;
    dlg.adjustSize();
    if(dlg.exec())
    {
        QColor color=dlg.currentColor();
        ui->pen_color_box->setPalette(QPalette(color));
        QPen pen=ui->canvas_widget->pen();
        pen.setColor(color);
        ui->canvas_widget->set_pen(pen);
    }
}


void painter_demo::on_brush_color_box_clicked()
{
    QColorDialog dlg;
    dlg.adjustSize();
    if(dlg.exec())
    {
        QColor color=dlg.currentColor();
        ui->brush_color_box->setPalette(QPalette(color));
        QBrush brush=ui->canvas_widget->brush();
        brush.setColor(color);
        ui->canvas_widget->set_brush(brush);
    }
}


void painter_demo::on_shape_box_activated(int index)
{
    ui->canvas_widget->set_shape(
    static_cast<canvas::Shape>(ui->shape_box->itemData(ui->shape_box->currentIndex()).toInt()));
}


void painter_demo::on_pen_width_box_valueChanged(int width)
{
    QPen pen=ui->canvas_widget->pen();
    pen.setWidth(width);
    ui->canvas_widget->set_pen(pen);
}


void painter_demo::on_pen_capstyle_box_activated(int index)
{
    QPen pen=ui->canvas_widget->pen();
    pen.setCapStyle(
    static_cast<Qt::PenCapStyle>(ui->pen_capstyle_box->itemData(ui->pen_capstyle_box->currentIndex()).toInt()));
    ui->canvas_widget->set_pen(pen);
}

void painter_demo::on_pen_joinstyle_box_activated(int index)
{
    QPen pen=ui->canvas_widget->pen();
    pen.setJoinStyle(
        static_cast<Qt::PenJoinStyle>(ui->pen_joinstyle_box->itemData(ui->pen_joinstyle_box->currentIndex()).toInt()));
    ui->canvas_widget->set_pen(pen);
}


void painter_demo::on_fill_rule_box_activated(int index)
{
    ui->canvas_widget->set_fill_rule(
        static_cast<Qt::FillRule>(ui->fill_rule_box->itemData(ui->fill_rule_box->currentIndex()).toInt()));
}


void painter_demo::on_spread_box_activated(int index)
{
    spread=static_cast<QGradient::Spread>
        (ui->spread_box->itemData((ui->spread_box->currentIndex())).toInt());
}


void painter_demo::on_brush_style_box_activated(int index)
{
    Qt::BrushStyle style=static_cast<Qt::BrushStyle>
        (ui->brush_style_box->itemData(ui->brush_style_box->currentIndex()).toInt());
    switch(style)
    {
        case Qt::LinearGradientPattern:
        {
            QLinearGradient gradient(0,0,400,400);
            gradient.setColorAt(0,Qt::white);
            gradient.setColorAt(0.5,ui->brush_color_box->palette().color(QPalette::Button));
            gradient.setColorAt(1.0,Qt::black);
            gradient.setSpread(spread);
            ui->canvas_widget->set_brush(gradient);
            break;
        }
        case Qt::RadialGradientPattern:
        {
            QRadialGradient gradient(200,200,150,150,100);
            gradient.setColorAt(0,Qt::white);
            gradient.setColorAt(0.5,ui->brush_color_box->palette().color(QPalette::Button));
            gradient.setColorAt(1.0,Qt::black);
            ui->canvas_widget->set_brush(gradient);
            break;
        }
        case Qt::ConicalGradientPattern:
        {
            QConicalGradient gradient(200,200,30);
            gradient.setColorAt(0,Qt::white);
            gradient.setColorAt(0.5,ui->brush_color_box->palette().color(QPalette::Button));
            gradient.setColorAt(1.0,Qt::black);
            gradient.setSpread(spread);
            ui->canvas_widget->set_brush(gradient);
            break;
        }
        default:
        {
            QBrush brush=ui->canvas_widget->brush();
            brush.setStyle(style);
            ui->canvas_widget->set_brush(brush);
            break;
        }
    }
}
