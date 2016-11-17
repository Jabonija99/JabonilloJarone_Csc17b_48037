#ifndef DETECTBX_H
#define DETECTBX_H

#include <QGraphicsRectItem>
#include <QObject>

class DetectBx : public QObject, public QGraphicsRectItem
{
    Q_OBJECT

private:
    int width;
    int height;

public:
    DetectBx(QGraphicsItem* parent = 0);
public slots:
    void scan();
signals:
    void detects(int dir);
};

#endif // DETECTBX_H
