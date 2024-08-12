#ifndef CONNECT_DIALOG_H
#define CONNECT_DIALOG_H

#include <QDialog>
#include <QSqlError>

namespace Ui
{
class connect_dialog;
}

class connect_dialog : public QDialog
{
    Q_OBJECT

public:
    explicit connect_dialog(QWidget *parent = nullptr);
    ~connect_dialog();
    QString driver() const;
    QString database() const;
    QString username() const;
    QString password() const;
    QString host() const;
    quint16 port() const;

    QSqlError add_connection(const QString &driver,
                             const QString &database,const QString &host,
                             const QString &user,const QString &password,quint16 port);
    void add_sqlite_connection();
    void database_init();
private slots:
    void on_driver_edit_currentTextChanged(const QString &text);

    void on_ok_button_clicked();

    void on_cancel_button_clicked();

private:
    Ui::connect_dialog *ui;
};

#endif // CONNECT_DIALOG_H
