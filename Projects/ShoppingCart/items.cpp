#include "items.h"

#include <QtWidgets>
#include <QFile>
#include <QDebug>

Items::Items(QGraphicsItem *parent):
    QObject(), QGraphicsPixmapItem(parent)
{
    filename="";
    img="";
    name="";
    price="";
    ship="";
    desc="";
}

Items::Items(QString filename, QGraphicsItem *parent):
    QObject(), QGraphicsPixmapItem(parent)
{
    if(load(filename)){
        qDebug() <<"File failed to open" <<filename <<" !\n";
    }
}

bool Items::load(QString filename){
    //Create bool for errors
    bool error = true;

    //Open file
    QFile file(":/items/inv/"+filename);
    if(!file.open(QIODevice::ReadOnly|QIODevice::Text)){
        error = false;
    }
    else{
        QTextStream in(&file);

        img = in.readLine();
        name = in.readLine();
        price = in.readLine();
        ship = in.readLine();
        desc = in.readLine();
    }

    return error;
}
