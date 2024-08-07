#include "event_filter_demo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    event_filter_demo w;
    w.show();
    return a.exec();
}
