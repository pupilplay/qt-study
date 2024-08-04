#include "server.h"
#include "ui_server.h"

server::server(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::server)
{
    ui->setupUi(this);
}

server::~server()
{
    delete ui;
}

void server::update_server(QString msg, int length)
{
    ui->msg_list->addItem(msg.left(length));
}

void server::on_init_button_clicked()
{
    m_server = new s_tcpserver(this,ui->port_edit->text().toUShort());
    connect(m_server,&s_tcpserver::update_server,this,&server::update_server);
    ui->init_button->setEnabled(false);
}


