#include "complete.h"

#include <QtWidgets>

const int SCREEN_HEIGHT = 740;
const int SCREEN_WIDTH = 1024;

Complete::Complete(QWidget* parent) :
    QDialog(parent)
{
    setItems();
    setConnect();
    layItems();
}

Complete::~Complete(){

}

void Complete::setItems(){
    btClose = new QPushButton(tr("Exit"));
    btShop = new QPushButton(tr("Shop"));

    lbThanks = new QLabel(tr("<b>Thank you for shopping!</b>"));
    lbMsg = new QLabel(tr("You're package will arrive in the specified time frame."));

    spMsg1 = new QSpacerItem(430,50);
    spMsg2 = new QSpacerItem(350,50);
    spBtn = new QSpacerItem(500,50);
}

void Complete::setConnect(){
    connect(btClose,SIGNAL(clicked()),
            this, SLOT(goExit()));
    connect(btShop,SIGNAL(clicked()),
            this, SLOT(goShop()));

}

void Complete::layItems(){
    QHBoxLayout* loMsg1 = new QHBoxLayout;
    loMsg1->addSpacerItem(spMsg1);
    loMsg1->addWidget(lbThanks);
    loMsg1->addSpacerItem(spMsg1);

    QHBoxLayout* loMsg2 = new QHBoxLayout;
    loMsg2->addSpacerItem(spMsg2);
    loMsg2->addWidget(lbMsg);
    loMsg2->addSpacerItem(spMsg2);

    QVBoxLayout* loBtn = new QVBoxLayout;
    loBtn->addWidget(btShop);
    loBtn->addWidget(btClose);

    QHBoxLayout* loBot = new QHBoxLayout;
    loBot->addSpacerItem(spBtn);
    loBot->addLayout(loBtn);
    loBot->addSpacerItem(spBtn);

    QVBoxLayout* loMain = new QVBoxLayout;
    loMain->addStretch(2);
    loMain->addLayout(loMsg1);
    loMain->addLayout(loMsg2);
    loMain->addStretch(1);
    loMain->addLayout(loBot);
    loMain->addStretch(1);

    setLayout(loMain);


    setFixedHeight(SCREEN_HEIGHT);
    setFixedWidth(SCREEN_WIDTH);

}

void Complete::goShop(){
    emit toShop();
}

void Complete::goExit(){
    emit toExit();
}
