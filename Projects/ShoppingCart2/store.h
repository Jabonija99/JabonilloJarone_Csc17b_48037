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

    //Scroll Area for items
    QScrollArea *itemBox;

    //Groupboxes
    QGroupBox *mkGrp_Scroll();
    QGroupBox *mkGrp_Options();
    QGroupBox *mkGrp_Item(Item*);

    QSpacerItem *spOptions;
    QSpacerItem *spItems;


public:

    Store(QWidget *parent=0);
    ~Store();

public slots:
signals:


};

#endif // STORE_H
