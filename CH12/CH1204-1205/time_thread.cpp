#include "time_thread.h"
#include <QDateTime>

time_thread::time_thread(qintptr socketDescriptor, QObject *parent)
    :QThread(parent),sd(socketDescriptor)
{
    ;
}

void time_thread::run()
{
    QTcpSocket socket;
    if(socket.setSocketDescriptor(sd))
    {
        QByteArray block;
        QDataStream out(&block,QIODevice::WriteOnly);
        qint64 time = QDateTime::currentDateTime().toSecsSinceEpoch();
        out<<time;
        socket.write(block);
        socket.disconnectFromHost();
        socket.waitForDisconnected(-1);
    }
    else
    {
        emit error(socket.error());
        return;
    }
}
