#ifndef SHOP_H
#define SHOP_H

#include <QDialog>
#include "item.h"


class QLabel;
class QScrollArea;
class QPushButton;
class QGroupBox;
class QSpacerItem;

class Shop : public QDialog
{
    Q_OBJECT
private:
    void setItems();
    void setConnect();
    void layItems();

    Item *item1;
    Item *item2;
    Item *item3;

    QLabel  *lbItemN;   //number of items label
    QLabel *lbTotal;    //Total price in cart

    QSpacerItem *spCart;

    QPushButton *btCart;    //Cart button

    QScrollArea *itemBox;
    QGroupBox *mkGrp_Cart();
    QGroupBox *mkGrp_Scroll();
    QGroupBox *mkGrp_Item(Item*);


public:
    Shop(QWidget*parent=0);
};

#endif // SHOP_H
