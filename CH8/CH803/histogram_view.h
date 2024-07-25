#ifndef HISTOGRAM_VIEW_H
#define HISTOGRAM_VIEW_H

#include <QAbstractItemView>
#include<QMouseEvent>
#include<QPaintEvent>
#include<QPainter>

class histogram_view : public QAbstractItemView
{
    Q_OBJECT
public:
    histogram_view(QWidget *parent = nullptr);
    void setSelectionModel(QItemSelectionModel *selectionModel) override;
    QRegion item_region(QModelIndex index);
    QModelIndex indexAt(const QPoint &point) const override;
    QRect visualRect(const QModelIndex &index) const override {return QRect();}
    void scrollTo(const QModelIndex &index,ScrollHint) override {}
protected:
    void paintEvent(QPaintEvent *ev) override;
    void mousePressEvent(QMouseEvent *ev) override;
    QModelIndex moveCursor(QAbstractItemView::CursorAction cursorAction, Qt::KeyboardModifiers modifiers) override {return QModelIndex();}
    int horizontalOffset() const override{return 0;}
    int verticalOffset() const override{return 0;}
    bool isIndexHidden(const QModelIndex &index) const override{return 0;}
    QRegion visualRegionForSelection(const QItemSelection &selection) const override {return QRegion();}
protected slots:
    void selectionChanged(const QItemSelection &selected,const QItemSelection &deselected) override;
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QList<int> &roles = QList<int>()) override;
    void setSelection(const QRect &rect,QItemSelectionModel::SelectionFlags flags) override;
private:
    QItemSelectionModel *selections;
    QList<QRegion> male_region_list;
    QList<QRegion> female_region_list;
    QList<QRegion> retired_region_list;
};

#endif // HISTOGRAM_VIEW_H
