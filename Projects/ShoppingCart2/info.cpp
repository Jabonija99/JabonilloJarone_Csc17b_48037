#include "info.h"

#include <QtWidgets>
#include <QDebug>

const int SCREEN_HEIGHT = 740;
const int SCREEN_WIDTH = 1024;

Info::Info(QWidget *parent) :
    QDialog(parent)
{
    setItems();
    setConnect();
    layItems();
}

Info::~Info(){
    delete item;
}

void Info::setItems(){
    item = new Item();

    name = new QLabel(tr("<b>Name:</b> ") + item->getName());
    price = new QLabel(tr("<b>Price:</b> ") + item->getPrice());
    ship = new QLabel(tr("<b>Shipping:</b> ") + item->getShip());
    desc = new QLabel(tr("<b>Description:</b>\n")+item->getDesc());

    img = new QLabel;

    btCart = new QPushButton("Add to Cart");
    btShop = new QPushButton("Return to Shop");
}

void Info::setConnect(){
    connect(btCart, SIGNAL(clicked()),
            this, SLOT(loadItem()));
    connect(btShop, SIGNAL(clicked()),
            this, SLOT(goBack()));
}

void Info::layItems(){
    QVBoxLayout *loMain = new QVBoxLayout;
    loMain->addWidget(mkGrp_Item());
    loMain->addWidget(mkGrp_Info());

    setLayout(loMain);

    setFixedHeight(SCREEN_HEIGHT);
    setFixedWidth(SCREEN_WIDTH);
}

void Info::load(Item* shopItem){

    if(shopItem == NULL){
        qDebug() <<"No shop item";
    }
    else{
        item->load(shopItem->getfile());

        //Load labels
        /*
        name = new QLabel(item->getName());
        price = new QLabel(item->getPrice());
        ship = new QLabel(item->getShip());
        desc = new QLabel(item->getDesc());
        */

        name->setText(tr("<b>Name:</b> ")+ item->getName());
        price->setText(tr("<b>Price:</b> ")+ item->getPrice());
        ship->setText(tr("<b>Shipping:</b> ")+ item->getShip());
        desc->setText(tr("<b>Description:</b>\n")+ item->getDesc());

        //Load image
        //img = new QLabel;

        QPixmap pxImg(":imgs/deps/"+item->getImg());

        //If image doesnt load
        if(pxImg.isNull())
            qDebug() <<"Pixmap is null!";
        else{
            //Scale and set image
            pxImg = pxImg.scaled(240, 240, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            img->setPixmap(pxImg);
        }
    }
}

QGroupBox* Info::mkGrp_Item(){
    QGroupBox *groupbox = new QGroupBox();

    QVBoxLayout *loLeft = new QVBoxLayout;
    loLeft->addWidget(img);

    QVBoxLayout *loRight = new QVBoxLayout;
    loRight->addStretch(1);
    loRight->addWidget(btCart);
    loRight->addWidget(btShop);
    loRight->addStretch(1);

    QHBoxLayout *loMain = new QHBoxLayout;
    loMain->addLayout(loLeft);
    loMain->addStretch(1);
    loMain->addLayout(loRight);

    groupbox->setLayout(loMain);

    return groupbox;
}

QGroupBox* Info::mkGrp_Info(){
    QGroupBox *groupbox = new QGroupBox;

    QVBoxLayout *loMain = new QVBoxLayout;
    loMain->addWidget(name);
    loMain->addWidget(price);
    loMain->addWidget(ship);
    loMain->addWidget(desc);
    loMain->addStretch(1);

    groupbox->setLayout(loMain);

    return groupbox;
}

void Info::loadItem(){
    emit sendItem(item);
    emit toCart();
}

void Info::goBack(){
    emit toShop();
}
