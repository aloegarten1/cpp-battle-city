#include "tank.h"



void Tank::setDirecton(float vx, float vy){
    velocityX_=vx;
    velocityY_=vy;

}

void Tank::update(){
    float nx = x_ + velocityX_*velocity_;
    float ny = y_ + velocityY_*velocity_;

    if (game_->collide(this,nx,ny) != nullptr){
        return;
    }

    x_=nx;
    y_=ny;

    int s = game_->scale();
    setPos(x_*s,y_*s);

}

