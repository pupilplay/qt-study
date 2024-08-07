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
    void on_exit_button_clicked();

    void on_get_button_clicked();

private:

    Ui::client *ui;
    QTcpSocket *socket;
};

#endif // CLIENT_H
