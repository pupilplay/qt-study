#ifndef S_TCPSOCKET_H
#define S_TCPSOCKET_H

#include <QTcpSocket>

class s_tcpsocket : public QTcpSocket
{
    Q_OBJECT
public:
    s_tcpsocket(QObject *parent=nullptr);
signals:
    void update_client(QString msg,int length);
    void my_disconnected(qintptr socketDescriptor);
protected slots:
    void data_received();
    void disconnected_client();
};

#endif // S_TCPSOCKET_H
