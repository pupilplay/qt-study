#include "s_tcpsocket.h"

s_tcpsocket::s_tcpsocket(QObject *parent)
    :QTcpSocket(parent)
{
    connect(this,&s_tcpsocket::readyRead,this,&s_tcpsocket::data_received);
    connect(this,&s_tcpsocket::disconnected,this,&s_tcpsocket::disconnected_client);
}

void s_tcpsocket::data_received()
{
    QString msg;
    int length=0;
    while(bytesAvailable()>0)
    {
        char buf[1024];
        length+=read(buf,1024);
        msg.append(buf);
    }
    emit update_client(msg,length);
}

void s_tcpsocket::disconnected_client()
{
    emit my_disconnected(this->socketDescriptor());
}
