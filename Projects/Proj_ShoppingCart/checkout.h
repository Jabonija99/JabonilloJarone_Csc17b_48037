#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <QDialog>
#include "endtext.h"

class QPushButton;
class QLabel;
class QLineEdit;
class QPlainTextEdit;
class QSpacerItem;


class Checkout : public QDialog
{
    Q_OBJECT

    private:
        //Object functions
        void setItems();        //Create widget function
        void setConnect();      //Set connections
        void layItems();        //Layouts

        //Widgets
        QLabel *lbHeader;
        QLabel *lbItems;
        QLabel *lbInfo;

        QPushButton *submit;    //Submit Button
        QPushButton *cancel;    //Cancel Button

        QPlainTextEdit *tbPrice; //Price text box

        QSpacerItem *spHeadr;      //Header spacer
        QSpacerItem *spPrice;      //Price spacer
        QSpacerItem *spBtn;

        //End text window
        Endtext *txtTy;

    public:
        //Constructor
        Checkout(QWidget *parent=0);

    private slots:
        //Opens the complete window
        void complete();
        //Enable submit button
        void enableSubmit(const QString&text);
};

#endif // CHECKOUT_H
