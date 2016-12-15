#ifndef CART_H
#define CART_H

#include <QDialog>
#include <vector>

#include "item.h"

class QLabel;
class QScrollArea;
class QPushButton;
class QGroupBox;
class QSpacerItem;
class QHBoxLayout;

class Cart :
        public QDialog
{
    Q_OBJECT
private:
    void setItems();
    void setConnect();
    void layItems();

    int itemNum;
    std::vector<Item*> items;
    std::vector<QPushButton*> btnRemove;
    std::vector<QLabel*> lbNames;
    std::vector<QLabel*> lbImgs;

    QPushButton* btShop;
    QPushButton* btCheck;

    //Scroll Area
    QScrollArea *itemBox;

    //Groupboxes
    QGroupBox *mkGrp_Scroll();
    QGroupBox *mkGrp_Total();
    QGroupBox *mkGrp_Item(Item*, int);

    QSpacerItem* spTotal;
    QSpacerItem* spItems;

    QHBoxLayout* mainLayout;


public:
    Cart(QWidget* parent =0);
    ~Cart();

public slots:
    void add(Item*);
    void goNext();
    void goBack();

signals:
    void toCheck();
    void toShop();
};

#endif // CART_H