#include "connect_dialog.h"
#include "ui_connect_dialog.h"
#include <QSqlDatabase>
#include <QSqlQuery>

connect_dialog::connect_dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::connect_dialog)
{
    ui->setupUi(this);
    ui->driver_edit->addItems(QSqlDatabase::drivers());
    ui->status_label->setText("Ready to connect");
}

connect_dialog::~connect_dialog()
{
    delete ui;
}

QString connect_dialog::driver() const
{
    return ui->driver_edit->currentText();
}

QString connect_dialog::database() const
{
    return ui->database_edit->text();
}

QString connect_dialog::username() const
{
    return ui->username_edit->text();
}

QString connect_dialog::password() const
{
    return ui->password_edit->text();
}

QString connect_dialog::host() const
{
    return ui->host_edit->text();
}

quint16 connect_dialog::port() const
{
    return ui->port_edit->value();
}

QSqlError connect_dialog::add_connection(const QString &driver,
                                         const QString &database, const QString &host,
                                         const QString &user, const QString &password, quint16 port)
{
    QSqlError error;
    QSqlDatabase db = QSqlDatabase::addDatabase(driver);
    db.setDatabaseName(database);
    db.setHostName(host);
    db.setPort(port);
    if(db.open(user,password))
    {
        return error;
    }
    else
    {
        return db.lastError();
    }
}

void connect_dialog::add_sqlite_connection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("db");
    if(db.open())
    {
        ui->status_label->setText("Sqlite database is created successfully");
    }
    else
    {
        ui->status_label->setText(db.lastError().text());
    }
}

void connect_dialog::database_init()
{
    QSqlQuery query;
    query.exec("create table manufactories("
               "id int primary key,"
               "name varchar(40),"
               "address varchar(40) )");
    query.exec("create table cars("
               "id int primary key,"
               "name varchar(50),"
               "manufactory_id int,"
               "year int,"
               "foreign key(manufactory_id) references manufactories )");

}

void connect_dialog::on_driver_edit_currentTextChanged(const QString &text)
{
    if(text=="QSQLITE")
    {
        ui->database_edit->setEnabled(false);
        ui->username_edit->setEnabled(false);
        ui->password_edit->setEnabled(false);
        ui->host_edit->setEnabled(false);
        ui->port_edit->setEnabled(false);
    }
    else
    {
        ui->database_edit->setEnabled(true);
        ui->username_edit->setEnabled(true);
        ui->password_edit->setEnabled(true);
        ui->host_edit->setEnabled(true);
        ui->port_edit->setEnabled(true);
    }
}


void connect_dialog::on_ok_button_clicked()
{
    if(ui->driver_edit->currentText().isEmpty())
    {
        ui->status_label->setText("Select a driver first");
        ui->driver_edit->setFocus();
    }
    else if(ui->driver_edit->currentText()=="QSQLITE")
    {
        add_sqlite_connection();
        database_init();
        accept();
    }
    else
    {
        QSqlError error=add_connection(ui->driver_edit->currentText(),
        ui->database_edit->text(),ui->host_edit->text(),
        ui->username_edit->text(),ui->password_edit->text(),ui->port_edit->value());
        if(error.type()!=QSqlError::NoError)
        {
            ui->status_label->setText(error.text());
        }
        else
        {
            ui->status_label->setText("Sqlite database is created successfully");
        }
        accept();
    }
}


void connect_dialog::on_cancel_button_clicked()
{
    reject();
}

