#include "server.h"
#include "ui_server.h"

server::server(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::server)
{
    ui->setupUi(this);
    socket= new QUdpSocket(this);
    socket->bind(5555);
    connect(socket,&QUdpSocket::readyRead,this,[this]()->void
    {
        while(socket->hasPendingDatagrams())
        {
            QByteArray datagram;
            datagram.resize(socket->pendingDatagramSize());
            socket->readDatagram(datagram.data(),datagram.size());
            ui->text_edit->insertPlainText(QString(datagram));
        }
    });
}

server::~server()
{
    delete ui;
}
