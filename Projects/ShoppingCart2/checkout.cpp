#include "checkout.h"

#include <QtWidgets>


const int SCREEN_HEIGHT = 740;
const int SCREEN_WIDTH = 1024;


Checkout::Checkout(QWidget* parent) :
    QDialog(parent)
{
    setItems();
    setConnect();
    layItems();
}

Checkout::~Checkout(){

}


void Checkout::setItems(){
    btShop = new QPushButton("Shop");
    btCart = new QPushButton("Cart");
    btSubmit = new QPushButton("Submit");

    spTotal = new QSpacerItem(236, 720);
    spInfo = new QSpacerItem(200, 30);
    spBtn = new QSpacerItem(300, 50);

    leName = new QLineEdit;
    leName->setMaxLength(26);
    leAddr = new QLineEdit;
    leAddr->setMaxLength(50);
    leCity = new QLineEdit;
    leCity->setMaxLength(26);
    leSt = new QLineEdit;
    leSt->setMaxLength(32);
    leZip = new QLineEdit;
    leZip->setMaxLength(5);
    lePhone = new QLineEdit("1234567890");
    lePhone->setMaxLength(10);

    leCard = new QLineEdit;
    leCard->setMaxLength(16);
    leSvc = new QLineEdit;
    leSvc->setMaxLength(3);
    leExp = new QLineEdit("mm/yy");
    leExp->setMaxLength(5);

    lbName = new QLabel(tr("<b>Name:</b>"));
    lbAddr = new QLabel(tr("<b>Address:</b>"));
    lbCity = new QLabel(tr("<b>City:</b>"));
    lbSt = new QLabel(tr("<b>Street:</b>"));
    lbZip = new QLabel(tr("<b>Zip:</b>"));
    lbPhone = new QLabel(tr("<b>Phone:</b>"));

    lbCard = new QLabel(tr("<b>Card:</b>"));
    lbSvc = new QLabel(tr("<b>Security code:</b>"));
    lbExp = new QLabel(tr("<b>Expiration date:</b>"));

    infoBox = new QScrollArea;
    infoBox->setWidget(mkGrp_Scroll());
}

void Checkout::setConnect(){
    connect(btShop, SIGNAL(clicked()),
            this, SLOT(goShop()));
    connect(btCart, SIGNAL(clicked()),
            this, SLOT(goBack()));
    connect(btSubmit, SIGNAL(clicked()),
            this, SLOT(goNext()));

}

void Checkout::layItems(){
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(infoBox);
    mainLayout->addWidget(mkGrp_Total());

    setLayout(mainLayout);

    setFixedHeight(SCREEN_HEIGHT);
    setFixedWidth(SCREEN_WIDTH);
}

QGroupBox* Checkout::mkGrp_Scroll(){
    QGroupBox *groupbox = new QGroupBox();

    QVBoxLayout *loItems = new QVBoxLayout;
    loItems->addWidget(mkGrp_Info());
    loItems->addSpacerItem(spInfo);
    loItems->addWidget(mkGrp_Card());
    loItems->addSpacerItem(spInfo);

    QHBoxLayout *loBtn = new QHBoxLayout;
    loBtn->addSpacerItem(spBtn);
    loBtn->addWidget(btSubmit);
    loBtn->addSpacerItem(spBtn);

    QVBoxLayout *loMain = new QVBoxLayout;
    loMain->addLayout(loItems);
    loMain->addLayout(loBtn);

    groupbox->setLayout(loMain);
    //groupbox->setFixedSize(720,630);

    return groupbox;
}


QGroupBox* Checkout::mkGrp_Info(){
    QGroupBox *groupbox = new QGroupBox(tr("GENERAL INFO"));

    QHBoxLayout* loName = new QHBoxLayout;
    loName->addWidget(lbName);
    loName->addWidget(leName);

    QHBoxLayout* loAddr = new QHBoxLayout;
    loAddr->addWidget(lbAddr);
    loAddr->addWidget(leAddr);

    QHBoxLayout* loCity = new QHBoxLayout;
    loCity->addWidget(lbCity);
    loCity->addWidget(leCity);

    QHBoxLayout* loSt = new QHBoxLayout;
    loSt->addWidget(lbSt);
    loSt->addWidget(leSt);

    QHBoxLayout* loZip = new QHBoxLayout;
    loZip->addWidget(lbZip);
    loZip->addWidget(leZip);

    QHBoxLayout* loPhone = new QHBoxLayout;
    loPhone->addWidget(lbPhone);
    loPhone->addWidget(lePhone);

    QVBoxLayout* loMain = new QVBoxLayout;
    loMain->addLayout(loName);
    loMain->addLayout(loAddr);
    loMain->addLayout(loCity);
    loMain->addLayout(loSt);
    loMain->addLayout(loZip);
    loMain->addLayout(loPhone);

    groupbox->setLayout(loMain);
    groupbox->setFixedSize(700,500);

    return groupbox;
}

QGroupBox* Checkout::mkGrp_Card(){
    QGroupBox *groupbox = new QGroupBox(tr("PAYMENT INFO"));

    QHBoxLayout* loCard = new QHBoxLayout;
    loCard->addWidget(lbCard);
    loCard->addWidget(leCard);

    QHBoxLayout* loSvc = new QHBoxLayout;
    loSvc->addWidget(lbSvc);
    loSvc->addWidget(leSvc);

    QHBoxLayout* loExp = new QHBoxLayout;
    loExp->addWidget(lbExp);
    loExp->addWidget(leExp);

    QVBoxLayout* loMain = new QVBoxLayout;
    loMain->addLayout(loCard);
    loMain->addLayout(loSvc);
    loMain->addLayout(loExp);

    groupbox->setLayout(loMain);
    groupbox->setFixedSize(700,200);

    return groupbox;
}

QGroupBox* Checkout::mkGrp_Total(){
    QGroupBox *groupbox = new QGroupBox(tr("Total"));

    QVBoxLayout* loMain = new QVBoxLayout;
    loMain->addSpacerItem(spTotal);
    loMain->addWidget(btShop);
    loMain->addWidget(btCart);

    groupbox->setLayout(loMain);

    return groupbox;
}

void Checkout::goNext(){
    emit toFinish();
}

void Checkout::goShop(){
    emit toShop();
}

void Checkout::goBack(){
    emit toCart();
}

