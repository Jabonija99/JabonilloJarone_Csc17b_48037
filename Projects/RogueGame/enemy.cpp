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
    findBox = new DetectBx();


    //Create timers
    //Movement timer
    QTimer *timer1 = new QTimer(this);
    //Attack timer
    QTimer *timer2 = new QTimer(this);

    //Connect timers
    connect(timer1, SIGNAL(timeout()),
            this, SLOT(idle()));
    connect(timer2, SIGNAL(timeout()),
            this, SLOT(fire()));


    timer1->start(200);
    timer2->start(1000);
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

void Enemy::fire(){
    int dir = 0;

    switch(dir){
        case 0:
            fireUp();
            break;
        case 1:
            fireRgt();
            break;
        case 2:
            fireDwn();
            break;
        case 3:
            fireLft();
            break;
        default:
            fireUp();
            break;
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

