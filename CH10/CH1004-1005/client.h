#ifndef CLIENT_H
#define CLIENT_H

#include <QDialog>
#include <QTcpSocket>

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
    void on_connect_button_clicked();

    void on_send_button_clicked();

private:
    Ui::client *ui;
    bool status;
    QTcpSocket *socket;
};

#endif // CLIENT_H
