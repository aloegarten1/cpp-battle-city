#include "tank.h"



void Tank::setDirecton(Direction dir){

    float vx;
    float vy;

    dir_=dir;

    switch (dir){
    case Direction::UP:{
        vx = 0;
        vy = -1;
        break;
    }
    case Direction::RIGHT:{
        vx = 1;
        vy = 0;
        break;
    }
    case Direction::DOWN:{
        vx = 0;
        vy = 1;
        break;
    }
    case Direction::LEFT:{
        vx = -1;
        vy = 0;
        break;
    }
    }

    velocityX_=vx;
    velocityY_=vy;

    SetTile();

}

void Tank::stop(){
    velocityX_=0;
    velocityY_=0;

}

void Tank::update(){
    frame_++;

    if (0 == frame_ % 5 && (velocityX_!=0 || velocityY_!=0)){
        sprite_ = 1-sprite_;
        SetTile();
    }


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

QString Tank::skin(){
    QString dirName="";
    switch (dir_){
    case Direction::UP:{
        dirName="up";
        break;
    }
    case Direction::RIGHT:{
        dirName="right";
        break;
    }
    case Direction::DOWN:{
        dirName="down";
        break;
    }
    case Direction::LEFT:{
        dirName="left";
        break;
    }
    }

    QString res =  mark_+"-"+dirName+"-"+QString::number(sprite_);
    return res;
}
