#include "edit_dialog.h"
#include "ui_edit_dialog.h"
#include <QMessageBox>
#include <QSqlRecord>
#include <QSqlField>
#include <QDate>
#include <QSqlError>

int unique_car_id=0;
int unique_manufactory_id=0;

edit_dialog::edit_dialog(QSqlRelationalTableModel *car_model,
                         QSqlTableModel *manufactory_model,QDomDocument data,
                         QFile *file,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::edit_dialog)
    ,file(file),data(data),car_model(car_model),manufactory_model(manufactory_model)
{
    ui->setupUi(this);
}

edit_dialog::~edit_dialog()
{
    delete ui;
}

void edit_dialog::on_submit_button_clicked()
{
    QString manufactory = ui->manufactory_edit->text();
    QString address = ui->address_edit->text();
    QString name = ui->brand_edit->text();
    if(manufactory.isEmpty() || address.isEmpty()|| name.isEmpty())
    {
        QMessageBox::information(this,"Edit","Invalid arguments");
    }
    else
    {
        int manufactory_id=get_manufactory_id(manufactory);
        if(manufactory_id==-1)
        {
            manufactory_id = new_manufactory(manufactory,address);
        }
        int car_id=new_car(name,manufactory_id);
        QStringList details;
        details=ui->detail_edit->text().split(';',Qt::SkipEmptyParts);
        write_detail(car_id,details);
        accept();
    }
}

int edit_dialog::new_manufactory(const QString &manufactory, const QString &address)
{
    QSqlRecord record;
    QSqlField f1("id",QMetaType(QMetaType::Int));
    QSqlField f2("name",QMetaType(QMetaType::QString));
    QSqlField f3("address",QMetaType(QMetaType::QString));
    f1.setValue(QVariant(unique_manufactory_id));
    f2.setValue(QVariant(manufactory));
    f3.setValue(QVariant(address));
    record.append(f1);
    record.append(f2);
    record.append(f3);
    manufactory_model->insertRecord(-1,record);
    return unique_manufactory_id++;
}

int edit_dialog::new_car(const QString &name, int manufactory_id)
{
    QSqlRecord record;
    QSqlField f1("id",QMetaType(QMetaType::Int));
    QSqlField f2("name",QMetaType(QMetaType::QString));
    QSqlField f3("manufactory_id",QMetaType(QMetaType::Int));
    QSqlField f4("year",QMetaType(QMetaType::Int));
    f1.setValue(QVariant(unique_car_id));
    f2.setValue(QVariant(name));
    f3.setValue(QVariant(manufactory_id));
    f4.setValue(QVariant(ui->year_edit->value()));
    record.append(f1);
    record.append(f2);
    record.append(f3);
    record.append(f4);
    qDebug()<<car_model->insertRecord(-1,record);
    qDebug()<<car_model->lastError().text();
    return unique_car_id++;
}

int edit_dialog::get_manufactory_id(const QString &manufactory)
{
    for(int i=0;i<manufactory_model->rowCount();i++)
    {
        QSqlRecord record = manufactory_model->record(i);
        if(record.value("name")==manufactory)
        {
            return record.value("id").toInt();
        }
    }
    return -1;
}

void edit_dialog::write_detail(int car_id, QStringList details)
{
    if(!file->open(QIODevice::ReadOnly) || !data.setContent(file))
    {
        file->close();
        return;
    }
    QDomElement node = data.createElement("car");
    node.setAttribute("id",car_id);
    for(int i=0;i<details.size();i++)
    {
        QString num=QString::number(i+1);
        QDomText text_node=data.createTextNode(details[i]);
        QDomElement detail_node=data.createElement("detail");
        detail_node.setAttribute("number",num);
        detail_node.appendChild(text_node);
        node.appendChild(detail_node);
    }
    QDomNodeList archive = data.elementsByTagName("archive");
    archive.item(0).appendChild(node);
    file->close();
    if(!file->open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        file->close();
        return;
    }
    QTextStream stream(file);
    archive.item(0).save(stream,4);
    file->close();
}


void edit_dialog::on_rever_button_clicked()
{
    ui->manufactory_edit->clear();
    ui->address_edit->clear();
    ui->brand_edit->clear();
    ui->year_edit->setValue(QDate::currentDate().year());
    ui->detail_edit->clear();
}


void edit_dialog::on_cancel_button_clicked()
{
    reject();
}

