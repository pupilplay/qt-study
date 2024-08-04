#ifndef SERVER_H
#define SERVER_H

#include <QDialog>
#include "s_tcpserver.h"

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
public slots:
    void update_server(QString msg,int length);
private slots:
    void on_init_button_clicked();

private:
    Ui::server *ui;
    quint16 port;
    s_tcpserver *m_server;
};

#endif // SERVER_H
