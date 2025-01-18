#include "enemyhq.h"

// void EnemyHQ::update()
// {
//     GameObject::update();

//     setTile();
// }

QString EnemyHQ::skin()
{
    return "enemyHQ-" + QString::number(frame_ % 7);
}
