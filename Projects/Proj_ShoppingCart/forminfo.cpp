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

    cbGender = new QComboBox;
    cbGender->addItem(tr("Male"));
    cbGender->addItem(tr("Female"));
    cbGender->addItem(tr("Other"));

    //Create address label and line editor
    lbAddrs = new QLabel(tr("Address:"));
    leAddrs = new QLineEdit;

    //Create phone label and line editor
    lbPhone = new QLabel(tr("Phone"));
    lePhone = new QLineEdit;
    //Set max character length to 10
    lePhone->setMaxLength(10);

    //Create submit button
    submit = new QPushButton(tr("Submit"));
    //Set it as the default button
    submit->setDefault(true);
    //Disable the button
    submit->setEnabled(false);

    //Create cancel button
    cancel = new QPushButton(tr("Cancel"));

    //Create format spacers
    spInfo = new QSpacerItem(100,10);
    spInfo2 = new QSpacerItem(800, 5);
    spInfo3 = new QSpacerItem(800,500);
    spBtn = new QSpacerItem(300,100);

    wCheckout = new Checkout;
}

void FormInfo::setConnect(){
    //Enable submit button when text is changed
    connect(leName, SIGNAL(textChanged(const QString&)),
            this, SLOT(enableBtn(const QString&)));
    connect(leAddrs, SIGNAL(textChanged(const QString&)),
            this, SLOT(enableBtn(const QString&)));
    connect(lePhone, SIGNAL(textChanged(const QString&)),
            this, SLOT(enableBtn(const QString&)));

    //Open checkout window when submit is entered
    connect(submit, SIGNAL(clicked()),
            this, SLOT(openCheckout()));
    connect(cancel, SIGNAL(clicked()),
            this, SLOT(close()));
}

void FormInfo::layItems(){

    //Layout for names
    QHBoxLayout *nameLayout = new QHBoxLayout;
    nameLayout->addSpacerItem(spInfo);
    nameLayout->addWidget(lbName);  //Add name Label
    nameLayout->addWidget(leName);  //Add name Line edit
    nameLayout->addWidget(cbGender);//Add gender combo box
    nameLayout->addSpacerItem(spInfo);

    //Layout for addresses
    QHBoxLayout *addrLayout = new QHBoxLayout;
    addrLayout->addSpacerItem(spInfo);
    addrLayout->addWidget(lbAddrs); //Add address label
    addrLayout->addWidget(leAddrs);
    addrLayout->addSpacerItem(spInfo);

    QHBoxLayout *phoneLayout = new QHBoxLayout;
    phoneLayout->addSpacerItem(spInfo);
    phoneLayout->addWidget(lbPhone);
    phoneLayout->addWidget(lePhone);
    phoneLayout->addSpacerItem(spInfo);

    QVBoxLayout *topLayout = new QVBoxLayout;
    topLayout->addSpacerItem(spInfo3);
    topLayout->addLayout(nameLayout);
    topLayout->addSpacerItem(spInfo2);
    topLayout->addLayout(addrLayout);
    topLayout->addSpacerItem(spInfo2);
    topLayout->addLayout(phoneLayout);
    topLayout->addSpacerItem(spInfo3);

    QVBoxLayout *centerLayout = new QVBoxLayout;
    centerLayout->addWidget(submit);
    centerLayout->addWidget(cancel);

    QHBoxLayout *botLayout = new QHBoxLayout;
    botLayout->addSpacerItem(spBtn);
    botLayout->addLayout(centerLayout);
    botLayout->addSpacerItem(spBtn);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(topLayout);
    mainLayout->addLayout(botLayout);

    setLayout(mainLayout);
    setFixedHeight(600);
    setFixedWidth(800);

}

void FormInfo::openCheckout(){
    wCheckout->show();
    this->close();
}

void FormInfo::enableBtn(const QString &text){
    submit->setEnabled(!text.isEmpty());
}
