#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <QDialog>

class QPushButton;
class QLabel;
class QLineEdit;

class Checkout : public QDialog
{
    Q_OBJECT

    private:
        //Widgets
        QPushButton * submit;   //Submit Button
        QLabel *lbName;         //Name Label
        QLabel *lbAddrs;        //Address Label
        QLabel *lbPhone;        //Phone Label
        QLineEdit *leName;      //Name textbox
        QLineEdit *leAddrs;     //Address textbox
        QLineEdit *lePhone;     //Phone textbox
    public:
        Checkout(QWidget *parent=0);

    signals:

    private slots:
        void enableSubmit(const QString&text);
};

#endif // CHECKOUT_H
