#ifndef CHECKOUT_H
#define CHECKOUT_H

#include <QDialog>

class QPushButton;
class QLabel;
class QLineEdit;

class Checkout
{
    Q_OBJECT

    private:
        QPushButton * submit;
        QLabel *instructions;
        QLineEdit *line;
    public:
        Checkout();
    signals:
    private slots:
};

#endif // CHECKOUT_H
