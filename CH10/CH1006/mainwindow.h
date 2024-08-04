#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void start_request(QUrl url);

private slots:
    void reply_finished(QNetworkReply *reply);
    void http_finished();
    void http_ready_read();
    void update_progress(qint64 received,qint64 total);
    void on_download_button_clicked();
private:
    Ui::MainWindow *ui;
    QNetworkAccessManager *manager;
    QNetworkReply *reply;
    QFile file;
};
#endif // MAINWINDOW_H
