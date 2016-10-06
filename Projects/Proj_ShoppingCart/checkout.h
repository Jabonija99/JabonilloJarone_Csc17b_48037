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
        void setItems();        //Create widget function
        void setConnect();      //Set connections
        void layItems();        //Layouts

        //Widgets
        QPushButton *submit;    //Submit Button
        QPushButton *cancel;    //Cancel Button

        QPlainTextEdit *display; //Checkout display

        QSpacerItem *spacer;        //LayoutSpacer

    public:
        //Constructor
        Checkout(QWidget *parent=0);

    private slots:
        //Pulls text from line editors
        void pullText();
        //Enable submit button
        void enableSubmit(const QString&text);
};

#endif // CHECKOUT_H
