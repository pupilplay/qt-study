#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTreeWidgetItem>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    void init();
    void update_parent_item(QTreeWidgetItem* item);
    void update_child_item(QTreeWidgetItem* item,Qt::CheckState state);
public slots:
    void update_item(QTreeWidgetItem* item,int column);
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
