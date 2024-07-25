#include "histogram_view.h"

histogram_view::histogram_view(QWidget *parent)
    :QAbstractItemView(parent)
{
    ;
}

void histogram_view::setSelectionModel(QItemSelectionModel *selectionModel)
{
    selections=selectionModel;
}

QRegion histogram_view::item_region(QModelIndex index)
{
    QRegion region;
    switch(index.column())
    {
    case 1:
        region=male_region_list[index.row()];
        break;
    case 2:
        region=female_region_list[index.row()];
        break;
    case 3:
        region=retired_region_list[index.row()];
        break;
    default:
        break;
    }
    return region;
}

QModelIndex histogram_view::indexAt(const QPoint &point) const
{
    QRegion region;
    foreach(region,male_region_list)
    {
        if(region.contains(point))
        {
            int row= male_region_list.indexOf(region);
            QModelIndex index = model()->index(row,1,rootIndex());
            return index;
        }
    }
    foreach(region,female_region_list)
    {
        if(region.contains(point))
        {
            int row= female_region_list.indexOf(region);
            QModelIndex index = model()->index(row,2,rootIndex());
            return index;
        }
    }
    foreach(region,retired_region_list)
    {
        if(region.contains(point))
        {
            int row= retired_region_list.indexOf(region);
            QModelIndex index = model()->index(row,3,rootIndex());
            return index;
        }
    }
    return QModelIndex();
}

void histogram_view::paintEvent(QPaintEvent *ev)
{
    QPainter painter(viewport());
    painter.setPen(Qt::black);
    int x0=40;
    int y0=250;
    painter.drawLine(x0,y0,40,30);
    painter.drawLine(38,32,40,30);
    painter.drawLine(40,30,42,32);
    painter.drawText(20,30,"People");
    for(int i=1;i<50;i++)
    {
        painter.drawLine(-1,-i*50,1,-i*50);
        painter.drawText(-20,-i*50,QString("%1").arg(i*5));
    }
    painter.drawLine(x0,y0,540,250);
    painter.drawLine(538,248,540,250);
    painter.drawText(545,250,"Department");
    int pos_delta=x0+20;
    for(int row=0;row<model()->rowCount(rootIndex());row++)
    {
        QModelIndex index=model()->index(row,0,rootIndex());
        QString department=model()->data(index).toString();
        painter.drawText(pos_delta,y0+20,department);
        pos_delta+=50;
    }
    int pos_male=x0+20;
    male_region_list.clear();
    for(int row=0;row<model()->rowCount(rootIndex());row++)
    {
        QModelIndex index=model()->index(row,1,rootIndex());
        int male=model()->data(index).toDouble();
        int width=10;
        if(selections->isSelected(index))
        {
            painter.setBrush(QBrush(Qt::blue,Qt::Dense3Pattern));
        }
        else
        {
            painter.setBrush(QBrush(Qt::blue));
        }
        QRect region_male(pos_male,y0-male*10,width,male*10);
        painter.drawRect(region_male);
        male_region_list.insert(row,region_male);
        pos_male+=50;
    }
    int pos_female=x0+30;
    female_region_list.clear();
    for(int row=0;row<model()->rowCount(rootIndex());row++)
    {
        QModelIndex index=model()->index(row,2,rootIndex());
        int female=model()->data(index).toDouble();
        int width=10;
        if(selections->isSelected(index))
        {
            painter.setBrush(QBrush(Qt::red,Qt::Dense3Pattern));
        }
        else
        {
            painter.setBrush(QBrush(Qt::red));
        }
        QRect region_female(pos_female,y0-female*10,width,female*10);
        painter.drawRect(region_female);
        female_region_list.insert(row,region_female);
        pos_female+=50;
    }
    int pos_retired=x0+40;
    retired_region_list.clear();
    for(int row=0;row<model()->rowCount(rootIndex());row++)
    {
        QModelIndex index=model()->index(row,3,rootIndex());
        int retired=model()->data(index).toDouble();
        int width=10;
        if(selections->isSelected(index))
        {
            painter.setBrush(QBrush(Qt::green,Qt::Dense3Pattern));
        }
        else
        {
            painter.setBrush(QBrush(Qt::green));
        }
        QRect region_retired(pos_retired,y0-retired*10,width,retired*10);
        painter.drawRect(region_retired);
        retired_region_list.insert(row,region_retired);
        pos_retired+=50;
    }
}

void histogram_view::mousePressEvent(QMouseEvent *ev)
{
    QAbstractItemView::mousePressEvent(ev);
    setSelection(QRect(ev->pos(),QSize(1,1)),QItemSelectionModel::SelectCurrent);
}

void histogram_view::selectionChanged(const QItemSelection &selected, const QItemSelection &deselected)
{
    viewport()->update();
}

void histogram_view::dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QList<int> &roles)
{
    QAbstractItemView::dataChanged(topLeft,bottomRight);
    viewport()->update();
}

void histogram_view::setSelection(const QRect &rect, QItemSelectionModel::SelectionFlags flags)
{
    int rows=model()->rowCount(rootIndex());
    int columns=model()->columnCount(rootIndex());
    QModelIndex selected_index;
    for(int row=0;row<rows;row++)
    {
        for(int column=1;column<columns;column++)
        {
            QModelIndex index=model()->index(row,column,rootIndex());
            QRegion region=item_region(index);
            if(region.intersects(rect))
            {
                selected_index=index;
            }
        }
    }
    if(selected_index.isValid())
    {
        selections->select(selected_index,flags);
    }
    else
    {
        selections->select(QModelIndex(),flags);
    }
}
