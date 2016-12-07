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
    item1 = NULL;
    delete item1;

    item2 = NULL;
    delete item2;

    item3 = NULL;
    delete item3;
}

void Store::setItems(){
    item1 = new Item("tablet.txt");
    item2 = new Item("punchingbag.txt");
    item3 = new Item("hoop.txt");

    btCart = new QPushButton(tr("Cart"));
    btCart->setFixedHeight(30);

    btMore = new QPushButton(tr("More Info"));
    for(int i = 0; i < 3; i++){
        buttons.push_back(new QPushButton(tr("MoreInfo")));
        buttons[i]->setFixedHeight(30);
        buttons[i]->setFixedWidth(130);
    }


    spOptions = new QSpacerItem(236,720);
    spItems = new QSpacerItem(60,180);

    itemBox = new QScrollArea;
    itemBox->setWidget(mkGrp_Scroll());
}

void Store::setConnect(){
    connect(buttons.at(0), SIGNAL(clicked()),
            this, SLOT(loadItem1()));
    connect(buttons.at(1), SIGNAL(clicked()),
            this, SLOT(loadItem2()));
    connect(buttons.at(2), SIGNAL(clicked()),
            this, SLOT(loadItem3()));
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
    items->addWidget(mkGrp_Item(item1,0));
    items->addWidget(mkGrp_Item(item2,1));
    items->addWidget(mkGrp_Item(item3,2));

    groupbox->setLayout(items);

    return groupbox;
}

QGroupBox* Store::mkGrp_Options(){
    QGroupBox *groupbox = new QGroupBox;

    QVBoxLayout* loMain = new QVBoxLayout;
    loMain->addWidget(btCart);
    loMain->addSpacerItem(spOptions);

    groupbox->setLayout(loMain);

    return groupbox;
}

QGroupBox* Store::mkGrp_Item(Item* item,int slot){
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
    loRight->addWidget(buttons[slot]);
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

void Store::loadItem1(){
    emit sendItem(item1);
}

void Store::loadItem2(){
    emit sendItem(item2);
}

void Store::loadItem3(){
    emit sendItem(item3);
}

