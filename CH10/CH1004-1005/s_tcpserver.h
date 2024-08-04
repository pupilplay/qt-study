#ifndef S_TCPSERVER_H
#define S_TCPSERVER_H

#include <QTcpServer>
#include"s_tcpsocket.h"

class s_tcpserver : public QTcpServer
{
    Q_OBJECT
public:
    s_tcpserver(QObject *parent = nullptr,quint16 port=9999);
signals:
    void update_server(QString msg,int length);
public slots:
    void update_client(QString msg,int length);
    void disconnected_server(qintptr socketDescriptor);
protected:
    void incomingConnection(qintptr socketDescriptor) override;
private:
    QList<s_tcpsocket*> sockets;
};

#endif // S_TCPSERVER_H
