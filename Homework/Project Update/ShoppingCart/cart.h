#ifndef CART_H
#define CART_H

#include <QDialog>
#include "item.h"

class QPushButton;
class QLabel;
class QScrollArea;
class QGroupBox;
class QSpacerItem;

class Cart : public QDialog
{
    Q_OBJECT
private:
    void setItems();
    void setConnect();
    void layItems();

    Item* item1;
    Item* item2;
    Item* item3;

    QLabel *lbPrice;    //Price
    QLabel *lbShip;     //Shipping cost
    QLabel *lbTotal;    //Total price
    QLabel *lbSeparate; //Separator label

    QScrollArea *saItems;

    QSpacerItem *spSummary;

    QPushButton *btCheckout;
    QPushButton *btRemove;

    QGroupBox *mkGrp_Summary();
    QGroupBox *mkGrp_Scroll();
    QGroupBox *mkGrp_Item(Item*);

public:
    Cart(QWidget *parent =0);
};

#endif // CART_H
