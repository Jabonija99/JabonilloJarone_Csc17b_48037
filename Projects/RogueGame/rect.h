#ifndef RECT_H
#define RECT_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QMediaPlayer>

#include "enemy.h"

class Rect : public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
private:
    QMediaPlayer *bulletsound;

public:
    Rect(QGraphicsItem *parent=0);
    void keyPressEvent(QKeyEvent * event);
public slots:
    void spawn();
};
#endif // RECT_H
