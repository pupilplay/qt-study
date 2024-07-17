#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include<QtPrintSupport/QPrintDialog>
#include<QtPrintSupport/QPrinter>
#include<QPainter>
#include<QFontDatabase>
#include<QColorDialog>
#include<QTextList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    edit_space = new workspace(this);
    setCentralWidget(edit_space);
    create_font_buttons();
    create_actions();
    create_list_items();
    create_menus();
    create_toolbars();
    connect(edit_space->text,&QTextEdit::cursorPositionChanged,this,&MainWindow::update_info);
    if(image.load(":/image.png"))
    {
        edit_space->image_label->setPixmap(QPixmap::fromImage(image));
    }
    this->adjustSize();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::create_actions()
{
    open_file_action=new QAction(QIcon(":/open.png"),"Open",this);
    open_file_action->setShortcut(QString("Ctrl+O"));
    open_file_action->setStatusTip("Open file");
    connect(open_file_action,&QAction::triggered,edit_space,&workspace::load_file);
    new_file_action=new QAction(QIcon(":/new.png"),"New",this);
    new_file_action->setShortcut(QString("Ctrl+N"));
    new_file_action->setStatusTip("New file");
    connect(new_file_action,&QAction::triggered,edit_space,&workspace::new_file);
    print_text_action=new QAction(QIcon(":/print.png"),"Print text",this);
    print_text_action->setStatusTip("Print text");
    connect(print_text_action,&QAction::triggered,this,&MainWindow::print_text);
    print_image_action=new QAction(QIcon(":/print.png"),"Print image",this);
    print_image_action->setStatusTip("Print image");
    connect(print_image_action,&QAction::triggered,this,&MainWindow::print_image);
    exit_action=new QAction(QIcon(":/exit.png"),"Exit",this);
    exit_action->setShortcut(QString("Ctrl+Q"));
    exit_action->setStatusTip("Exit");
    connect(exit_action,&QAction::triggered,this,&QMainWindow::close);
    copy_action=new QAction(QIcon(":/copy.png"),"Copy",this);
    copy_action->setShortcut(QString("Ctrl+C"));
    copy_action->setStatusTip("Copy");
    connect(copy_action,&QAction::triggered,edit_space->text,&QTextEdit::copy);
    cut_action=new QAction(QIcon(":/cut.png"),"Cut",this);
    cut_action->setShortcut(QString("Ctrl+C"));
    cut_action->setStatusTip("Copy");
    connect(cut_action,&QAction::triggered,edit_space->text,&QTextEdit::cut);
    paste_action=new QAction(QIcon(":/paste.png"),"Paste",this);
    paste_action->setShortcut(QString("Ctrl+V"));
    paste_action->setStatusTip("Paste");
    connect(paste_action,&QAction::triggered,edit_space->text,&QTextEdit::paste);
    about_action=new QAction(QIcon(":/about.png"),"About",this);
    about_action->setStatusTip("About");
    connect(about_action,&QAction::triggered,this,&QApplication::aboutQt);
    zoomin_action=new QAction(QIcon(":/zoomin.png"),"Zoom in",this);
    zoomin_action->setStatusTip("Zoom in");
    connect(zoomin_action,&QAction::triggered,this,&MainWindow::zoomin);
    zoomout_action=new QAction(QIcon(":/zoomout.png"),"Zoom out",this);
    zoomout_action->setStatusTip("Zoom out");
    connect(zoomout_action,&QAction::triggered,this,&MainWindow::zoomout);
    rotate90_action=new QAction(QIcon(":/rotate90.png"),"Rotate 90 degrees",this);
    rotate90_action->setStatusTip("Rotate 90 degrees");
    connect(rotate90_action,&QAction::triggered,this,&MainWindow::rotate90);
    rotate180_action=new QAction(QIcon(":/rotate180.png"),"Rotate 180 degrees",this);
    rotate180_action->setStatusTip("Rotate 180 degrees");
    connect(rotate180_action,&QAction::triggered,this,&MainWindow::rotate180);
    rotate270_action=new QAction(QIcon(":/rotate270.png"),"Rotate 270 degrees",this);
    rotate270_action->setStatusTip("Rotate 270 degrees");
    connect(rotate270_action,&QAction::triggered,this,&MainWindow::rotate270);
    mirror_horizontal_action=new QAction(QIcon(":/mirror_horizontal.png"),"Mirror horizontally",this);
    mirror_horizontal_action->setStatusTip("Mirror horizontally");
    connect(mirror_horizontal_action,&QAction::triggered,this,&MainWindow::mirror_horizontal);
    mirror_vertical_action=new QAction(QIcon(":/mirror_vertical.png"),"Mirror vertically",this);
    mirror_vertical_action->setStatusTip("Mirror vertically");
    connect(mirror_vertical_action,&QAction::triggered,this,&MainWindow::mirror_vertical);


    undo_action=new QAction(QIcon(":/undo.png"),"Undo",this);
    undo_action->setStatusTip("Undo");
    connect(undo_action,&QAction::triggered,edit_space->text,&QTextEdit::undo);
    redo_action=new QAction(QIcon(":/redo.png"),"Redo",this);
    connect(redo_action,&QAction::triggered,edit_space->text,&QTextEdit::redo);
    redo_action->setStatusTip("Redo");
    //connect

}

