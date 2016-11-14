#include "enemy.h"

#include <QTimer>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <cstdlib>
#include <ctime>
#include <stdlib.h>

#include <QDebug>

#include "bullet.h"
#include "game.h"

extern Game *GAME;

Enemy::Enemy() :
    QObject(), QGraphicsPixmapItem()
{
    //Set random position
    int randX = rand() % 700;
    int randY = rand() % 500;
    setPos(randX,randY);

    //Draw enemy
    setPixmap(QPixmap(":/imgs/deps/enemyexam.png"));

    //Set speed
    vel = 6;

    //Create detection box

    //Connect
    //Timer item counts down and sends signal whenever it reaches 0
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()),
            this, SLOT(idle()));

    //Sets timer time to 50ms
    timer->start(200);
}

void Enemy::idle(){


    int direction = rand()%6;

    for(int i = 0; i < 3; i++){
        if(direction == 0){
            //Move enemy up
            setPos(x(), y()-vel);
        }
        else if(direction == 1){
            //Move enemy down
            setPos(x(), y()+vel);
        }
        else if(direction == 2){
            //Move enemy left
            setPos(x()-vel, y());
        }
        else if(direction == 3){
            //Move enemy right
            setPos(x()+vel, y());
        }
    }

}

void Enemy::fireUp(){
    //Create bullet above object
    Bullet *bullet = new Bullet();
    bullet->setPos(x()+50, y());
    scene()->addItem(bullet);
}

void Enemy::fireDwn(){
    //Create bullet below object
    Bullet *bullet = new Bullet();
    bullet->setPos(x()+50, y()+100);
    scene()->addItem(bullet);
}

void Enemy::fireLft(){
    //Create bullet left of object
    Bullet *bullet = new Bullet();
    bullet->setPos(x(), y()+50);
    scene()->addItem(bullet);
}

void Enemy::fireRgt(){
    //Create bullet right of object
    Bullet *bullet = new Bullet();
    bullet->setPos(x()+100, y()+50);
    scene()->addItem(bullet);
}

