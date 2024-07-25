#include "spin_delegate.h"
#include <QSpinBox>

spin_delegate::spin_delegate(QObject *parent)
    : QStyledItemDelegate{parent}
{
    ;
}

QWidget *spin_delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QSpinBox *editor = new QSpinBox(parent);
    editor->setRange(0,10000);
    editor->installEventFilter(const_cast<spin_delegate*>(this));
    return editor;
}

void spin_delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    int value = index.model()->data(index).toInt();
    QSpinBox *box = static_cast<QSpinBox*>(editor);
    box->setValue(value);
}

void spin_delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QSpinBox *box=static_cast<QSpinBox*>(editor);
    int value=box->value();
    model->setData(index,value);
}

void spin_delegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}
