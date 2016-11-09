#include "bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include <typeinfo> //Enables object type info
#include <QDebug>

#include "enemy.h"
#include "game.h"

extern Game* GAME; //Includes external global constants

Bullet::Bullet(QGraphicsItem *parent):
    QObject(), QGraphicsPixmapItem(parent)
{
    //Draw graphics
    setPixmap(QPixmap(":/images/dep/bullet.png"));

    //Draws rect and sets size
    //setRect(0,0,10,50);

    //Connect
    //Timer item counts down and sends signal whenever it reaches 0
    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()),
            this, SLOT(move()));

    //Sets timer time to 50ms
    timer->start(50);
}

void Bullet::move(){
    //Check enemy collision then destroy both
    //QList of graphics items from collidingItems();
    //**collidingItems() - returns items colliding with it
    QList<QGraphicsItem *> colliding_items = collidingItems();
    //Checks all colliding items
    for(int i = 0, n = colliding_items.size(); i < n; ++i){
        //If the colliding item is an enemy
        if(typeid(*(colliding_items[i])) == typeid(Enemy)){
            //increase the score
            GAME->score->incScore();

            //Remove both items
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);

            //Delete from memory
            delete colliding_items[i];
            delete this;
            return;
        }
    }


    //Moves bullet up
    setPos(x(),y()-10);

    //if item moves offscren
    if(pos().y() - 50 <0){
        //Remove item from scene before deleting
        scene()->removeItem(this);
        delete this;
        qDebug() <<"Bullet deleted.";

    }
}
