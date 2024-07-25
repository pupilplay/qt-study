#include "date_delegate.h"
#include<QDateTimeEdit>
date_delegate::date_delegate(QObject *parent)
    :QStyledItemDelegate(parent)
{
    ;
}

QWidget *date_delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QDateTimeEdit *editor=new QDateTimeEdit(parent);
    editor->setDisplayFormat("yyyy-MM-dd");
    editor->setCalendarPopup(true);
    editor->installEventFilter(const_cast<date_delegate*>(this));
    return editor;
}


void date_delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString data_str=index.model()->data(index).toString();
    QDate date=QDate::fromString(data_str,Qt::ISODate);
    QDateTimeEdit *edit=static_cast<QDateTimeEdit*>(editor);
    edit->setDate(date);
}

void date_delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QDateTimeEdit *edit=static_cast<QDateTimeEdit*>(editor);
    QDate date=edit->date();
    model->setData(index,QVariant(date.toString(Qt::ISODate)));
}

void date_delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

