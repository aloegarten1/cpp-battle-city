#ifndef TANK_H
#define TANK_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QRect>


#include "gameobject.h"

class Tank : public GameObject
{
public:
    Tank(int x, int y, int size) : GameObject(x,y,size) {

        QPixmap tl = QPixmap(":/images/images/tanks.png");
        QPixmap img = tl.copy(QRect(2.0f, 2.0f, 15.0f, 15.0f));
        setPixmap(img.scaled(QSize(50,50),Qt::KeepAspectRatio));

    }

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

};

#endif // TANK_H
