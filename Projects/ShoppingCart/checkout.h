#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <QDialog>

class QLabel;
class QPushButton;
class QLineEdit;
class QCheckBox;

class Checkout : public QDialog
{
    Q_OBJECT
private:
    void setItems();
    void setConnect();
    void layItems();

    QLabel *lbHeader;
    QLabel *lbName;
    QLabel *lbAddr;
    QLabel *lbPhone;

    QLineEdit *leName;
    QLineEdit *leAddr;
    QLineEdit *lePhone;

    QCheckBox *chkterms;

    QPushButton *btSubmit;

private slots:
    void enableBtn();
    void disablBtn();

public:
    Checkout();
};

#endif // CHECKOUT_H
