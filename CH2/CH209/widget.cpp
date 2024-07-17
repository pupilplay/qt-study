#include "widget.h"
#include "./ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->treeWidget->clear();
    init();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::init()
{
    for(int i=0;i<4;i++)
    {
        QTreeWidgetItem* group=new QTreeWidgetItem(ui->treeWidget);
        group->setText(0,"group"+QString::number(i));
        group->setFlags(Qt::ItemIsEnabled |Qt::ItemIsSelectable);
        group->setCheckState(0,Qt::Unchecked);
        for(int j=0;j<i;j++)
        {
            QTreeWidgetItem* sub_item=new QTreeWidgetItem(group);
            sub_item->setText(0,"sub_item"+QString().setNum(i)+QString::number(j));
            sub_item->setFlags(Qt::ItemIsEnabled|Qt::ItemIsSelectable);
            sub_item->setCheckState(0,Qt::Unchecked);
            for(int k=0;k<3;k++)
            {
                QTreeWidgetItem* sub2_item=new QTreeWidgetItem(sub_item);
                sub2_item->setText(0,"sub2_item"+QString().setNum(i)+QString::number(j)+QString::number(k));
                sub2_item->setFlags(Qt::ItemIsEnabled|Qt::ItemIsSelectable);
                sub2_item->setCheckState(0,Qt::Unchecked);
            }
        }
    }
    ui->treeWidget->show();
    connect(ui->treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)),this,SLOT(update_item(QTreeWidgetItem*,int)));
}

void Widget::update_parent_item(QTreeWidgetItem *item)
{
    if(nullptr == item)
    {
        return;
    }
    int checked_count=0;
    for(int i=0;i<item->childCount();i++)
    {
        checked_count+=item->child(i)->checkState(0);
    }
    if(checked_count==0)
    {
        item->setCheckState(0,Qt::Unchecked);
    }
    else if(checked_count==item->childCount()*Qt::Checked)
    {
        item->setCheckState(0,Qt::Checked);
    }
    else
    {
        item->setCheckState(0,Qt::PartiallyChecked);
    }
    update_parent_item(item->parent());
}

void Widget::update_child_item(QTreeWidgetItem *item,Qt::CheckState state)
{
    if(item->childCount()>0)
    {
        for(int i=0;i<item->childCount();i++)
        {
            update_child_item(item->child(i),state);
        }
    }
    item->setCheckState(0,state);
}

void Widget::update_item(QTreeWidgetItem *item, int column)
{
    switch(item->checkState(0))
    {
    case Qt::Checked:
        update_child_item(item,Qt::Unchecked);
        break;
    //Qt::Unchecked || Qt::PartiallyChecked
    default:
        update_child_item(item,Qt::Checked);
        break;
    }
    update_parent_item(item->parent());
}
