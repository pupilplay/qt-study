#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug()<<qAbs<int>(-123);
    qDebug()<<qAbs<double>(12.34);
    qDebug()<<qMax<QString>("hello","world");
    qDebug()<<qRound(4.4999999999999999);
    qDebug()<<qRound(4.49);
    qint64 num1=10;
    qint64 num2=20;
    qDebug()<<"num1="<<num1<<" num2="<<num2;
    qSwap(num1,num2);
    qDebug()<<"num1="<<num1<<" num2="<<num2;
    return a.exec();
}
