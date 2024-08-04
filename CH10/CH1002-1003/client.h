#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QTimer>
#include<QtNetwork/QUdpSocket>

namespace Ui
{
class client;
}

class client : public QDialog
{
    Q_OBJECT

public:
    explicit client(QWidget *parent = nullptr);
    ~client();

private slots:
    void on_start_button_clicked();

private:
    Ui::client *ui;
    bool launched;
    QUdpSocket *socket;
    QTimer *timer;
};

#endif // CLIENT_H
