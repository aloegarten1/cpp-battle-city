#include "enemyhq.h"

void EnemyHQ::update(){
    GameObject::update();

        SetTile();

}


QString EnemyHQ::skin(){
    return "enemyHQ-" + QString::number(frame_ % 7);
}
