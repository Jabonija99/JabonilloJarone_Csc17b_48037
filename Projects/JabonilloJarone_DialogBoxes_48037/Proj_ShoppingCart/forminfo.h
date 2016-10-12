#ifndef FORMINFO_H
#define FORMINFO_H

#include <QDialog>
#include "checkout.h"

class QPushButton;
class QLabel;
class QLineEdit;
class QSpacerItem;
class QComboBox;

class FormInfo : public QDialog
{
    Q_OBJECT

    private:
        Checkout *wCheckout;    //Checkout window

        void setItems();
        void setConnect();
        void layItems();

        QLabel *lbName;         //Name Label
        QLabel *lbAddrs;        //Address Label
        QLabel *lbPhone;        //Phone Label

        QComboBox *cbGender;    //Gender type

        QLineEdit *leName;      //Name textbox
        QLineEdit *leAddrs;     //Address textbox
        QLineEdit *lePhone;     //Phone textbox

        QPushButton *submit;    //Submit button
        QPushButton *cancel;    //Cancel button

        QSpacerItem *spInfo;    //Info Spacer
        QSpacerItem *spInfo2;   //Info Spacer 2
        QSpacerItem *spInfo3;
        QSpacerItem *spBtn;     //Button spacer

    public:
        FormInfo(QWidget *parent = 0);

    private slots:
        void openCheckout();
        void enableBtn(const QString&);

};

#endif // FORMINFO_H
