#include "gameobjectm.h"

void GameObjectM::setDirecton(Direction dir)
{

    float vx;
    float vy;

    dir_ = dir;

    switch (dir)
    {
    case Direction::UP:
    {
        vx = 0;
        vy = -1;
        break;
    }
    case Direction::RIGHT:
    {
        vx = 1;
        vy = 0;
        break;
    }
    case Direction::DOWN:
    {
        vx = 0;
        vy = 1;
        break;
    }
    case Direction::LEFT:
    {
        vx = -1;
        vy = 0;
        break;
    }
    }

    velocityX_ = vx;
    velocityY_ = vy;

    // setTile();
}

void GameObjectM::stop()
{
    velocityX_ = 0;
    velocityY_ = 0;
}

void GameObjectM::update()
{
    GameObject::update();

    // if (frame_ < 2 || (0 == frame_ % 5 && (velocityX_!=0 || velocityY_!=0))){

    //     setTile();
    // }

    if (velocityX_ == 0 && velocityY_ == 0)
    {
        return;
    }

    float nx = x_ + velocityX_ * velocity_;
    float ny = y_ + velocityY_ * velocity_;

    if (game_->collide(this, nx, ny) != nullptr)
    {
        return;
    }

    x_ = nx;
    y_ = ny;

    // TileSet *tl = TileSet::getInstance();
    // int s = tl->scale();
    // setPos(x_*s,y_*s);
}
