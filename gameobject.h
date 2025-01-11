#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsPixmapItem>
#include <QGraphicsScene>

class GameObject: public QGraphicsPixmapItem
{
public:
    GameObject(int x, int y, int size);


protected:

    int x_;
    int y_;

    int width_;
    int height_;

};

#endif // GAMEOBJECT_H
