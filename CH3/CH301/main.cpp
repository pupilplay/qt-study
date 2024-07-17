#include<QSplitter>
#include<QTextEdit>
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setFont(QFont("ZYSong18030",12));
    QSplitter *splitter_main=new QSplitter(Qt::Horizontal,nullptr);
    QTextEdit *text_left=new QTextEdit("left widget",splitter_main);
    text_left->setAlignment(Qt::AlignCenter);
    QSplitter *splitter_right=new QSplitter(Qt::Vertical,splitter_main);
    splitter_right->setOpaqueResize(false);
    QTextEdit *text_bottom=new QTextEdit("bottom widget",splitter_right);
    text_bottom->setAlignment(Qt::AlignCenter);
    QTextEdit *text_up=new QTextEdit("top widget",splitter_right);
    text_up->setAlignment(Qt::AlignCenter);
    splitter_main->setStretchFactor(1,1);
    splitter_main->setStretchFactor(0,2);
    splitter_main->setWindowTitle("splitter");
    splitter_main->show();
    a.exec();
    splitter_main->deleteLater();
    return 0;
}
