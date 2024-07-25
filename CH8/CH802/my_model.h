#ifndef MY_MODEL_H
#define MY_MODEL_H

#include <QAbstractTableModel>

class my_model : public QAbstractTableModel
{
    Q_OBJECT
public:
    my_model(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent=QModelIndex()) const;
    int columnCount(const QModelIndex &parent=QModelIndex()) const;
    QVariant data(const QModelIndex &index,int role) const;
    QVariant headerData(int section,Qt::Orientation orientation,int role) const;

private:
    QVector<short> army;
    QVector<short> weapon_type;
    QStringList weapon;
    QMap<short,QString>army_map;
    QMap<short,QString>weapon_type_map;
    QStringList header;
};

#endif // MY_MODEL_H
