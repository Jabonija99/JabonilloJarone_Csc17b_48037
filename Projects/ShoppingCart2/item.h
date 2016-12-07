#ifndef ITEM_H
#define ITEM_H

#include <QString>

class Item
{
private:
    QString img;
    QString name;
    QString price;
    QString ship;
    QString desc;
    QString itemfile;

public:
    Item();
    Item(QString);

    //Load item
    bool load(QString);

    QString getImg(){return img;}
    QString getName(){return name;}
    QString getPrice(){return price;}
    QString getShip(){return ship;}
    QString getDesc(){return desc;}
    QString getfile(){return itemfile;}
};

#endif // ITEM_H
