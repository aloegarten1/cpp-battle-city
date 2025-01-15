#include "wall.h"

void Wall::update(){
    if (frame_ == 0){
        setTile();
    }
    return;
}

QString Wall::skin(){
    return "wall1";
}
