#include "widget.h"
#include "./ui_widget.h"
#include<QtNetwork/QHostinfo>
#include<QtNetwork/QNetworkInterface>
#include<QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_refres_button_clicked()
{
    QString host=QHostInfo::localHostName();
    ui->host_edit->setText(host);
    QHostInfo host_info=QHostInfo::fromName(host);
    QList<QHostAddress> addresses_list=host_info.addresses();
    if(!addresses_list.isEmpty())
    {
        QString addresses;
        foreach(QHostAddress address,addresses_list)
        {
            addresses.append(address.toString());
            addresses.append('\n');
        }
        ui->ip_edit->setText(addresses);
    }
    QString detail;
    QList<QNetworkInterface> interfaces_list=QNetworkInterface::allInterfaces();
    foreach(QNetworkInterface interface,interfaces_list)
    {
        detail+="Device:"+interface.name()+'\n';
        detail+="Hardware address:"+interface.hardwareAddress()+'\n';
        QList<QNetworkAddressEntry> entries=interface.addressEntries();
        foreach(QNetworkAddressEntry entry,entries)
        {
            detail+='\t';
            detail+="IP address:"+entry.ip().toString()+'\n';
            detail+='\t';
            detail+="Net mask:"+entry.netmask().toString()+'\n';
            detail+='\t';
            detail+="Boradcast:"+entry.broadcast().toString()+'\n';
        }
    }
    QMessageBox::information(this,"Detail",detail);
}
