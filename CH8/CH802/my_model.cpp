#include "my_model.h"

my_model::my_model(QObject *parent)
    :QAbstractTableModel(parent),header{"Type","Weapon type","Weapon"}
{
    //    QMap<short,QString>army_map;
    //    QMap<short,QString>weapon_type_map;
    army_map[1]="Air force";
    army_map[2]="Navy";
    army_map[3]="Army";
    army_map[4]="Marine";
    weapon_type_map[1]="Bomber";
    weapon_type_map[2]="Fighter";
    weapon_type_map[3]="Aircraft carrier";
    weapon_type_map[4]="Destroyer";
    weapon_type_map[5]="Helicopter";
    weapon_type_map[6]="Tank";
    weapon_type_map[7]="Amphibia attacker";
    weapon_type_map[8]="Amphibia tank";

    army<<1<<2<<3<<4<<2<<4<<3<<1;
    weapon_type<<1<<3<<5<<7<<4<<8<<6<<2;
    weapon<<"A"<<"B"<<"C"<<"D"<<"E"<<"G"<<"J"<<"K";
}

int my_model::rowCount(const QModelIndex &parent) const
{
    return army.size();
}

int my_model::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant my_model::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }
    switch(role)
    {
    case Qt::DisplayRole:
        switch(index.column())
        {
        case 0:
            return army_map[army[index.row()]];
            break;
        case 1:
            return weapon_type_map[weapon_type[index.row()]];
            break;
        case 2:
            return weapon[index.row()];
            break;
        default:
            return QVariant();
        }
        break;
    default:
        return QVariant();
    }
}

QVariant my_model::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role==Qt::DisplayRole && orientation == Qt::Horizontal)
    {
        return header[section];
    }
    return QAbstractTableModel::headerData(section,orientation,role);
}
