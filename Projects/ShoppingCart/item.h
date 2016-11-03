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

    QPixmap pxImage;
    QLabel *lbImage;
    QLabel *lbName;
    QLabel *lbPrice;
    QLabel *lbShip;
    QLabel *lbDesc;

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

public slots:
    void moreInfo();
};

#endif // ITEM_H
