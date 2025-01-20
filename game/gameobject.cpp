#include "gameobject.h"

GameObject::GameObject(Game *game, float x, float y, bool collide, bool destructable) : game_(game)
{
    x_ = x;
    y_ = y;
    collide_ = collide;
    destructable_ = destructable;
    frame_ = 0;

    alive_ = true;
}

void GameObject::update()
{
    frame_++;
}
