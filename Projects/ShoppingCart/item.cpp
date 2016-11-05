#include "item.h"
#include <QtWidgets>
#include <QDebug>

const int SCREEN_HEIGHT = 480;
const int SCREEN_WIDTH = 680;

Item::Item(QString dir, QWidget *parent):
    QDialog(parent)
{
    error= false;
    info = false;
    setItems(dir);
    setConnect();
    layItems();
}
void Item::setItems(QString dir){
    //Create item

    QFile file(":inv/"+dir);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        qDebug() << "File failed to open!\n";
        error = true;
        return;
    }
    else{


        QTextStream in(&file);
        QString img = in.readLine();

        /*
        name = in.readLine();
        price = in.readLine().toFloat();
        ship =  in.readLine().toFloat();
        */

        QString name = in.readLine();
        QString price = in.readLine();
        QString ship =  in.readLine();
        QString desc = in.readLine();


        lbImage = new QLabel;
        pxImage = QPixmap(":images/"+img);

        if(pxImage.isNull())
                qDebug() <<"Pixmap is null!\n";
        else {
            qDebug() <<"Image load successful!\n";
            pxImage = pxImage.scaled(240, 240, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            lbImage->setPixmap(pxImage);
        }

        lbImage->setFixedHeight(240);
        lbImage->setFixedWidth(240);

        lbName = new QLabel(name);
        lbPrice = new QLabel(price);
        if(ship>0)
            lbShip = new QLabel(tr("Shipping:")+ship);
        else
            lbShip = new QLabel(tr("Free Shipping!"));
        lbDesc = new QLabel(desc);
    }


    btAddCart = new QPushButton(tr("Add to Cart"));
    btMore = new QPushButton(tr("More Info"));

    spItems = new QSpacerItem(SCREEN_WIDTH, 70);

    grpbox = mkGrp_More();
    grpbox->hide();
}

void Item::setConnect(){
    connect(btMore, SIGNAL(clicked()),
            this, SLOT(moreInfo()));
}

void Item::layItems(){

    if(error){
        qDebug() <<"No item loaded!\n";
        return;
    }
    else{
        QVBoxLayout *loBtn = new QVBoxLayout;
        loBtn->addWidget(btAddCart);
        loBtn->addWidget(btMore);

        QHBoxLayout *loTop = new QHBoxLayout;
        loTop->addWidget(lbImage);
        loTop->addWidget(mkGrp_Item());
        loTop->addLayout(loBtn);

        QVBoxLayout *mainlayout = new QVBoxLayout;
        mainlayout->addLayout(loTop);
        mainlayout->addSpacerItem(spItems);
        mainlayout->addWidget(grpbox);



        setLayout(mainlayout);
        //setFixedHeight(SCREEN_HEIGHT);
        //setFixedWidth(SCREEN_WIDTH);
    }

}

QGroupBox *Item::mkGrp_Item(){
    QGroupBox *groupbox = new QGroupBox();

    QVBoxLayout *loInfo = new QVBoxLayout;
    loInfo->addWidget(lbName);
    loInfo->addWidget(lbPrice);
    loInfo->addWidget(lbShip);
    loInfo->addStretch(1);

    groupbox->setLayout(loInfo);

    return groupbox;
}

QGroupBox *Item::mkGrp_More(){
    QGroupBox *groupbox = new QGroupBox();

    QVBoxLayout *vbox = new QVBoxLayout;
    vbox->addWidget(lbDesc);
    vbox->addStretch(2);

    groupbox->setLayout(vbox);

    return groupbox;
}

void Item::moreInfo(){
    if(!info){
        grpbox->show();
        info = true;
        emit btnPressed(info);
    }
    else{
        grpbox->hide();
        info = false;
        emit btnPressed(info);
    }
}
