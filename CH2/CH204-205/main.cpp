#include <QCoreApplication>

int main(int argc, char *argv[])
{
    QMap<QString,QString>map;
    map.insert("key1","value1");
    map["abc"]="value2";
    map.insert("zzz","value3");
    map.insert("ABC","value4");
    //"ABC"<"abc"<"key1"<"zzz"
    for(QMapIterator<QString,QString>it_java(map);it_java.hasNext();it_java.next())
    {
        qDebug()<<it_java.peekNext().key()<<" "<<it_java.peekNext().value();
    }
    QMutableMapIterator<QString,QString>mutable_it_java(map);
    if(mutable_it_java.findNext("value3"))
    {
        mutable_it_java.setValue("value_changed");
    }
    for(auto it =map.constBegin();it!=map.constEnd();it++)
    {
        qDebug()<<it.key() <<" "<<it.value();
    }
    auto it=map.find("abc");
    if(it!=map.end())
    {
        it.value()="value changed in STL style";
    }
    for(auto [key,value]:map.asKeyValueRange())
    {
        qDebug()<<key<<value;
    }
    return 0;
}
