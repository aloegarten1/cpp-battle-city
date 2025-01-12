#include "tank.h"



void Tank::setVelocity(int vx, int vy){
    velocityX_=vx;
    velocityY_=vy;

}

void Tank::update(){
    int nx = x_ + velocityX_;
    int ny = y_ + velocityY_;

    if (game_->collide(nx,ny)){
        return;
    }

    x_=nx;
    y_=ny;

    setPos(x_,y_);

}

