
#include <QtWidgets>
#include "checkout.h"

//Checkout window class
Checkout::Checkout(QWidget *parent) : QDialog(parent)
{
    setItems();
    setConnect();
    layItems();
}

void Checkout::setItems(){

    lbHeader = new QLabel(tr("Order Summary\n========================"));
    lbItems = new QLabel(tr("Items\n========================"));
    lbInfo = new QLabel(tr("Information\n========================"));

    //Create submit button
    submit = new QPushButton(tr("Checkout"));
    submit->setDefault(true);//Set it as default button
    submit->setEnabled(true);//Enable button

    //Create cancel button
    cancel = new QPushButton(tr("Cancel"));

    //Create display textbox
    tbPrice = new QPlainTextEdit(tr("Payment\n=====================\n"));
    tbPrice->setFixedWidth(200); //Set textbox width

    //Create spacer item (width, height)
    spHeadr = new QSpacerItem(300,250);
    spPrice = new QSpacerItem(300,50);
    spBtn = new QSpacerItem(50,200);

    txtTy = new Endtext;
}

void Checkout::setConnect(){
    //Connections
    //Pull text when the submit button is clicked
    connect(submit,SIGNAL(clicked()),
            this, SLOT(complete()));
    //Close program f cancel button clicked
    connect(cancel,SIGNAL(clicked()),
            this,SLOT(close()));
}

void Checkout::layItems(){

    QVBoxLayout * leftLayout = new QVBoxLayout;
    leftLayout->addWidget(lbHeader);
    leftLayout->addSpacerItem(spHeadr);
    leftLayout->addWidget(lbInfo);
    leftLayout->addSpacerItem(spHeadr);
    leftLayout->addWidget(lbItems);
    leftLayout->addSpacerItem(spHeadr);

    QVBoxLayout *btnLayout = new QVBoxLayout;
    btnLayout->addWidget(submit);
    btnLayout->addWidget(cancel);

    QHBoxLayout *centerLayout = new QHBoxLayout;
    centerLayout->addSpacerItem(spBtn);
    centerLayout->addLayout(btnLayout);
    centerLayout->addSpacerItem(spBtn);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addSpacerItem(spPrice);
    rightLayout->addWidget(tbPrice);
    rightLayout->addSpacerItem(spPrice);
    rightLayout->addLayout(centerLayout);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);
    setLayout(mainLayout);
    setFixedHeight(600);
    setFixedWidth(800);

}

void Checkout::complete(){
    txtTy->show();
    this->close();
}

void Checkout::enableSubmit(const QString &text){
    //Enable submit button when text isnt empty
    submit->setEnabled(!text.isEmpty());
}
