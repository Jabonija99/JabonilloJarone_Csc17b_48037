#include "enemy.h"

#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>

#include <QDebug>

#include "game.h"

extern Game *GAME;

Enemy::Enemy() : QObject(), QGraphicsPixmapItem(){
    int randNum = rand() % 700;
    //Set random position at top of screen
    setPos(randNum,-100);

    //Draw enemy
    setPixmap(QPixmap(":/images/dep/enemy2.png"));
    //To transform objects use:
    //setTransformOriginPoint(50,50); //rotationpoint
    //setRotation(180); //rotates object


    //Draw rect
    //setRect(0,0,100,100);

    //Connect
    //Timer item counts down and sends signal whenever it reaches 0
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),
            this, SLOT(move1()));

    //Sets timer time to 50ms
    timer->start(50);
}

void Enemy::move1(){
    //Moves bullet down
    setPos(x(),y()+5);

    //if item moves offscren
    if(pos().y()>600){
        //Decrease health
        GAME->hp->decHp();

        //Remove item from scene before deleting
        scene()->removeItem(this);
        delete this;
        qDebug() <<"Enemy deleted.";
    }
}
