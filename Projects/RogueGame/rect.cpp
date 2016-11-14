#include "rect.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <ctime>

//includes debugger
#include <QDebug>

#include "bullet.h"
#include "enemy.h"

Rect::Rect(QGraphicsItem* parent):
    QGraphicsPixmapItem(parent)
{
    //Set player image
    setPixmap(QPixmap(":/images/dep/spaceship2.png"));

    //Set bullet sound
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/dep/pew.mp3"));

}



void Rect::keyPressEvent(QKeyEvent *event){
    //qDebug() <<"Rectangle reads key\n"; //Output Debugger


    /* Enemy idle() test
    srand(time(0));
    int direction = rand()%5;
    if(direction == 0){
        //Move enemy up
        setPos(x(), y()-10);
    }
    else if(direction == 1){
        //Move enemy down
        setPos(x(), y()+10);
    }
    else if(direction == 2){
        //Move enemy left
        setPos(x()-10, y());
    }
    else if(direction == 3){
        //Move enemy right
        setPos(x()+10, y());
    }
    */

    //Reads key
    if(event->key() == Qt::Key_A){
        qDebug() <<"(L)Player x: " <<x();
        if(pos().x() > 0)
            setPos(x()-10, y());
    }
    else if(event->key() == Qt::Key_D){
        qDebug() <<"(R)Player x: " <<x();
        if(pos().x()+100 < 800 )
            setPos(x()+10, y());
    }
    /*
    else if(event->key() == Qt::Key_Up){
        setPos(x(), y()-10);
    }
    else if(event->key() == Qt::Key_Down){
        setPos(x(), y()+10);
    }
    */
    else if(event->key() == Qt::Key_Space){
        Bullet *bullet = new Bullet();
        //scene() returns pointer to scene
        bullet->setPos(x()+50, y());
        scene()->addItem(bullet);

        //Play bullet
        //If the bullet is already playing
        if(bulletsound->state() == QMediaPlayer::PlayingState){
            //Rewind sound
            bulletsound->setPosition(0);
        }
        //Else if it's paused
        else if(bulletsound->state() == QMediaPlayer::StoppedState){
            //Play normally
            bulletsound->play();
        }
    }

}

void Rect::spawn(){
    //Create enemy
    Enemy *enemy = new Enemy();
    scene()->addItem(enemy);
}
