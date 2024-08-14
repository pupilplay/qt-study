#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QSqlRecord>
#include "edit_dialog.h"
#include <QMessageBox>

MainWindow::MainWindow(const QString &manufactory_table, const QString &car_table, QFile *car_details, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    file=car_details;
    car_model = new QSqlRelationalTableModel(this);
    car_model->setTable(car_table);
    //car_model->setRelation(2,QSqlRelation(manufactory_table,"id","name"));
    manufactory_model= new QSqlTableModel(this);
    manufactory_model->setTable(manufactory_table);
    ui->manufactory_view->setModel(manufactory_model);
    ui->car_view->setModel(car_model);
    manufactory_model->select();
    car_model->select();
    connect(ui->car_view,&QTableView::clicked,this,&MainWindow::update_car_detail);
    connect(ui->car_view,&QTableView::activated,this,&MainWindow::update_car_detail);
    connect(ui->manufactory_view,&QTableView::clicked,this,&MainWindow::update_manufactory);
}

MainWindow::~MainWindow()
{
    delete ui;
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

void MainWindow::remove_car_from_file(int id)
{
    QDomNodeList cars = data.elementsByTagName("car");
    for(int i=0;i<cars.size();i++)
    {
        QDomNode node = cars.item(i);
        if(node.toElement().attribute("id").toInt() == id)
        {
            data.elementsByTagName("archive").item(0).removeChild(node);
            break;
        }
    }
}

void MainWindow::remove_car_from_database(const QModelIndex &index)
{
    car_model->removeRow(index.row());
}

void MainWindow::decrease_car_count(const QModelIndex &index)
{
    int row = index.row();
    int count = car_model->rowCount();
    if(count == 0)
    {
        manufactory_model->removeRow(row);
    }
}

void MainWindow::update_car_detail(const QModelIndex &index)
{
    if(!file->open(QIODevice::ReadOnly) || !data.setContent(file))
    {
        file->close();
        return;
    }
    QSqlRecord record = car_model->record(index.row());
    QString manufactory = record.value(2).toString();
    QString id=record.value("id").toString();
    QString name=record.value("name").toString();
    QString year=record.value("year").toString();
    update_manufactory_profile(manufactory_index(manufactory));
    ui->title_label->setText(QString("Brand: %1 (%2)").arg(name,year));
    ui->profile_label->setText(QString("Manufactory: %1").arg(manufactory));
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
    ui->title_label->setText("");
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
    QModelIndexList selection = ui->car_view->selectionModel()->selectedRows(0);
    if(!selection.isEmpty())
    {
        QModelIndex id_index=selection.at(0);
        int id=id_index.data().toInt();
        QString name = id_index.sibling(id_index.row(),1).data().toString();
        QString manufactory = id_index.sibling(id_index.row(),2).data().toString();
        QMessageBox::StandardButton button;
        button = QMessageBox::question(this,"Remove",QString("Confirm to remove %1").arg(name));
        if(button == QMessageBox::Yes)
        {
            remove_car_from_file(id);
            remove_car_from_database(id_index);
            decrease_car_count(manufactory_index(manufactory));
        }
    }
}

void MainWindow::on_exit_action_triggered()
{
    close();
}

void MainWindow::update_manufactory(const QModelIndex &index)
{
    QSqlRecord record = manufactory_model->record(index.row());
    QString id = record.value("id").toString();
    car_model->setFilter("manufactory_id = '"+ id+"'");
    update_manufactory_profile(index);
}
