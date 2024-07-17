#include "workspace.h"
#include<QFile>
#include<QFileDialog>
#include<QMessageBox>
#include<QTextCursor>

workspace::workspace(QWidget *parent)
    : QWidget{parent}
{
    main_layout=new QHBoxLayout(this);
    image_label=new QLabel();
    text= new QTextEdit();
    main_layout->addWidget(image_label);
    main_layout->addWidget(text);
}

void workspace::new_file()
{
    if(text->document()->isEmpty())
    {
        return;
    }
    switch(QMessageBox::question(this,"New","Discard current text or not?",QMessageBox::Discard|QMessageBox::Cancel,QMessageBox::Cancel))
    {
    case QMessageBox::Discard:
        if(!text->document()->isEmpty())
        {
            text_clear();
        }
        break;
    case QMessageBox::Cancel:
        break;
    default:
        break;
    }
}

void workspace::load_file()
{
    QString filename=QFileDialog::getOpenFileName(this,"Open","./");
    if(!filename.isEmpty())
    {
        QFile file(filename);
        if(file.open(QIODevice::ReadOnly|QIODevice::Text))
        {
            if(!text->document()->isEmpty())
            {
                text_clear();
            }
            QTextStream text_stream(&file);
            while(!text_stream.atEnd())
            {
                text->append(text_stream.readLine());
            }
        }
        else
        {
            qDebug()<<"Failed to open the file";
        }
    }
}

void workspace::text_clear()
{
    main_layout->removeWidget(text);
    text->deleteLater();
    text=new QTextEdit();
    main_layout->addWidget(text);
}

void workspace::merge_format(QTextCharFormat format)
{
    QTextCursor cursor=text->textCursor();
    if(!cursor.hasSelection())
    {
        cursor.select(QTextCursor::WordUnderCursor);
    }
    cursor.mergeCharFormat(format);
    text->mergeCurrentCharFormat(format);
}
