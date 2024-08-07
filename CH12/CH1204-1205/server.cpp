#include "server.h"
#include "ui_server.h"
#include <QMessageBox>

server::server(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::server)
{
    ui->setupUi(this);
    count=0;
    m_server=new time_server(this);
    if(m_server->listen())
    {
        ui->message_label->setText(QString("Port: %1").arg(m_server->serverPort()));
    }
    else
    {
        QMessageBox::critical(this,"Server","Failed to initialize the server");
        close();
        return;
    }
}

server::~server()
{
    delete ui;
}

void server::update()
{
    ui->message_label->setText(QString("Requested for %1 times").arg(++count));
}

void server::on_exit_button_clicked()
{
    close();
}

