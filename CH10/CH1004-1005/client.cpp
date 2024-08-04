#include "client.h"
#include "ui_client.h"
#include<QMessageBox>

client::client(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::client)
{
    ui->setupUi(this);
    status=false;
    ui->send_button->setEnabled(false);
}

client::~client()
{
    delete ui;
}

void client::on_connect_button_clicked()
{
    if(status)
    {
        QString msg=ui->username_edit->text()+" leave chat room";
        socket->write(msg.toLatin1(),msg.length());
        socket->disconnectFromHost();
        status=false;
    }
    else
    {
        QString ip = ui->address_edit->text();
        QHostAddress address;
        if(!address.setAddress(ip))
        {
            QMessageBox::information(this,"Error","The address is invalid");
            return;
        }
        if(ui->username_edit->text().isEmpty())
        {
            QMessageBox::information(this,"Error","The username is invalid");
            return;
        }
        socket=new QTcpSocket(this);
        connect(socket,&QTcpSocket::connected,this,[this]()->void
        {
            ui->send_button->setEnabled(true);
            ui->connect_button->setText("Disconnect");
            QString msg=ui->username_edit->text()+" enter chat room";
            socket->write(msg.toLatin1(),msg.length());
        });
        connect(socket,&QTcpSocket::disconnected,this,[this]()->void
        {
            ui->send_button->setEnabled(false);
            ui->connect_button->setText("Connect");
        });
        connect(socket,&QTcpSocket::readyRead,this,[this]()->void
        {
            while(socket->bytesAvailable()>0)
            {
                QByteArray datagram;
                datagram.resize(socket->bytesAvailable());
                socket->read(datagram.data(),datagram.size());
                QString msg=datagram.data();
                ui->msg_list->addItem(msg.left(datagram.size()));
            }
        });
        socket->connectToHost(address,ui->port_edit->text().toUShort());
        status=true;
    }
}
void client::on_send_button_clicked()
{
    if(ui->msg_edit->text().isEmpty())
    {
        return;
    }
    QString msg=ui->msg_edit->text();
    socket->write(msg.toLatin1(),msg.length());
    ui->msg_edit->clear();
}

