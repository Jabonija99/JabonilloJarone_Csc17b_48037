#ifndef COMPLETE_H
#define COMPLETE_H

#include <QDialog>

class QLabel;
class QPushButton;
class QSpacerItem;


class Complete : public QDialog
{
private:
    void setItems();
    void setConnect();
    void layItems();

    QLabel *lbComplete;     //Completion text
    QPushButton *btExit;    //Exit button
    QPushButton *btStats;   //Stat button

    QSpacerItem *spLb;      //Label spacer
    QSpacerItem *spLb2;     //Label spacer 2
    QSpacerItem *spVert;    //Veritcal spacer
    QSpacerItem *spHorz;    //Horizontal spacer

public:
    Complete(QWidget *parent = 0);
};

#endif // COMPLETE_H
