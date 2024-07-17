#include "dialog.h"
#include "./ui_dialog.h"


Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    username_label =new QLabel("username:");
    nickname_label =new QLabel("nickname:");
    gender_label =new QLabel("gender:");
    department_label=new QLabel("department:");
    age_label=new QLabel("age:");
    note_label=new QLabel("note:");
    note_label->setFrameStyle(QFrame::Panel|QFrame::Sunken);
    username_input=new QLineEdit();
    nickname_input=new QLineEdit();
    gender_box=new QComboBox();
    gender_box->addItem("Male");
    gender_box->addItem("Female");
    department_input=new QTextEdit();
    age_input=new QLineEdit();
    profile_label=new QLabel("profile picture:");
    profile_image=new QLabel();
    profile_image->setPixmap(QPixmap("://icon.png"));
    profile_update_btn =new QPushButton("update");
    info_label=new QLabel("personal information:");
    info_input =new QTextEdit();
    ok_btn=new QPushButton("OK");
    cancel_btn=new QPushButton("Cancel");

    main_layout= new QGridLayout(this);
    left_layout=new QGridLayout();
    right_layout= new QVBoxLayout();
    profile_layout=new QHBoxLayout();
    bottom_layout=new QHBoxLayout();

    main_layout->addLayout(left_layout,0,0);
    main_layout->addLayout(right_layout,0,1);
    main_layout->setSpacing(10);
    main_layout->setContentsMargins(QMargins(15,15,15,15));

    left_layout->addWidget(username_label,0,0);
    left_layout->addWidget(nickname_label,1,0);
    left_layout->addWidget(gender_label,2,0);
    left_layout->addWidget(department_label,3,0);
    left_layout->addWidget(age_label,4,0);
    left_layout->addWidget(note_label,5,0,1,2);
    left_layout->addWidget(username_input,0,1);
    left_layout->addWidget(nickname_input,1,1);
    left_layout->addWidget(gender_box,2,1);
    left_layout->addWidget(department_input,3,1);
    left_layout->addWidget(age_input,4,1);

    right_layout->addLayout(profile_layout);
    profile_layout->addWidget(profile_label);
    profile_layout->addWidget(profile_image);
    profile_layout->addWidget(profile_update_btn);
    right_layout->addWidget(info_label);
    right_layout->addWidget(info_input);

    main_layout->addLayout(bottom_layout,1,0,1,2);
    bottom_layout->addStretch();
    bottom_layout->addWidget(ok_btn);
    bottom_layout->addWidget(cancel_btn);
}

Dialog::~Dialog()
{
    delete ui;
}
