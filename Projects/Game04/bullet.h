#ifndef BULLET_H
#define BULLET_H

//#include <QGraphicsRectItem>
//Change to graphic item
#include <QGraphicsPixmapItem>
#include <QObject> //allows signals and slots

class Bullet : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Bullet(QGraphicsItem *parent =0);

public slots:
    void move();

};

#endif // BULLET_H
