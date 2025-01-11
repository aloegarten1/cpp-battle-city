#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsScene>
#include <QGraphicsRectItem>

class Enemy : public QGraphicsRectItem
{

public:
    Enemy() : QGraphicsRectItem()
    {
        setRect(0, 0, 40, 40);
        setBrush(Qt::red);
    }
};
#endif // ENEMY_H
