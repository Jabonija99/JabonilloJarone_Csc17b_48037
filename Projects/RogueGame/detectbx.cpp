#include "detectbx.h"

#include <QList>
#include <QTimer>
#include <typeinfo>
#include "player.h"

DetectBx::DetectBx() :
    QObject(), QGraphicsRectItem()
{
    width = 200;
    height = 200;
    setRect(0,0,width,height);

    //Timer for scnaning
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),
            this, SLOT(scan()));

    timer->start(200);
}

void DetectBx::scan(){
    //detect player
    QList<QGraphicsItem *> colliding_items = collidingItems();
    //Checks all colliding items
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        //If player hits the box
        if(typeid(*(colliding_items[i])) == typeid(Player)){
            int direction = 0;

            //If player is at upper half of box
            if(colliding_items[i]->y()<100)
                //Fire up
                direction = 0;
            //If player is below
            else if (colliding_items[i]->y()> 100)
                //fire down
                direction = 2;
            //if Player is to the left
            else if (colliding_items[i]->x()<100)
                //fire left
                direction = 3;
            //If player is to the right
            else if (colliding_items[i]->x()>100)
                //Fire right
                direction = 4;

            emit detects(direction);
            return;
        }
    }
}
