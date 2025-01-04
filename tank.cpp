#include "tank.h"

Tank::Tank():
    _hp(0), _speed(0), _currDirection(UP)
{}

Tank::Tank(const QPixmap image):
    _hp(0), _speed(0), _currDirection(UP)
{
    setPixmap(image);
}


void Tank::move() noexcept {
    switch (_currDirection) {
    case UP:
        moveBy(.0f, -_speed);
    case DOWN:
        moveBy(.0f, _speed);
    case RIGHT:
        moveBy(_speed, .0f);
    case LEFT:
        moveBy(-_speed, .0f);
    }
}

void Tank::stop() noexcept {
    _speed = .0f;
}
void Tank::changeHealth(uint16_t delta) noexcept {
    _hp += delta;
}

void Tank::setDirection(Direction dir) noexcept {
    _currDirection = dir;
}
