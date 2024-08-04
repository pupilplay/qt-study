#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QFileInfo>
#include <QListWidget>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui
{
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();
    void update_fileinfo_list(QFileInfoList list);
public slots:
    void update_dir();
    void unfold_dir(QListWidgetItem *item);
private:
    Ui::Dialog *ui;
};
#endif // DIALOG_H
