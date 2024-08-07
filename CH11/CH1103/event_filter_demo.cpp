#include "event_filter_demo.h"
#include "ui_event_filter_demo.h"

event_filter_demo::event_filter_demo(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::event_filter_demo)
{
    ui->setupUi(this);
    image.load(":/1.png");
    image=image.scaled(96,96);
    ui->label_left->setPixmap(QPixmap::fromImage(image));
    ui->label_middle->setPixmap(QPixmap::fromImage(image));
    ui->label_right->setPixmap(QPixmap::fromImage(image));
    ui->label_left->installEventFilter(this);
    ui->label_middle->installEventFilter(this);
    ui->label_right->installEventFilter(this);
}

event_filter_demo::~event_filter_demo()
{
    delete ui;
}

bool event_filter_demo::eventFilter(QObject *watched, QEvent *event)
{
    QMouseEvent *ev=static_cast<QMouseEvent*>(event);
    QLabel *label=static_cast<QLabel*>(watched);
    switch(event->type())
    {
    case QEvent::MouseButtonPress:
    {
        switch(ev->button())
        {
        case Qt::LeftButton:
            ui->message_label->setText("Left pressed "+label->objectName());
            break;
        case Qt::RightButton:
            ui->message_label->setText("Right pressed "+label->objectName());
            break;
        case Qt::MiddleButton:
            ui->message_label->setText("Middle pressed "+label->objectName());
            break;
        default:
            break;
        }
        QTransform matrix;
        matrix.scale(1.8,1.8);
        QImage transformed_image=image.transformed(matrix);
        label->setPixmap(QPixmap::fromImage(transformed_image));
        break;
    }
    case QEvent::MouseButtonRelease:
        label->setPixmap(QPixmap::fromImage(image));
        ui->message_label->setText("Released "+label->objectName());
    default:
        break;
    }
    return QDialog::eventFilter(watched,event);
}
