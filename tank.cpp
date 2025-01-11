#include "tank.h"

Tank::Tank(uint16_t __hp, qreal __speed, Direction __dir)
    : hp_(__hp),
      currSpeed_(__speed),
      maxSpeed_(__speed),
      dir_(__dir)
{}

void Tank::updateObject() {
    move();
}

uint16_t Tank::hp() const noexcept {
    return hp_;
}

qreal Tank::speed() const noexcept {
    return currSpeed_;
}

Direction Tank::dir() const noexcept {
    return dir_;
}

void Tank::startMoving(Direction dir) {
    currSpeed_ = maxSpeed_;
    dir_ = dir;
}

void Tank::stop() {
    currSpeed_ = 0;
}

void Tank::move() {
    switch(dir_) {
    case Direction::UP:
        moveBy(0.0f, -currSpeed_);
        break;
    case Direction::DOWN:
        moveBy(0.0f, currSpeed_);
        break;
    case Direction::RIGHT:
        moveBy(currSpeed_, 0.0f);
        break;
    case Direction::LEFT:
        moveBy(-currSpeed_, 0.0f);
        break;
    }
}
