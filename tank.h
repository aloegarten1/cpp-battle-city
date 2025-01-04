#ifndef TANK_H
#define TANK_H

#include "gameobject.h"

class Tank : public GameObject
{
public:
    enum Direction {
        UP, DOWN, RIGHT, LEFT
    };

    Tank();
    Tank(const QPixmap image);

    void move() noexcept;
    void stop() noexcept;

    void changeHealth(uint16_t delta) noexcept;
    void setDirection(Direction dir) noexcept;

protected:
    uint16_t _hp;
    qreal _speed;
    Direction _currDirection;
};

#endif // TANK_H
