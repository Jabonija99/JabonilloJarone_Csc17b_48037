#ifndef STORE_H
#define STORE_H

#include <QDialog>
#include <vector>

#include "item.h"

class QLabel;
class QScrollArea;
class QPushButton;
class QGroupBox;
class QSpacerItem;

class Store :
        public QDialog
{
    Q_OBJECT
private:
    void setItems();
    void setConnect();
    void layItems();

    Item *item1;
    Item *item2;
    Item *item3;

    QPushButton* btCart;
    QPushButton* btMore;
    std::vector<QPushButton*> buttons;

    //Scroll Area for items
    QScrollArea *itemBox;

    //Groupboxes
    QGroupBox *mkGrp_Scroll();
    QGroupBox *mkGrp_Options();
    QGroupBox *mkGrp_Item(Item*, int);

    QSpacerItem *spOptions;
    QSpacerItem *spItems;


public:
    Store(QWidget *parent=0);
    ~Store();

public slots:
    void loadItem1();
    void loadItem2();
    void loadItem3();
    void goCart();

signals:
    void sendItem(Item* item);
    void toInfo();
    void toCart();

};

#endif // STORE_H
