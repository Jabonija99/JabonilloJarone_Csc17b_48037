#ifndef COMPLETE_H
#define COMPLETE_H

#include <QDialog>

class QLabel;
class QPushButton;
class QGroupBox;
class QSpacerItem;

class Complete :
        public QDialog
{
    Q_OBJECT
private:
    void setItems();
    void setConnect();
    void layItems();

    QPushButton* btClose;
    QPushButton* btShop;

    QLabel* lbThanks;
    QLabel* lbMsg;

    QSpacerItem* spMsg1;
    QSpacerItem* spMsg2;

    QSpacerItem* spBtn;

public:
    Complete(QWidget *parent=0);
    ~Complete();

public slots:
    void goShop();
    void goExit();

signals:
    void toShop();
    void toExit();

};

#endif // COMPLETE_H
