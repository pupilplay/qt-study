#include "my_model.h"
#include <QTableView>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    my_model model;
    QTableView view;
    view.setModel(&model);
    view.resize(400,400);
    view.show();
    return a.exec();
}
