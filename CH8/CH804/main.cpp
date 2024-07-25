#include<QTableView>
#include<QStandardItemModel>
#include<QFile>
#include<QTextStream>
#include <QApplication>
#include<QFileDialog>
#include "date_delegate.h"
#include "combo_delegate.h"
#include "spin_delegate.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QStandardItemModel model(4,4);
    QTableView view;
    model.setHeaderData(0,Qt::Horizontal,"Name");
    model.setHeaderData(1,Qt::Horizontal,"Birthday");
    model.setHeaderData(2,Qt::Horizontal,"Job");
    model.setHeaderData(3,Qt::Horizontal,"Income");
    QString file_name=QFileDialog::getOpenFileName();
    QFile file(file_name);
    if(file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        QString line;
        model.removeRows(0,model.rowCount(QModelIndex()),QModelIndex());
        int row=0;
        line=stream.readLine();
        while(!line.isEmpty())
        {
            model.insertRows(row,1,QModelIndex());
            QStringList pieces=line.split(',',Qt::SkipEmptyParts);
            model.setData(model.index(row,0,QModelIndex()),pieces.value(0));
            model.setData(model.index(row,1,QModelIndex()),pieces.value(1));
            model.setData(model.index(row,2,QModelIndex()),pieces.value(2));
            model.setData(model.index(row,3,QModelIndex()),pieces.value(3));
            line =stream.readLine();
            row++;
        }
        file.close();
    }
    else
    {
        file.close();
        return 0;
    }
    view.setModel(&model);
    date_delegate my_date_delegate;
    combo_delegate my_combo_delegate;
    spin_delegate my_spin_delegate;
    view.setItemDelegateForColumn(1,&my_date_delegate);
    view.setItemDelegateForColumn(2,&my_combo_delegate);
    view.setItemDelegateForColumn(3,&my_spin_delegate);
    view.show();
    view.resize(500,300);
    return a.exec();
}
