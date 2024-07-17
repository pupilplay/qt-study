#include "dialog.h"
#include "./ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    color_list =QColor::colorNames();
    fill_colorlist(ui->window_box);
    fill_colorlist(ui->windowtext_box);
    fill_colorlist(ui->button_box);
    fill_colorlist(ui->buttontext_box);
    fill_colorlist(ui->base_box);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::fill_colorlist(QComboBox *box)
{
    for(auto &color:color_list)
    {
        QPixmap pix(QSize(70,20));
        pix.fill(QColor(color));
        box->addItem(QIcon(pix),NULL);
        box->setIconSize(QSize(70,20));
    }
    box->setSizeAdjustPolicy(QComboBox::AdjustToContents);
}

void Dialog::on_window_box_activated(int index)
{
    QPalette p =ui->left_frame->palette();
    p.setColor(QPalette::Window,QColor(color_list[index]));
    ui->left_frame->setPalette(p);
    ui->left_frame->update();
}


void Dialog::on_windowtext_box_activated(int index)
{
    QPalette p =ui->left_frame->palette();
    p.setColor(QPalette::WindowText,QColor(color_list[index]));
    ui->left_frame->setPalette(p);
    ui->left_frame->update();
}


void Dialog::on_button_box_activated(int index)
{
    QPalette p =ui->right_frame->palette();
    p.setColor(QPalette::Button,QColor(color_list[index]));
    ui->right_frame->setPalette(p);
    ui->right_frame->update();
}


void Dialog::on_buttontext_box_activated(int index)
{
    QPalette p =ui->right_frame->palette();
    p.setColor(QPalette::ButtonText,QColor(color_list[index]));
    ui->right_frame->setPalette(p);
    ui->right_frame->update();
}


void Dialog::on_base_box_activated(int index)
{
    QPalette p =ui->right_frame->palette();
    p.setColor(QPalette::Base,QColor(color_list[index]));
    ui->right_frame->setPalette(p);
    ui->right_frame->update();
}

