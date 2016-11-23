#include "item.h"

#include <QFile>
#include <QDebug>

Item::Item()
{
    filename="";
    img="";
    name="";
    price="";
    ship="";
    desc="";
}

Item::Item(QString filename)
{
    if(load(filename)){
        qDebug() <<"File failed to open" <<filename <<" !\n";
    }
}

bool Item::load(QString filename){
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
