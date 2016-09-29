#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <QDialog>

class QPushButton;
class QLabel;
class QLineEdit;
class QPlainTextEdit;
class QSpacerItem;

class Checkout : public QDialog
{
    Q_OBJECT

    private:
        //Widgets
        QPushButton *submit;    //Submit Button
        QPushButton *cancel;    //Cancel Button

        QLabel *lbName;         //Name Label
        QLabel *lbAddrs;        //Address Label
        QLabel *lbPhone;        //Phone Label

        QLineEdit *leName;      //Name textbox
        QLineEdit *leAddrs;     //Address textbox
        QLineEdit *lePhone;     //Phone textbox

        QPlainTextEdit *display; //Checkout display

        QSpacerItem *spacer;        //LayoutSpacer

    public:
        //Constructor
        Checkout(QWidget *parent=0);
    signals:

    private slots:
        //Pulls text from line editors
        void pullText();
        //Enable submit button
        void enableSubmit(const QString&text);
};

#endif // CHECKOUT_H
