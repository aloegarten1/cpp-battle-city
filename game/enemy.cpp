#include <random>
#include "enemy.h"


void Enemy::AI(){

    frame_++;

    if (!alive_) return;

    if (frame_ % 20 != 0){
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 8);

    int coin =  dis(gen);

    switch (coin) {
    case 1:
        tank_->setDirecton(Direction::UP);
        break;
    case 2:
        tank_->setDirecton(Direction::RIGHT);
        break;
    case 3:
        tank_->setDirecton(Direction::DOWN);
        break;
    case 4:
        tank_->setDirecton(Direction::LEFT);
        break;
     case 5:
        tank_->fire();
        break;
    default:
        tank_->stop();
        break;
    }

}
