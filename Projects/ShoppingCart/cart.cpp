#include "cart.h"
#include <QtWidgets>


const int SCREEN_HEIGHT = 750;
const int SCREEN_WIDTH = 1024;

Cart::Cart(QWidget *parent):
    QDialog(parent)
{
    setItems();
    setConnect();
    layItems();
}

void Cart::setItems(){
    item1 = new Item(tr("punchingbag.txt"));
    item2 = new Item(tr("hoop.txt"));
    item3 = new Item(tr("tablet.txt"));

    lbPrice = new QLabel(tr("$100.98"));
    lbShip = new QLabel(tr("$10.00"));
    lbTotal = new QLabel(tr("$110.98"));
    lbSeparate = new QLabel(tr("============="));

    spSummary  = new QSpacerItem(200,50);

    saItems = new QScrollArea;
    saItems->setWidget(mkGrp_Scroll());

    btCheckout = new QPushButton("Checkout");
    btRemove = new QPushButton("Remove");
}

void Cart::setConnect(){


}

void Cart::layItems(){
    QHBoxLayout *mainlayout = new QHBoxLayout;
    mainlayout->addWidget(saItems);
    mainlayout->addWidget(mkGrp_Summary());

    setLayout(mainlayout);

    setFixedHeight(SCREEN_HEIGHT);
    setFixedWidth(SCREEN_WIDTH);

}

QGroupBox* Cart::mkGrp_Summary(){
    QGroupBox *groupbox = new QGroupBox("Summary");

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(lbPrice);
    vbox->addWidget(lbShip);
    vbox->addWidget(lbSeparate);
    vbox->addWidget(lbTotal);
    vbox->addSpacerItem(spSummary);
    vbox->addWidget(btCheckout);
    vbox->addStretch(2);

    groupbox->setLayout(vbox);

    return groupbox;
}

QGroupBox* Cart::mkGrp_Scroll(){
    QGroupBox *groupbox = new QGroupBox("Cart");

    QVBoxLayout *vbox = new QVBoxLayout;

    vbox->addWidget(mkGrp_Item(item1));
    vbox->addWidget(mkGrp_Item(item2));
    vbox->addWidget(mkGrp_Item(item3));

    groupbox->setLayout(vbox);

    return groupbox;

}

QGroupBox* Cart::mkGrp_Item(Item* item){
    QGroupBox *groupbox = new QGroupBox();

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(item);

    groupbox->setLayout(vbox);

    return groupbox;
}
