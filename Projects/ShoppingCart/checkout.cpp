#include "checkout.h"
#include <QtWidgets>


const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 800;

Checkout::Checkout()
{
    setItems();
    setConnect();
    layItems();
}

void Checkout::setItems(){
    lbHeader = new QLabel(tr("Enter Information"));
    lbName = new QLabel(tr("Name:"));
    lbAddr = new QLabel(tr("Address:"));
    lbPhone = new QLabel(tr("Phone:"));

    leName = new QLineEdit;
    leAddr = new QLineEdit;
    lePhone = new QLineEdit;

    chkterms = new QCheckBox(tr("I agree with the terms."));

    btSubmit = new QPushButton("Submit");
    btSubmit->setDefault(true);
    btSubmit->setEnabled(false);
}

void Checkout::setConnect(){
    connect(chkterms, SIGNAL(stateChanged(int)),
            this,SLOT(enableBtn()));
}

void Checkout::layItems(){
    QGridLayout *gridlayout = new QGridLayout;
    gridlayout->addWidget(lbHeader,0,0);
    gridlayout->addWidget(lbName,1,0);
    gridlayout->addWidget(leName,1,1);
    gridlayout->addWidget(lbAddr,2,0);
    gridlayout->addWidget(leAddr,2,1);
    gridlayout->addWidget(lbPhone,3,0);
    gridlayout->addWidget(lePhone,3,1);
    gridlayout->addWidget(chkterms,4,1);
    gridlayout->addWidget(btSubmit,5,1);

    setLayout(gridlayout);
    setFixedHeight(SCREEN_HEIGHT);
    setFixedWidth(SCREEN_WIDTH);
}

void Checkout::enableBtn(){
    btSubmit->setEnabled(true);
}

void Checkout::disablBtn(){
    btSubmit->setEnabled(false);
}
