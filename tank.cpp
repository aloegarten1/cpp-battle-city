#include "tank.h"


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

    int sprite_ = (frame_ / 5) % 2;
    QString res =  mark_+"-"+dirName+"-"+QString::number(sprite_);
    return res;
}
