#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QList<int> list{1,2,3,4,5,6,7,8,9};
    for(QMutableListIterator<int>it(list);it.hasNext();it.next())
    {
        if(it.peekNext()%2==0)
        {
            it.remove();
        }
        else
        {
            it.insert(it.peekNext()*2);
        }
        qDebug()<<list;
    }
    return 0;
}
