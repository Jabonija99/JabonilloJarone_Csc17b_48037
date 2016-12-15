#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <QDialog>
#include <vector>

#include "item.h"

class QLabel;
class QScrollArea;
class QPushButton;
class QGroupBox;
class QSpacerItem;
class QLineEdit;

class Checkout :
        public QDialog
{
    Q_OBJECT
private:
    void setItems();
    void setConnect();
    void layItems();

    QPushButton* btShop;
    QPushButton* btCart;
    QPushButton* btSubmit;

    QSpacerItem* spInfo;
    QSpacerItem* spTotal;
    QSpacerItem* spBtn;

    QLineEdit* leName;
    QLineEdit* leAddr;
    QLineEdit* leCity;
    QLineEdit* leSt;
    QLineEdit* leZip;
    QLineEdit* lePhone;

    QLineEdit* leCard;
    QLineEdit* leSvc;
    QLineEdit* leExp;

    QLabel* lbInfoGen;
    QLabel* lbInfoCard;

    QLabel* lbName;
    QLabel* lbAddr;
    QLabel* lbCity;
    QLabel* lbSt;
    QLabel* lbZip;
    QLabel* lbPhone;

    QLabel* lbCard;
    QLabel* lbSvc;
    QLabel* lbExp;

    QScrollArea *infoBox;

    //Groupboxes
    QGroupBox *mkGrp_Scroll();
    QGroupBox *mkGrp_Info();
    QGroupBox *mkGrp_Card();
    QGroupBox *mkGrp_Total();

public:
    Checkout(QWidget* parent =0);
    ~Checkout();

public slots:
    void goNext();
    void goShop();
    void goBack();


signals:
    void toFinish();
    void toShop();
    void toCart();

};

#endif // CHECKOUT_H
