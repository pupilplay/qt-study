#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include<QtNetwork/QUdpSocket>

namespace Ui
{
class server;
}

class server : public QDialog
{
    Q_OBJECT

public:
    explicit server(QWidget *parent = nullptr);
    ~server();

private:
    Ui::server *ui;
    QUdpSocket *socket;
};

#endif // SERVER_H
