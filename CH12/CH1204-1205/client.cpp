#include "client.h"
#include "ui_client.h"
#include <QMessageBox>

client::client(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::client)
{
    ui->setupUi(this);
    socket=new QTcpSocket(this);
    connect(socket,&QTcpSocket::readyRead,this,[this]()->void
    {
        QDataStream in(socket);
        qint64 time;
        if(socket->bytesAvailable()<sizeof(qint64))
        {
            return;
        }
        in >>time;
        ui->time_edit->setDateTime(QDateTime::fromSecsSinceEpoch(time));
        ui->message_label->setText("Get time successfully");
        ui->get_button->setEnabled(true);
    });

    connect(socket,&QTcpSocket::errorOccurred,this,[this](QAbstractSocket::SocketError error)->void
    {
        switch(error)
        {
        case QAbstractSocket::RemoteHostClosedError:
            break;
        case QAbstractSocket::HostNotFoundError:
            QMessageBox::information(this,"error","Host not found");
            break;
        case QAbstractSocket::ConnectionRefusedError:
            QMessageBox::information(this,"error","Connection refused");
            break;
        default:
            QMessageBox::information(this,"error",QString("Error : %1").arg(socket->errorString()));
            break;
        }
        ui->get_button->setEnabled(true);
    });
}

client::~client()
{
    delete ui;
}

void client::on_exit_button_clicked()
{
    close();
}


void client::on_get_button_clicked()
{
    ui->get_button->setEnabled(false);
    socket->abort();
    socket->connectToHost(ui->server_edit->text(),ui->port_edit->text().toUShort());
}

