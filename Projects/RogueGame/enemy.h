#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsRectItem> //Rectangle item
#include <QGraphicsPixmapItem>
#include <QObject> //allows signals and slots

class Enemy :
        public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    //Detection box for enemy
    QGraphicsRectItem *bxDetect;

    int vel;
public:
    Enemy();

    void fireUp();
    void fireDwn();
    void fireLft();
    void fireRgt();

public slots:
    void idle();
    void fire();

};

#endif // ENEMY_H
