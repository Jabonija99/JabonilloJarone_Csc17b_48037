#ifndef ITEM_H
#define ITEM_H

#include <QDialog>
#include <QString>

class QLabel;
class QPushButton;
class QGroupBox;
class QFile;
class QSpacerItem;
class QPixmap;
class QScrollArea;

class Item : public QDialog
{
    Q_OBJECT
private:
    void setItems(QString);
    void setConnect();
    void layItems();

    /*
    float price;      //item price
    float ship;       //item shipping price
    QString name;   //item name
    */

    QPixmap pxImage;//item image
    QLabel *lbImage;//Label for image
    QLabel *lbName; //Name label
    QLabel *lbPrice;//Price label
    QLabel *lbShip; //Shipping price label
    QLabel *lbDesc; //description label

    QPushButton *btAddCart;
    QPushButton *btMore;

    QSpacerItem *spItems;

    QScrollArea *scrollArea;

    QGroupBox *grpbox;
    QGroupBox *mkGrp_Item();
    QGroupBox *mkGrp_More();

    bool error;
    bool info;

public:
    Item(QWidget *parent = 0);
    Item(QString, QWidget *parent = 0 );
/*
    int getPrice(){return price;}
    int getShip(){return ship;}
    QString getName(){return name;}
*/
public slots:
    void moreInfo();
};

#endif // ITEM_H
