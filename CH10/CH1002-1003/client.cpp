#include "client.h"
#include "ui_client.h"
#include <QIntValidator>

client::client(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::client)
{
    ui->setupUi(this);
    ui->interval_edit->setValidator(new QIntValidator(10,99999,ui->interval_edit));
    timer=new QTimer(this);
    socket= new QUdpSocket(this);
    connect(timer,&QTimer::timeout,socket,[this]()->void
    {
        QString msg=ui->interval_edit->text();
        if(msg.isEmpty())
        {
            return;
        }
        quint16 port=5555;
        int length = socket->writeDatagram(msg.toLatin1(),msg.length(),QHostAddress::Broadcast,port);
        if(length== -1)
        {
            qDebug()<<"Error when sending datagram";
        }
    });
}

client::~client()
{
    delete ui;
}

void client::on_start_button_clicked()
{
    if(launched)
    {
        ui->start_button->setText("Stop");
        timer->start(ui->interval_edit->text().toInt());
        launched=false;
    }
    else
    {
        ui->start_button->setText("Start");
        timer->stop();
        launched=true;
    }
}
