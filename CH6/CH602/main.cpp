#include "painter_demo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    painter_demo w;
    w.show();
    return a.exec();
}