void MainWindow::create_menus()
{
    file_menu=this->menuBar()->addMenu("File");
    file_menu->addAction(open_file_action);
    file_menu->addAction(new_file_action);
    file_menu->addAction(print_text_action);
    file_menu->addAction(print_image_action);
    file_menu->addSeparator();
    file_menu->addAction(exit_action);
    zoom_menu=this->menuBar()->addMenu("Zoom");
    zoom_menu->addAction(zoomin_action);
    zoom_menu->addAction(zoomout_action);
    rotate_menu=this->menuBar()->addMenu("Rotate");
    rotate_menu->addAction(rotate90_action);
    rotate_menu->addAction(rotate180_action);
    rotate_menu->addAction(rotate270_action);
    mirror_menu=this->menuBar()->addMenu("Mirror");
    mirror_menu->addAction(mirror_horizontal_action);
    mirror_menu->addAction(mirror_vertical_action);
}

void MainWindow::create_toolbars()
{
    file_tool=this->addToolBar("File");
    file_tool->addAction(open_file_action);
    file_tool->addAction(new_file_action);
    file_tool->addAction(print_text_action);
    file_tool->addAction(print_image_action);
    file_tool->addSeparator();
    file_tool->addAction(exit_action);
    zoom_tool=this->addToolBar("Zoom");
    zoom_tool->addAction(zoomin_action);
    zoom_tool->addAction(zoomout_action);
    rotate_tool=this->addToolBar("Rotate");
    rotate_tool->addAction(rotate90_action);
    rotate_tool->addAction(rotate180_action);
    rotate_tool->addAction(rotate270_action);
    mirror_tool=this->addToolBar("Mirror");
    mirror_tool->addAction(mirror_horizontal_action);
    mirror_tool->addAction(mirror_vertical_action);
    this->addToolBarBreak(Qt::TopToolBarArea);
    font_toolbar =this->addToolBar("Font");
    font_toolbar->addWidget(font_type_label);
    font_toolbar->addWidget(font_box);
    font_toolbar->addWidget(font_size_label);
    font_toolbar->addWidget(size_box);
    font_toolbar->addWidget(bold_btn);
    font_toolbar->addWidget(italic_btn);
    font_toolbar->addWidget(underline_btn);
    font_toolbar->addSeparator();
    font_toolbar->addWidget(color_btn);
    list_toolbar=this->addToolBar("List");
    list_toolbar->addWidget(list_label);
    list_toolbar->addWidget(list_box);
    list_toolbar->addSeparator();
    list_toolbar->addActions(act_group->actions());
}

