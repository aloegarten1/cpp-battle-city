#ifndef GAMEOBJECTM_H
#define GAMEOBJECTM_H

#include "game.h"
#include "gameobject.h"

enum class Direction : int
{
    UP = 1,
    RIGHT = 2,
    DOWN = 3,
    LEFT = 4
};

// movable game object
class GameObjectM : public GameObject
{
public:
    GameObjectM(Game *game, float x, float y, bool collide, bool destructable) : GameObject(game, x, y, collide, destructable),
                                                                                 velocityX_(0),
                                                                                 velocityY_(0),
                                                                                 velocity_(0.2),
                                                                                 dir_(Direction::UP) {}

    void setDirecton(Direction dir);
    Direction getDirection() { return dir_; }

    void stop();
    void update() override;

protected:
    float velocityX_;
    float velocityY_;
    float velocity_;
    Direction dir_;
};

#endif // GAMEOBJECTM_H
