#include "server.h"
#include "time_thread.h"



time_server::time_server(QObject *parent)
    :QTcpServer(parent)
{
    ;
}

void time_server::incomingConnection(qintptr socketDescriptor)
{
    time_thread *thread=new time_thread(socketDescriptor,this);
    connect(thread,&QThread::finished,(server*)parent(),&server::update);
    connect(thread,&QThread::finished,thread,&QObject::deleteLater);
    thread->start();
}
