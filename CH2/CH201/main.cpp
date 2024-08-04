#include <QCoreApplication>
#include<QDebug>
int main(int argc, char *argv[])
{
    QList<int> list;
    list<<1<<2<<3;
    for(QListIterator<int> it(list);it.hasNext();)
    {
        qDebug()<<it.next();
    }

    QListIterator<int> reverse_it(list);
    reverse_it.toBack();
    for(;reverse_it.hasPrevious();reverse_it.previous())
    {
        qDebug()<<reverse_it.peekPrevious();
    }
    return 0;
}
