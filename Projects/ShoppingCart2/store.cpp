#include "store.h"
#include <QtWidgets>


const int SCREEN_HEIGHT = 740;
const int SCREEN_WIDTH = 1024;

Store::Store(QWidget *parent):
    QDialog(parent)
{
    setItems();     //Create items
    setConnect();   //Assign connections
    layItems();     //Render items
}

void Store::setItems(){
    int index = 0;
    inv[index++] = new Item("tablet.txt");
    inv[index++] = new Item("punchingbag.txt");
    inv[index++] = new Item("hoop.txt");

    btMore = new QPushButton("More Info");
    btAddCart = new QPushButton("Add to Cart");

    itemBox = new QScrollArea;
    itemBox->setWidget(mkGrp_Scroll());
}

