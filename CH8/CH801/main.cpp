#include <QApplication>
#include<QSplitter>
#include<QAbstractItemModel>
#include<QAbstractItemView>
#include<QItemSelectionModel>
#include<QFileSystemModel>
#include<QTreeView>
#include<QListView>
#include<QTableView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QFileSystemModel model;
    model.setRootPath(QDir::currentPath());
    QTreeView *tree_view=new QTreeView();
    QListView *list_view=new QListView();
    QTableView *table_view=new QTableView();
    tree_view->setModel(&model);
    list_view->setModel(&model);
    table_view->setModel(&model);
    tree_view->setSelectionMode(QAbstractItemView::MultiSelection);
    list_view->setSelectionModel(tree_view->selectionModel());
    table_view->setSelectionModel(tree_view->selectionModel());
    QObject::connect(tree_view,&QTreeView::doubleClicked,list_view,&QListView::setRootIndex);
    QObject::connect(tree_view,&QTreeView::doubleClicked,table_view,&QTableView::setRootIndex);
    QSplitter *splitter = new QSplitter();
    splitter->addWidget(tree_view);
    splitter->addWidget(list_view);
    splitter->addWidget(table_view);
    splitter->show();
    a.exec();
    delete splitter;
    return 0;
}
