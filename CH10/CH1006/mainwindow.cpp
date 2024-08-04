#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QFileInfo>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    manager= new QNetworkAccessManager(this);
    connect(manager,&QNetworkAccessManager::finished,this,&MainWindow::reply_finished);
    manager->get(QNetworkRequest(QUrl("https://www.google.com/")));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start_request(QUrl url)
{
    reply = manager->get(QNetworkRequest(url));
    connect(reply,&QNetworkReply::readyRead,this,&MainWindow::http_ready_read);
    connect(reply,&QNetworkReply::downloadProgress,this,&MainWindow::update_progress);
    connect(reply,&QNetworkReply::finished,this,&MainWindow::http_finished);
}

void MainWindow::reply_finished(QNetworkReply *reply)
{
    QString all=reply->readAll();
    ui->text_browser->setText(all);
    reply->deleteLater();
}

void MainWindow::http_finished()
{
    file.flush();
    file.close();
    reply->deleteLater();
    reply=nullptr;
}

void MainWindow::http_ready_read()
{
    if(file.isOpen())
    {
        file.write(reply->readAll());
    }
}

void MainWindow::update_progress(qint64 received, qint64 total)
{
    ui->progress_bar->setMaximum(total);
    ui->progress_bar->setValue(received);
}

void MainWindow::on_download_button_clicked()
{
    QFileInfo info(QUrl(ui->url_edit->text()).path());
    file.setFileName(info.fileName());
    if(file.open(QIODevice::WriteOnly))
    {
        start_request(ui->url_edit->text());
        ui->progress_bar->setValue(0);
    }
    else
    {
        qDebug()<<"file open error";
    }
}
