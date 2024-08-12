#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSqlRecord>
#include "edit_dialog.h"

MainWindow::MainWindow(const QString &manufactory_table, const QString &car_table, QFile *car_details, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    file=car_details;
    car_model = new QSqlRelationalTableModel(this);
    car_model->setTable(car_table);
    car_model->setRelation(2,QSqlRelation(manufactory_table,"id","name"));
    car_model->select();
    manufactory_model= new QSqlTableModel(this);
    manufactory_model->setTable(manufactory_table);
    manufactory_model->select();
    ui->manufactory_view->setModel(manufactory_model);
    ui->car_view->setModel(car_model);
    connect(ui->car_view,&QTableView::clicked,this,&MainWindow::update_car_detail);
    connect(ui->car_view,&QTableView::activated,this,&MainWindow::update_car_detail);
    connect(ui->manufactory_view,&QTableView::clicked,this,&MainWindow::update_manufactory);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::read_car_data()
{
    if(!file->open(QIODevice::ReadOnly) || !data.setContent(file))
    {
        file->close();
    }
}

QModelIndex MainWindow::manufactory_index(const QString &manufactory)
{
    for(int i=0;i<manufactory_model->rowCount();i++)
    {
        QSqlRecord record = manufactory_model->record(i);
        if(record.value("name") == manufactory)
        {
            return manufactory_model->index(i,1);
        }
    }
    return QModelIndex();
}

void MainWindow::update_detail_list(QDomNode car)
{
    ui->detail_list->clear();
    QDomNodeList list = car.childNodes();
    QDomNode node;
    QString num;
    for(int i=0;i<list.size();i++)
    {
        node = list.item(i);
        num=node.toElement().attribute("number");
        QString text=num+":"+node.toElement().text();
        new QListWidgetItem(text,ui->detail_list);
    }

}

void MainWindow::update_car_detail(const QModelIndex &index)
{
    read_car_data();
    QSqlRecord record = car_model->record(index.row());
    //与数据库方面对应，可能出错，记得检查
    QString manufactory = record.value("manufactory").toString();
    QString name=record.value("name").toString();
    QString year=record.value("year").toString();
    QString id=record.value("id").toString();
    update_manufactory_profile(manufactory_index(name));
    ui->title_label->setText(QString("Brand: %1 (%2)").arg(name).arg(year));
    QDomNodeList cars=data.elementsByTagName("car");
    for(int i=0;i<cars.size();i++)
    {
        QDomNode car =cars.item(i);
        if(car.toElement().attribute("id") == id)
        {
            update_detail_list(car.toElement());
            break;
        }
    }
    file->close();
}

void MainWindow::update_manufactory_profile(const QModelIndex &index)
{
    QSqlRecord record = manufactory_model->record(index.row());
    QString name = record.value("name").toString();
    int count = car_model->rowCount();
    ui->profile_label->setText(QString("Manufactory: %1\nProduct count: %2").arg(name).arg(count));
}

void MainWindow::on_add_action_triggered()
{
    edit_dialog dialog(car_model,manufactory_model,data,file);
    int accepted = dialog.exec();
    if(accepted==1)
    {
        int last_row=car_model->rowCount()-1;
        ui->car_view->selectRow(last_row);
        ui->car_view->scrollToBottom();
        update_car_detail(car_model->index(last_row,0));
    }
}


void MainWindow::on_remove_action_triggered()
{
    return;
}

void MainWindow::on_exit_action_triggered()
{
    close();
}

void MainWindow::update_manufactory(const QModelIndex &index)
{
    QSqlRecord record = manufactory_model->record(index.row());
    QString id = record.value("id").toString();
    car_model->setFilter("id = '"+ id+"'");
    update_manufactory_profile(index);
}
