#ifndef INFO_H
#define INFO_H

#include <QDialog>

#include "item.h"

class QLabel;
class QPushButton;
class QGroupBox;
class QSpacerItem;

class Info : public QDialog
{
    Q_OBJECT
private:
    void setItems();
    void setConnect();
    void layItems();

    Item *item;

    QLabel *name;
    QLabel *price;
    QLabel *ship;
    QLabel *desc;
    QLabel *img;

    QPushButton *btCart;
    QPushButton *btShop;

    QGroupBox *mkGrp_Item();
    QGroupBox *mkGrp_Info();

public:
    Info(QWidget *parent=0);
    ~Info();

public slots:
    void load(Item *shopItem);
    void loadItem();
    void goBack();

signals:
    void sendItem(Item*);
    void toShop();
    void toCart();
};

#endif // INFO_H
