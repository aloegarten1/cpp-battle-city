#include "tank.h"
#include "projectile.h"

QString Tank::skin()
{
    QString dirName = "";
    switch (dir_)
    {
    case Direction::UP:
    {
        dirName = "up";
        break;
    }
    case Direction::RIGHT:
    {
        dirName = "right";
        break;
    }
    case Direction::DOWN:
    {
        dirName = "down";
        break;
    }
    case Direction::LEFT:
    {
        dirName = "left";
        break;
    }
    }

    int sprite_ = (frame_ / 5) % 2;
    QString res = mark_ + "-" + dirName + "-" + QString::number(sprite_);
    return res;
}

void Tank::fire()
{
    if (frame_ - reloadCountdown_ < 10) // ??????
    {
        return;
    }

    reloadCountdown_ = frame_;

    float x = x_;
    float y = y_;

    switch (dir_)
    {
    case Direction::UP:
        y -= 1;
        break;
    case Direction::RIGHT:
        x += 1;
        break;
    case Direction::DOWN:
        y += 1;
        break;
    case Direction::LEFT:
        x -= 1;
        break;
    }

    Projectile *proj = new Projectile(game_, x, y);
    proj->setDirecton(dir_);
    game_->addGameObject(proj);
}