void MainWindow::create_font_buttons()
{
    font_type_label=new QLabel("Font");
    font_box=new QFontComboBox();
    font_box->setFontFilters(QFontComboBox::ScalableFonts);
    connect(font_box,&QFontComboBox::textActivated,edit_space,[this](QString font)->void{
        QTextCharFormat format;
        format.setFontFamilies(QStringList{font});
        this->edit_space->merge_format(format);
    });
    font_size_label=new QLabel("Size");
    size_box=new QComboBox();
    size_box->addItem("NULL");
    for(int size:QFontDatabase::standardSizes())
    {
        size_box->addItem(QString::number(size));
    }
    size_box->setSizeAdjustPolicy(QComboBox::AdjustToContents);
    connect(size_box,&QFontComboBox::textActivated,edit_space,[this](QString size)->void{
        QTextCharFormat format;
        format.setFontPointSize(size.toFloat());
        this->edit_space->merge_format(format);
    });
    bold_btn=new QToolButton();
    bold_btn->setIcon(QIcon(":/bold.png"));
    bold_btn->setCheckable(true);
    connect(bold_btn,&QToolButton::clicked,edit_space,[this]()->void{
        QTextCharFormat format;
        format.setFontWeight(bold_btn->isChecked()?QFont::Bold:QFont::Normal);
        this->edit_space->merge_format(format);
    });
    italic_btn=new QToolButton();
    italic_btn->setIcon(QIcon(":/italic.png"));
    italic_btn->setCheckable(true);
    connect(italic_btn,&QToolButton::clicked,edit_space,[this]()->void{
        QTextCharFormat format;
        format.setFontItalic(italic_btn->isChecked());
        this->edit_space->merge_format(format);
    });
    underline_btn=new QToolButton();
    underline_btn->setIcon(QIcon(":/underline.png"));
    underline_btn->setCheckable(true);
    connect(underline_btn,&QToolButton::clicked,edit_space,[this]()->void{
        QTextCharFormat format;
        format.setFontUnderline(underline_btn->isChecked());
        this->edit_space->merge_format(format);
    });
    color_btn=new QToolButton();
    color_btn->setIcon(QIcon(":/color.png"));
    color_btn->setCheckable(false);
    connect(color_btn,&QToolButton::clicked,edit_space,[this]()->void{
        QColorDialog dlg(Qt::black,this);
        dlg.adjustSize();
        dlg.show();
        if(dlg.exec())
        {
            QColor color=dlg.currentColor();
            QTextCharFormat format;
            format.setForeground(QBrush(color));
            this->edit_space->merge_format(format);
        }
    });
}

void MainWindow::create_list_items()
{
    list_label=new QLabel("Format");
    list_box=new QComboBox();
    list_box->addItem("Standard");
    list_box->addItem("Disc");
    list_box->addItem("Circle");
    list_box->addItem("Decimal");
    list_box->addItem("LowerAlpha");
    list_box->addItem("UpperAlpha");
    list_box->addItem("LowerRoman");
    list_box->addItem("UpperRoman");
    connect(list_box,&QComboBox::activated,this,[this](int index)->void{
        QTextCursor cursor=edit_space->text->textCursor();
        QTextListFormat::Style style;
        switch(index)
        {
        case 1:
            style=QTextListFormat::ListDisc;
            break;
        case 2:
            style=QTextListFormat::ListCircle;
            break;
        case 3:
            style=QTextListFormat::ListSquare;
        case 4:
            style=QTextListFormat::ListDecimal;
            break;
        case 5:
            style=QTextListFormat::ListLowerAlpha;
            break;
        case 6:
            style=QTextListFormat::ListUpperAlpha;
            break;
        case 7:
            style=QTextListFormat::ListLowerRoman;
            break;
        case 8:
            style=QTextListFormat::ListUpperRoman;
            break;
        default:
            return;
            break;
        }
        cursor.beginEditBlock();
        QTextBlockFormat block_format=cursor.blockFormat();
        QTextListFormat list_format;
        if(cursor.currentList())
        {
            list_format=cursor.currentList()->format();
        }
        else
        {
            list_format.setIndent(block_format.indent()+1);
            block_format.setIndent(0);
            cursor.setBlockFormat(block_format);
        }
        list_format.setStyle(style);
        cursor.createList(list_format);
        cursor.endEditBlock();
    });
    act_group=new QActionGroup(this);
    left_action=new QAction(QIcon(":/align_left.png"),"Left align",act_group);
    left_action->setCheckable(true);
    right_action=new QAction(QIcon(":/align_right.png"),"Right align",act_group);
    right_action->setCheckable(true);
    center_action=new QAction(QIcon(":/align_center.png"),"Center align",act_group);
    center_action->setCheckable(true);
    justify_action=new QAction(QIcon(":/align_justify.png"),"Justify align",act_group);
    justify_action->setCheckable(true);
    connect(act_group,&QActionGroup::triggered,this,[this](QAction *action)->void{
        if(action ==left_action)
        {
            edit_space->text->setAlignment(Qt::AlignLeft);
        }
        else if(action ==right_action)
        {
            edit_space->text->setAlignment(Qt::AlignRight);
        }
        else if(action ==center_action)
        {
            edit_space->text->setAlignment(Qt::AlignCenter);
        }
        else if(action ==justify_action)
        {
            edit_space->text->setAlignment(Qt::AlignJustify);
        }
    });
}


