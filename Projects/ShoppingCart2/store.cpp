#include "store.h"
#include <QtWidgets>

#include <QDebug>


const int SCREEN_HEIGHT = 740;
const int SCREEN_WIDTH = 1024;

Store::Store(QWidget *parent):
    QDialog(parent)
{
    setItems();     //Create items
    setConnect();   //Assign connections
    layItems();     //Render items
}

Store::~Store(){
    delete item1;
    delete item2;
    delete item3;
}

void Store::setItems(){
    item1 = new Item("tablet.txt");
    item2 = new Item("punchingbag.txt");
    item3 = new Item("hoop.txt");

    btCart = new QPushButton(tr("Cart"));
    btMore = new QPushButton(tr("More Info"));

    spOptions = new QSpacerItem(236,720);
    spItems = new QSpacerItem(50,240);

    itemBox = new QScrollArea;
    itemBox->setWidget(mkGrp_Scroll());
}

void Store::setConnect(){

}


void Store::layItems(){
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(mkGrp_Options());
    mainLayout->addWidget(itemBox);

    setLayout(mainLayout);

    setFixedHeight(SCREEN_HEIGHT);
    setFixedWidth(SCREEN_WIDTH);
}

QGroupBox* Store::mkGrp_Scroll(){
    QGroupBox *groupbox = new QGroupBox();

    QVBoxLayout *items = new QVBoxLayout;
    items->addWidget(mkGrp_Item(item1));
    items->addWidget(mkGrp_Item(item2));
    items->addWidget(mkGrp_Item(item3));

    groupbox->setLayout(items);

    return groupbox;
}

QGroupBox* Store::mkGrp_Options(){
    QGroupBox *groupbox = new QGroupBox;

    QVBoxLayout* loMain = new QVBoxLayout;
    loMain->addSpacerItem(spOptions);

    groupbox->setLayout(loMain);

    return groupbox;
}

QGroupBox* Store::mkGrp_Item(Item* item){
    //Groupbox for items
    QGroupBox *groupbox = new QGroupBox;

    //Create labels
    QLabel *name = new QLabel(item->getName());
    QLabel *price = new QLabel(item->getPrice());

    //Load image
    QLabel *img = new QLabel;

    QPixmap pxImg(":imgs/deps/"+item->getImg());

    //If image doesnt load
    if(pxImg.isNull())
        qDebug() <<"Pixmap is null!";
    else{
        //Scale and set image
        pxImg = pxImg.scaled(240, 240, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        img->setPixmap(pxImg);
    }

    //Set items onto layouts
    QVBoxLayout *loLeft = new QVBoxLayout;
    loLeft->addWidget(name);
    loLeft->addWidget(price);
    loLeft->addStretch(2);

    QVBoxLayout *loRight = new QVBoxLayout;
    loRight->addStretch(1);
    loRight->addWidget(btMore);
    loRight->addStretch(1);

    QHBoxLayout *loMain = new QHBoxLayout;
    loMain->addWidget(img);
    loMain->addLayout(loLeft);
    loMain->addSpacerItem(spItems);
    loMain->addLayout(loRight);
    loMain->addSpacerItem(spItems);

    groupbox->setLayout(loMain);

    return groupbox;
}

