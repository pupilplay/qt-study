#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <QDialog>
#include<QResizeEvent>
#include<QMoveEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class Geometry;
}
QT_END_NAMESPACE

class Geometry : public QDialog
{
    Q_OBJECT

protected:
    void resizeEvent(QResizeEvent *ev) override;
    void moveEvent(QMoveEvent *ev) override;
public:
    Geometry(QWidget *parent = nullptr);
    ~Geometry();

    void update_label();
private:
    Ui::Geometry *ui;
};
#endif // GEOMETRY_H
