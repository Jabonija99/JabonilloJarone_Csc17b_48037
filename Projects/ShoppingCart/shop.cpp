#include "shop.h"
#include <QtWidgets>

const int SCREEN_HEIGHT = 740;
const int SCREEN_WIDTH = 1024;

Shop::Shop(QWidget *parent) :
    QDialog(parent)
{
    setItems();
    setConnect();
    layItems();
}

void Shop::setItems(){
    item1 = new Item("tablet.txt");
    item2 = new Item("punchingbag.txt");
    item3 = new Item("hoop.txt");

    lbItemN = new QLabel("Total Items: 3");
    lbTotal = new QLabel("Total Cost: $49.99");

    spCart = new QSpacerItem(200,50);

    btCart = new QPushButton("Cart");

    itemBox = new QScrollArea;
    itemBox->setWidget(mkGrp_Scroll());

}

void Shop::setConnect(){
    connect(item1, SIGNAL(btnPressed(bool)),
            this, SLOT(readbtn(bool)));
    connect(item2, SIGNAL(btnPressed(bool)),
            this, SLOT(readbtn(bool)));
    connect(item3, SIGNAL(btnPressed(bool)),
            this, SLOT(readbtn(bool)));

    connect(this, SIGNAL(btClicked(bool)),
            item1, SLOT(moreinfo()));
    connect(this, SIGNAL(btClicked(bool)),
            item2, SLOT(moreinfo()));
    connect(this, SIGNAL(btClicked(bool)),
            item3, SLOT(moreinfo()));
}

void Shop::layItems(){
    QHBoxLayout *mainlayout = new QHBoxLayout;
    mainlayout->addWidget(itemBox);
    mainlayout->addWidget(mkGrp_Cart());

    setLayout(mainlayout);

    setFixedHeight(SCREEN_HEIGHT);
    setFixedWidth(SCREEN_WIDTH);

}

QGroupBox* Shop::mkGrp_Cart(){
    QGroupBox *grpbox = new QGroupBox("Summary");

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(lbItemN);
    vbox->addWidget(lbTotal);
    vbox->addWidget(btCart);
    vbox->addSpacerItem(spCart);
    vbox->addStretch(2);

    grpbox->setLayout(vbox);

    return grpbox;
}

QGroupBox* Shop::mkGrp_Scroll(){
    QGroupBox *groupbox = new QGroupBox();

    QVBoxLayout *items = new QVBoxLayout;
    items->addWidget(mkGrp_Item(item1));
    items->addWidget(mkGrp_Item(item2));
    items->addWidget(mkGrp_Item(item3));

    groupbox->setLayout(items);


    return groupbox;
}

QGroupBox* Shop::mkGrp_Item(Item* item){
    QGroupBox *groupbox = new QGroupBox();

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(item);

    groupbox->setLayout(vbox);

    return groupbox;
}

void Shop::readbtn(bool flag){
    emit btClicked(true);
}
