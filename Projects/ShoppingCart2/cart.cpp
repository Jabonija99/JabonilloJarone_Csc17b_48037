#include "cart.h"

#include <QtWidgets>
#include <QDebug>


const int SCREEN_HEIGHT = 740;
const int SCREEN_WIDTH = 1024;

Cart::Cart(QWidget* parent) :
    QDialog(parent)
{
    setItems();
    setConnect();
    layItems();
}

Cart::~Cart(){

}

void Cart::setItems(){
    itemNum = 0;
    for(int i =0; i < 10; i++){
        items.push_back(new Item());
    }


    btShop = new QPushButton("Shop");
    btCheck = new QPushButton("Check");
    for(int i =0; i < 10; i++){
        btnRemove.push_back(new QPushButton(tr("Remove")));
        btnRemove[i]->setFixedHeight(30);
        btnRemove[i]->setFixedWidth(130);

        lbNames.push_back(new QLabel);
        lbImgs.push_back(new QLabel);
    }


    spTotal = new QSpacerItem(236, 720);
    spItems = new QSpacerItem(60, 180);

    itemBox = new QScrollArea;
    itemBox->setWidget(mkGrp_Scroll());
}

void Cart::setConnect(){
    connect(btShop, SIGNAL(clicked()),
            this, SLOT(goBack()));
    connect(btCheck, SIGNAL(clicked()),
            this, SLOT(goNext()));
}

void Cart::layItems(){
    mainLayout = new QHBoxLayout;
    mainLayout->addWidget(itemBox);
    mainLayout->addWidget(mkGrp_Total());

    setLayout(mainLayout);

    setFixedHeight(SCREEN_HEIGHT);
    setFixedWidth(SCREEN_WIDTH);
}

QGroupBox* Cart::mkGrp_Scroll(){
    QGroupBox *groupbox = new QGroupBox();

    QVBoxLayout *loItems = new QVBoxLayout;

    for(int i =0; i < items.size() ; i++){
        loItems->addWidget(mkGrp_Item(items[i], i));
    }

    groupbox->setLayout(loItems);

    return groupbox;
}

QGroupBox* Cart::mkGrp_Total(){
    QGroupBox *groupbox = new QGroupBox(tr("Total"));

    QVBoxLayout* loMain = new QVBoxLayout;
    loMain->addSpacerItem(spTotal);
    loMain->addWidget(btShop);
    loMain->addWidget(btCheck);

    groupbox->setLayout(loMain);

    return groupbox;
}

QGroupBox* Cart::mkGrp_Item(Item* item,int slot){
    //Groupbox for items
    QGroupBox *groupbox = new QGroupBox;

    //Create labels
    lbNames[slot]->setText(item->getName());
    QLabel *price = new QLabel(item->getPrice());

    //Load image
    //QLabel *img = new QLabel;

    QPixmap pxImg(":imgs/deps/"+item->getImg());

    //If image doesnt load
    if(pxImg.isNull())
        qDebug() <<"Pixmap is null!";
    else{
        //Scale and set image
        pxImg = pxImg.scaled(240, 240, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        lbImgs[slot]->setPixmap(pxImg);
    }

    //Set items onto layouts
    QVBoxLayout *loLeft = new QVBoxLayout;
    loLeft->addWidget(lbNames[slot]);
    loLeft->addWidget(price);
    loLeft->addStretch(2);

    QVBoxLayout *loRight = new QVBoxLayout;
    loRight->addStretch(1);
    loRight->addWidget(btnRemove[slot]);
    loRight->addStretch(1);

    QHBoxLayout *loMain = new QHBoxLayout;
    loMain->addWidget(lbImgs[slot]);
    loMain->addLayout(loLeft);
    loMain->addSpacerItem(spItems);
    loMain->addLayout(loRight);
    loMain->addSpacerItem(spItems);

    groupbox->setLayout(loMain);
    groupbox->setFixedHeight(280);
    groupbox->setFixedWidth(720);

    return groupbox;
}

void Cart::add(Item* item){
    if(item == NULL){
        qDebug() <<"No item detected.";
    }
    else{
        delete items[itemNum];
        items[itemNum]= new Item(item->getfile());
        lbNames[itemNum]->setText(item->getName());

        QPixmap pxImg(":/imgs/deps/"+item->getImg());

        //If image doesnt load
        if(pxImg.isNull())
            qDebug() <<"Pixmap is null!";
        else{
            //Scale and set image
            pxImg = pxImg.scaled(240, 240, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            lbImgs[itemNum]->setPixmap(pxImg);
        }


        itemNum++;
    }
}

void Cart::goNext(){
    emit toCheck();
}

void Cart::goBack(){
    emit toShop();
}


