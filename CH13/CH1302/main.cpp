#include "mainwindow.h"
#include "connect_dialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    connect_dialog dialog;
    if(dialog.exec() != QDialog::Accepted)
    {
        return -1;
    }
    QFile *car_detail=new QFile("data.xml");
    MainWindow w("manufactories","cars",car_detail);
    w.show();
    a.exec();
    car_detail->deleteLater();
    return 0;
}
