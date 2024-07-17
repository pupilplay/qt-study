#include "drawer.h"
#include<QGroupBox>
#include<QVBoxLayout>
drawer::drawer(QWidget *parent):QToolBox(parent)
{
    QSizePolicy policy;
    policy.setHorizontalPolicy(QSizePolicy::Preferred);
    policy.setVerticalPolicy(QSizePolicy::Maximum);
    this->setSizePolicy(policy);
    for(int i=0;i<3;i++)
    {
        QGroupBox *box=new QGroupBox;

        QVBoxLayout *layout=new QVBoxLayout(box);
        for(int j=0;j<=i;j++)
        {
            QToolButton *user=new QToolButton();
            user->setText("user"+QString::number(i*2+j+1));
            user->setIcon(QIcon(QPixmap(":/"+QString::number(i*2+j+1)+".png")));
            user->setIconSize(QPixmap(":/"+QString::number(i*2+j+1)+".png").size());
            user->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
            user->setAutoRaise(true);
            layout->addWidget(user);
        }
        layout->addStretch();
        //layout->setSizeConstraint(QLayout::SetFixedSize);
        this->addItem(box,"group"+QString::number(i));
    }
}
