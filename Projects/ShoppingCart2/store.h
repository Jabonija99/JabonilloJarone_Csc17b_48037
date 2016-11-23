#ifndef STORE_H
#define STORE_H

#include <QDialog>
#include <vector>

#include "item.h"

class QLabel;
class QScrollArea;
class QPushButton;
class QGroupbox;
class QSpacerItem;

class Store :
        public QDialog
{
    Q_OBJECT
private:
    void setItems();
    void setConnect();
    void layItems();

    //Vectors for item
    std::vector<Item*> inv;

    QPushButton *btMore;
    QPushButton *btAddCart;

    QScrollArea *itemBox;
    QGroupbox *mkGrp_Cart();
    QGroupbox *mkGrp_Scroll();
    QGroupbox *mkGrp_Item(Item*);


public:
    Store(QWidget *parent=0);

public slots:
signals:


};

#endif // STORE_H
