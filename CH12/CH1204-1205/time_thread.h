#ifndef TIME_THREAD_H
#define TIME_THREAD_H

#include <QThread>
#include <QTcpSocket>

class time_thread : public QThread
{
    Q_OBJECT
public:
    time_thread(qintptr socketDescriptor,QObject *parent = nullptr);
protected:
    void run() override;
signals:
    void error(QTcpSocket::SocketError socket_error);
private:
    qintptr sd;
};

#endif // TIME_THREAD_H
