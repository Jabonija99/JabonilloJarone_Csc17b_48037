
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

    //Create submit button
    submit = new QPushButton(tr("Checkout"));
    submit->setDefault(true);//Set it as default button
    submit->setEnabled(false);//Disable button

    //Create cancel button
    cancel = new QPushButton(tr("Cancel"));

    //Create display textbox
    display = new QPlainTextEdit(tr("Summary\n=====================\n"
                                    "Name:\nAddress:\nPhone:\n"));
    display->setFixedWidth(200); //Set textbox width

    //Create spacer item (width, height)
    spacer = new QSpacerItem(300,150);
}

void Checkout::setConnect(){
    //Connectors

    //Pull text when the submit button is clicked
    connect(submit,SIGNAL(clicked()),
            this, SLOT(pullText()));
    //Close program f cancel button clicked
    connect(cancel,SIGNAL(clicked()),
            this,SLOT(close()));
}

void Checkout::layItems(){

    /*
    //Layouts
    //Create horziontal layout
    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(lbName);   //Add name label
    topLeftLayout->addWidget(leName);   //Add name text

    //Create horizontal layout
    QHBoxLayout *midLeftLayout = new QHBoxLayout;
    midLeftLayout->addWidget(lbAddrs);  //Add address label
    midLeftLayout->addWidget(leAddrs);  //Add address text

    //Create horizontal layout
    QHBoxLayout *botLeftLayout = new QHBoxLayout;
    botLeftLayout->addWidget(lbPhone);  //Add phone label
    botLeftLayout->addWidget(lePhone);  //Add phone text

    //Create vertical layout
    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);   //Add top layout
    leftLayout->addLayout(midLeftLayout);   //Add middle layout
    leftLayout->addLayout(botLeftLayout);   //Add bottom layout
    leftLayout->addSpacerItem(spacer);      //Add spacer item

    //Create vertical layout
    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(display);    //Add textbox
    rightLayout->addWidget(submit);     //Add submit button
    rightLayout->addWidget(cancel);     //Add cancel button

    //Create horizontal layout
    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);  //Add left layout
    mainLayout->addLayout(rightLayout); //Add right layout

    setLayout(mainLayout);              //Set main layout
    setWindowTitle(tr("Shopping Cart"));//Set window title
    setFixedHeight(sizeHint().height());//Set fixed height
    setFixedWidth(sizeHint().width());  //Set fixed width
    */
}

void Checkout::pullText(){
    //Pull string into text
    /*
    QString text = tr("Summary\n=====================\n")
            + tr("Name: ")+ leName->text() +tr("\n")
            + tr("Address: ")+ leAddrs->text() +tr("\n")
            + tr("Phone: ")+ lePhone->text() +tr("\n");
    //Set text into textbox
    display->setPlainText(text);
    */
}

void Checkout::enableSubmit(const QString &text){
    //Enable submit button when text isnt empty
    submit->setEnabled(!text.isEmpty());
}
