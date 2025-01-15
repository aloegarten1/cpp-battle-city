#ifndef ENEMYHQ_H
#define ENEMYHQ_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QPixmap>
#include <QRect>


#include "game.h"
#include "gameobject.h"

class EnemyHQ: public GameObject
{
public:
    EnemyHQ(Game *game, int x, int y) : GameObject(game, x,y, true,true) {};
    void update () override;

protected:
    QString skin() override;
};

#endif // ENEMYHQ_H
