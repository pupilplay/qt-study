#include "mainwindow.h"

#include <QApplication>
#include<QSplashScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen loading(QPixmap(":/image.png"));
    loading.show();
    MainWindow w;
    w.show();
    loading.finish(&w);
    return a.exec();
}
