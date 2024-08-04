#include <QCoreApplication>
#include<QDir>

quint64 my_read(QString path)
{
    QDir dir(path);
    quint64 size =0;
    QFileInfo file_info;
    foreach(file_info,dir.entryInfoList(QDir::Files))
    {
        size += file_info.size();
    }
    char units[]={'B','K','M','G'};
    int unit=0;
    quint64 current_size=size;
    while(current_size>1024)
    {
        current_size>>=10;
        unit++;
    }
    qDebug()<<current_size<<units[unit]<<'\t'<<qPrintable(path)<<Qt::endl;
    return size;
}
int main(int argc, char *argv[])
{
    QString path;
    if(argc==1)
    {
        path=QDir::currentPath();
    }
    else
    {
        path = QString(argv[1]);
    }
    qDebug()<<path<<Qt::endl;
    my_read(path);
    return 0;
}
