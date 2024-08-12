#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRecord>
#include <QtSql/QSqlError>
#include <QElapsedTimer>
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QSqlDatabase db=QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName("my_database.db");
    db.setUserName("qt_pupil");
    db.setPassword("123456");
    db.open();

    QSqlQuery query;
    bool ok = query.exec("create table automobile"
                         "(id int primary key,"
                         "attribute varchar,"
                         "type varchar,"
                         "kind varchar,"
                         "nation int,"
                         "carnumber int,"
                         "elevator int,"
                         "distance int,"
                         "oil int,"
                         "temperature int"
                         ")");
    if(ok)
    {
        qDebug()<<"table is created successfully";
    }
    else
    {
        qDebug()<<"Failed to create the table";
    }
    query.exec("select * from automobile");
    QSqlRecord rec = query.record();
    qDebug() << "automobile fields : " << rec.count();
    QElapsedTimer t;
    t.start();
    query.prepare("insert into automobile values(?,?,?,?,?,?,?,?,?,?)");
    long records=100;
    for(int i=0;i<records;i++)
    {
        query.bindValue(0,i);
        query.bindValue(1,"Four Wheel");
        query.bindValue(2,"Car");
        query.bindValue(3,"XXX");
        query.bindValue(4,rand()%100);
        query.bindValue(5,rand()%10000);
        query.bindValue(6,rand()%300);
        query.bindValue(7,rand()%200000);
        query.bindValue(8,rand()%52);
        query.bindValue(9,rand()%100);
        ok=query.exec();
        if(!ok)
        {
            QSqlError error=query.lastError();
            qDebug()<<error.driverText();
        }
    }
    qDebug()<<QString("%1 records inserted, time cost: %2 ms").arg(records).arg(t.elapsed());
    t.restart();
    ok = query.exec("select * from automobile order by id desc");
    if(ok)
    {
        qDebug()<<QString("%1 records ordered, time cost: %2 ms").arg(records).arg(t.elapsed());
    }
    else
    {
        qDebug()<<"Failed to order";
    }
    t.restart();
    for(int i=0;i<records;i++)
    {
        query.clear();
        query.prepare(QString("update automobile set attribute=?,type=?,"
                              "kind=?,nation=?,carnumber=?,"
                              "elevator=?,distance=?,oil=?,"
                              "temperature=? where id=%1").arg(i));
        query.bindValue(0,"Four Wheel");
        query.bindValue(1,"Car");
        query.bindValue(2,"XXX");
        query.bindValue(3,rand()%100);
        query.bindValue(4,rand()%10000);
        query.bindValue(5,rand()%300);
        query.bindValue(6,rand()%200000);
        query.bindValue(7,rand()%52);
        query.bindValue(8,rand()%100);
        ok=query.exec();
        if(!ok)
        {
            QSqlError error=query.lastError();
            qDebug()<<error.driverText();
        }
    }
    qDebug()<<QString("%1 records updated, time cost: %2").arg(records).arg(t.elapsed());
    t.restart();
    query.exec("delete from automobile where id=15");
    qDebug()<<QString("A record deleted, time cost: %1 ms").arg(t.elapsed());
    return 0;
}
