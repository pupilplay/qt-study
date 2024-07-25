#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    model=new QStandardItemModel(4,4,this);
    model->setHeaderData(0,Qt::Horizontal,"Department");
    model->setHeaderData(1,Qt::Horizontal,"Male");
    model->setHeaderData(2,Qt::Horizontal,"Female");
    model->setHeaderData(3,Qt::Horizontal,"Retired");
    selection=new QItemSelectionModel(model,model);
    splitter= new QSplitter(Qt::Vertical);
    histogram=new histogram_view(splitter);
    histogram->setModel(model);
    histogram->setSelectionModel(selection);
    table=new QTableView(splitter);
    table->setModel(model);
    table->setSelectionModel(selection);
    connect(selection,SIGNAL(selectionChanged(QItemSelection,QItemSelection)),table,SLOT(selectionChanged(QItemSelection,QItemSelection)));
    connect(selection,SIGNAL(selectionChanged(QItemSelection,QItemSelection)),histogram,SLOT(selectionChanged(QItemSelection,QItemSelection)));
    setCentralWidget(splitter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_open_action_triggered()
{
    QString file_name = QFileDialog::getOpenFileName(this,"Open","./","(*.txt)");
    if(!file_name.isEmpty())
    {
        QFile file(file_name);
        if(file.open(QFile::ReadOnly | QFile::Text))
        {
            QTextStream stream(&file);
            QString line;
            model->removeRows(0,model->rowCount(QModelIndex()),QModelIndex());
            int row=0;
            line = stream.readLine();
            while(!line.isEmpty())
            {
                model->insertRows(row,1,QModelIndex());
                QStringList pieces=line.split(',',Qt::SkipEmptyParts);
                model->setData(model->index(row,0,QModelIndex()),pieces.value(0));
                model->setData(model->index(row,1,QModelIndex()),pieces.value(1));
                model->setData(model->index(row,2,QModelIndex()),pieces.value(2));
                model->setData(model->index(row,3,QModelIndex()),pieces.value(3));
                line=stream.readLine();
                row++;
            }
        }
        file.close();
    }
}
