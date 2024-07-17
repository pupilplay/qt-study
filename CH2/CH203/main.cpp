#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QList<int>list{1};
    list.insert(list.end(),2);
    list.push_back(3);
    list.append(4);
    list.emplace_back(5);
    list.prepend(0);
    list.emplaceFront(-1);
    //{-1, 0, 1, 2, 3, 4, 5}
    qDebug()<<list;
    for(QList<int>::iterator it=list.begin();it!=list.end();it++)
    {
        qDebug()<<*it;
        *it=(*it)*10;
    }
    for(QList<int>::const_iterator const_it=list.constBegin();const_it!=list.constEnd();const_it++)
    {
        qDebug()<<*const_it;
    }
    for(auto num:list)
    {
        qDebug()<<num;
    }
    for(auto it=list.rbegin();it!=list.rend();it++)
    {
        qDebug()<<*it;
    }
    for(int i=list.size()-1;i>=0;i--)
    {
        qDebug()<<list[i];
    }
    return a.exec();
}
