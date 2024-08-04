#include <QCoreApplication>
#include<QVariant>
int main(int argc, char *argv[])
{
    QVariant v(52);
    qDebug()<<v.toInt();
    qDebug()<<v.toChar();
    QHash<QString,QVariant>hash;
    hash["int"]=100;
    hash["double"]=12.34;
    hash["text"]="hello variant";
    hash["Qvector<Variant>"]=QList<QVariant>{1,2,3};
    hash["int2"]=300;
    for(auto &var:hash)
    {
        switch(var.metaType().id())
        {
        case QMetaType::Int:
            qDebug()<<var.toInt();
            break;
        case QMetaType::Double:
            qDebug()<<var.toDouble();
            break;
        case QMetaType::QString:
            qDebug()<<var.toString();
            break;
        case QMetaType::QVariantList:
            qDebug()<<var.toList();
            break;
        default:
            break;
        }
    }
    return 0;
}
