#include "mainwindow.h"

#include "forminfo.h"
#include "checkout.h"

mainWindow::mainWindow()
{
    setItems();
    setConnect();
    layItems();
}

void mainWindow::setItems(){
    wForm = new Forminfo;
    wChkout = new Checkout;
    wEnd = new endtext;

}

void mainWindow::setConnect(){

}

void mainWindow::layItems(){

}
