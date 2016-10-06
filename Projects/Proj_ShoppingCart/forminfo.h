#ifndef FORMINFO_H
#define FORMINFO_H

#include <QDialog>

class QPushButton;
class QLabel;
class QLineEdit;
class QSpacerItem;

class FormInfo : public QDialog
{
    Q_OBJECT

    private:
        void setItems();
        void setConnect();
        void layItems();

        QLabel *lbName;         //Name Label
        QLabel *lbAddrs;        //Address Label
        QLabel *lbPhone;        //Phone Label

        QLineEdit *leName;      //Name textbox
        QLineEdit *leAddrs;     //Address textbox
        QLineEdit *lePhone;     //Phone textbox

        QPushButton *submit;    //Submit button
        QPushButton *cancel;    //Cancel button

        QSpacerItem *spacer;    //Spacer item

    public:
        FormInfo(QWidget *parent = 0);

    private slots:
        void openCheckout();
        void enableBtn(const QString&);

};

#endif // FORMINFO_H