void MainWindow::print_text()
{
    QPrinter printer;
    QPrintDialog print_dialog(&printer,this);
    if(print_dialog.exec())
    {
        QTextDocument *doc=edit_space->text->document();
        doc->print(&printer);
    }
}

void MainWindow::print_image()
{
    QPrinter printer;
    QPrintDialog print_dialog(&printer,this);
    if(print_dialog.exec())
    {
        QPainter painter(&printer);
        QRect rect(painter.viewport());
        QSize size= image.size();
        size.scale(rect.size(),Qt::KeepAspectRatio);
        painter.setViewport(rect.x(),rect.y(),size.width(),size.height());
        painter.setWindow(image.rect());
        painter.drawImage(0,0,image);
    }
}

void MainWindow::zoomin()
{
    if(image.isNull())
    {
        return;
    }
    QTransform matrix;
    matrix.scale(2,2);
    image= image.transformed(matrix);
    edit_space->image_label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::zoomout()
{
    if(image.isNull())
    {
        return;
    }
    QTransform matrix;
    matrix.scale(0.5,0.5);
    image= image.transformed(matrix);
    edit_space->image_label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::rotate90()
{
    if(image.isNull())
    {
        return;
    }
    QTransform matrix;
    matrix.rotate(90);
    image= image.transformed(matrix);
    edit_space->image_label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::rotate180()
{
    if(image.isNull())
    {
        return;
    }
    QTransform matrix;
    matrix.rotate(180);
    image= image.transformed(matrix);
    edit_space->image_label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::rotate270()
{
    if(image.isNull())
    {
        return;
    }
    QTransform matrix;
    matrix.rotate(270);
    image= image.transformed(matrix);
    edit_space->image_label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::mirror_horizontal()
{
    if(image.isNull())
    {
        return;
    }
    image.mirror(true,false);
    edit_space->image_label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::mirror_vertical()
{
    if(image.isNull())
    {
        return;
    }
    image.mirror(false,true);
    edit_space->image_label->setPixmap(QPixmap::fromImage(image));
}

void MainWindow::update_info()
{
    QTextCharFormat format =edit_space->text->textCursor().blockCharFormat();
    switch(format.fontWeight())
    {
    case QFont::Bold:
        bold_btn->setChecked(true);
        break;
    case QFont::Normal:
        bold_btn->setChecked(false);
        break;
    default:
        break;
    }
    italic_btn->setChecked(format.fontItalic());
    underline_btn->setChecked(format.fontUnderline());
    switch(edit_space->text->alignment())
    {
    case Qt::AlignLeft:
        left_action->setChecked(true);
        break;
    case Qt::AlignRight:
        right_action->setChecked(true);
        break;
    case Qt::AlignCenter:
        center_action->setChecked(true);
        break;
    case Qt::AlignJustify:
        justify_action->setChecked(true);
        break;
    default:
        break;
    }
}
