#include <QtWidgets>
#include "forminfo.h"

FormInfo::FormInfo(QWidget *parent) : QDialog(parent)
{
    setItems();
    setConnect();
    layItems();
}

void FormInfo::setItems(){
    //Create name Label and line editor
    lbName = new QLabel(tr("Name:"));
    leName = new QLineEdit;

    //Create address label and line editor
    lbAddrs = new QLabel(tr("Address:"));
    leAddrs = new QLineEdit;

    //Create phone label and line editor
    lbPhone = new QLabel(tr("Phone"));
    lePhone = new QLineEdit;

    submit = new QPushButton(tr("Submit"));
    submit->setDefault(true);
    submit->setEnabled(false);

    cancel = new QPushButton(tr("Cancel"));

    spacer = new QSpacerItem(100,300);
}

void FormInfo::setConnect(){
    //Enable submit button when text is changed
    connect(leName, SIGNAL(textChanged(const QString&)),
            this, SLOT(enableSubmit(const QString&)));
    connect(leAddrs, SIGNAL(textChanged(const QString&)),
            this, SLOT(enableSubmit(const QString&)));
    connect(lePhone, SIGNAL(textChanged(const QString&)),
            this, SLOT(enableSubmit(const QString&)));

    connect(submit, SIGNAL(clicked()),
            this, SLOT(openCheckout()));
    connect(leName, SIGNAL(textChanged()),
            this, SLOT(enableBtn(const QString&)));
}

void FormInfo::layItems(){

}

void FormInfo::openCheckout(){

}

void FormInfo::enableBtn(const QString &text){
    submit->setEnabled(!text.isEmpty());
}
