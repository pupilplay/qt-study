#include "combo_delegate.h"
#include <QComboBox>

combo_delegate::combo_delegate(QObject *parent)
    : QStyledItemDelegate{parent}
{
    ;
}

QWidget *combo_delegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QComboBox *editor=new QComboBox(parent);
    editor->addItem("Worker");
    editor->addItem("Farmer");
    editor->addItem("Doctor");
    editor->addItem("Lawyer");
    editor->addItem("Soldier");
    editor->installEventFilter(const_cast<combo_delegate*>(this));
    return editor;
}

void combo_delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    QString str=index.model()->data(index).toString();
    QComboBox* box=static_cast<QComboBox*>(editor);
    int i=box->findText(str);
    box->setCurrentIndex(i);
}

void combo_delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    QComboBox* box=static_cast<QComboBox*>(editor);
    QString str=box->currentText();
    model->setData(index,str);
}

void combo_delegate::updateEditorGeometry(QWidget *editor,const QStyleOptionViewItem &option,const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

