#ifndef DATE_DELEGATE_H
#define DATE_DELEGATE_H

#include <QStyledItemDelegate>

class date_delegate : public QStyledItemDelegate
{
    Q_OBJECT
public:
    date_delegate(QObject *parent = nullptr);
    QWidget *createEditor(QWidget *parent,const QStyleOptionViewItem &option,const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor,const QStyleOptionViewItem &option,const QModelIndex &index) const override;
};
#endif // DATE_DELEGATE_H
