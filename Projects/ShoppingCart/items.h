#ifndef ITEMS_H
#define ITEMS_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QString>

class Items :public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    QString filename;
    QString img;
    QString name;
    QString price;
    QString ship;
    QString desc;

public:
    Items(QGraphicsItem *parent =0);
    Items(QString, QGraphicsItem *parent=0);

    //Load item
    bool load(QString);

    QString getImg(){return img;}
    QString getName(){return name;}
    QString getPrice(){return price;}
    QString getShip(){return ship;}
    QString getDesc(){return desc;}

};

#endif // ITEMS_H
