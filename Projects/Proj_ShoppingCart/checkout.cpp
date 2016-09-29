
#include <QtWidgets>
#include "checkout.h"


Checkout::Checkout(QWidget *parent) : QDialog(parent)
{
    lbName = new QLabel("Name:");
    leName = new QLineEdit;

    lbAddrs = new QLabel("Address:");
    leAddrs = new QLineEdit;

    lbPhone = new QLabel("Phone");
    lePhone = new QLabel;

    submit = new QPushButton("Submit");
    submit->setDefault(true);
    submit->setEnabled(false);

    connect(leName, SIGNAL(textChanged(const QString&)), this,SLOT(enable))



}

