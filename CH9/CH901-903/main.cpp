#include <QCoreApplication>
#include<QFile>
#include<QDebug>
#include<QDate>
#include<iostream>
void traditional_read_demo()
{
    QFile file(":/demo.txt");
    if(file.open(QIODevice::ReadOnly))
    {
        char buffer[2048];
        qint64 len=file.readLine(buffer,sizeof(buffer));
        if(len!=-1)
        {
            qDebug()<<buffer;
        }
        else
        {
            qDebug()<<file.errorString();
        }
    }
    file.close();
}

void textstream_demo()
{
    QFile file("demo.txt");
    if(file.open(QIODevice::WriteOnly|QIODevice::Truncate))
    {
        QTextStream out(&file);
        out<<"score:"<<qSetFieldWidth(10)<<Qt::left<<90<<Qt::endl;
    }
    file.close();
}

void datastream_demo()
{
    QFile file("demo.dat");
    if(file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        QDataStream out(&file);
        out<<QString("Alice");
        out<<QDate::fromString("1996/09/25","yyyy/MM/dd");
        out<<(qint32)21;
    }
    else
    {
        qDebug()<<file.errorString();
    }
    file.close();
    if(file.open(QIODevice::ReadOnly))
    {
        QDataStream in(&file);
        QString name;
        QDate birthday;
        qint32 age;
        in>>name>>birthday>>age;
        qDebug()<<name<<birthday<<age;
    }
    else
    {
        qDebug()<<file.errorString();
    }
    file.close();
}

int main(int argc, char *argv[])
{
    int num;
    std::cin>>num;
    switch(num)
    {
    case 1:
        traditional_read_demo();
        break;
    case 2:
        textstream_demo();
        break;
    case 3:
        datastream_demo();
        break;
    default:
        break;
    }
    return 0;
}
