#include "login.h"
#include <QtWidgets>


const int SCREEN_HEIGHT = 600;
const int SCREEN_WIDTH = 800;


Login::Login(QWidget *parent):
    QDialog(parent)
{
    setItems();
    setConnect();
    layItems();
}

void Login::setItems(){
    lbTitle = new QLabel(tr("Awesome Survey"));
    lbName = new QLabel(tr("Enter Username:"));
    lbPin = new QLabel(tr("Enter PIN:"));

    leName = new QLineEdit;
    lePin = new QLineEdit;

    btLogin = new QPushButton(tr("Login"));
    btQuit = new QPushButton(tr("Quit"));

    spTitle = new QSpacerItem(150,80);
    spName = new QSpacerItem(150,50);
    spPin = new QSpacerItem(150, 50);
    spBtn = new QSpacerItem(80, 100);
    spHorz = new QSpacerItem(200,SCREEN_HEIGHT);
    spVert = new QSpacerItem(SCREEN_WIDTH, 150);


}

void Login::setConnect(){
    connect(btQuit, SIGNAL(clicked()),
            this, SLOT(goExit()));
    connect(btLogin, SIGNAL(clicked()),
            this, SLOT(goSurvey()));

}

void Login::layItems(){
    //Title layout
    QHBoxLayout *layTitle = new QHBoxLayout;
    layTitle->addSpacerItem(spTitle);
    layTitle->addWidget(lbTitle);
    layTitle->addSpacerItem(spTitle);

    //Name layout
    QHBoxLayout *layNamelb = new QHBoxLayout;
    layNamelb->addSpacerItem(spName);
    layNamelb->addWidget(lbName);
    layNamelb->addSpacerItem(spName);

    QVBoxLayout *layName = new QVBoxLayout;
    layName->addLayout(layNamelb);
    layName->addWidget(leName);

    //Pin layout
    QHBoxLayout *layPinlb = new QHBoxLayout;
    layPinlb->addSpacerItem(spPin);
    layPinlb->addWidget(lbPin);
    layPinlb->addSpacerItem(spPin);

    QVBoxLayout *layPin = new QVBoxLayout;
    layPin->addLayout(layPinlb);
    layPin->addWidget(lePin);

    //Button layout
    QVBoxLayout *laybtns = new QVBoxLayout;
    laybtns->addWidget(btLogin);
    laybtns->addWidget(btQuit);

    QHBoxLayout *laybtn = new QHBoxLayout;
    laybtn->addSpacerItem(spBtn);
    laybtn->addLayout(laybtns);
    laybtn->addSpacerItem(spBtn);

    //Main layouts
    QVBoxLayout *middle = new QVBoxLayout;
    middle->addLayout(layTitle);
    middle->addLayout(layName);
    middle->addLayout(layPin);
    middle->addLayout(laybtn);

    QHBoxLayout *center = new QHBoxLayout;
    center->addSpacerItem(spHorz);
    center->addLayout(middle);
    center->addSpacerItem(spHorz);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addSpacerItem(spVert);
    mainLayout->addLayout(center);
    mainLayout->addSpacerItem(spVert);


    setLayout(mainLayout);
    setWindowTitle(tr("Survey - Login"));
    setFixedHeight(SCREEN_HEIGHT);
    setFixedWidth(SCREEN_WIDTH);
}

void Login::goSurvey(){
    emit toSurvey();
}

void Login::goExit(){
    emit toExit();
}
