#include"digit_clock.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    digit_clock clock;
    clock.show();
    return a.exec();
}
