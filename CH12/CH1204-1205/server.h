#ifndef SERVER_H
#define SERVER_H

#include <QDialog>

namespace Ui
{
class server;
}

class server;
class time_server;
class server : public QDialog
{
    Q_OBJECT

public:
    explicit server(QWidget *parent = nullptr);
    ~server();
public slots:
    void update();

private slots:
    void on_exit_button_clicked();

private:
    Ui::server *ui;
    int count;
    time_server *m_server;
};

#endif // SERVER_H

#ifndef TIME_SERVER_H
#define TIME_SERVER_H

#include <QTcpServer>
class server;

class time_server : public QTcpServer
{
    Q_OBJECT
public:
    time_server(QObject *parent = nullptr);
protected:
    void incomingConnection(qintptr socketDescriptor) override;
};

#endif // TIME_SERVER_H
