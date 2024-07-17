#ifndef WORKSPACE_H
#define WORKSPACE_H

#include <QWidget>
#include<QTextEdit>
#include<QLabel>
#include<QImage>
#include<QHBoxLayout>

class workspace : public QWidget
{
    Q_OBJECT
    friend class MainWindow;
public:
    explicit workspace(QWidget *parent = nullptr);

public slots:
    void new_file();
    void load_file();
    void text_clear();
    void merge_format(QTextCharFormat format);
signals:

private:
    QImage image;
    QLabel *image_label;
    QTextEdit *text;
    QHBoxLayout *main_layout;
};

#endif // WORKSPACE_H
