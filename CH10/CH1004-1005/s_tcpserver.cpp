#include "s_tcpserver.h"

s_tcpserver::s_tcpserver(QObject *parent, quint16 port)
    :QTcpServer()
{
    listen(QHostAddress::Any,port);
}

void s_tcpserver::update_client(QString msg, int length)
{
    emit update_server(msg,length);
    foreach(s_tcpsocket *socket,sockets)
    {
        socket->write(msg.toLatin1(),length);
    }
}

void s_tcpserver::disconnected_server(qintptr socketDescriptor)
{
    for(int i=0;i<sockets.size();i++)
    {
        if(sockets[i]->socketDescriptor()==socketDescriptor)
        {
            sockets[i]->deleteLater();
            sockets.removeAt(i);
            return;
        }
    }
}



void s_tcpserver::incomingConnection(qintptr socketDescriptor)
{
    s_tcpsocket *socket=new s_tcpsocket(this);
    connect(socket,&s_tcpsocket::update_client,this,&s_tcpserver::update_client);
    connect(socket,&s_tcpsocket::my_disconnected,this,&s_tcpserver::disconnected_server);
    socket->setSocketDescriptor(socketDescriptor);
    sockets.append(socket);
}
