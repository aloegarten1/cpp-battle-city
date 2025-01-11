#include "gameobject.h"

GameObject::GameObject(Game * game,int x, int y, int size): game_(game) {
    x_=x;
    y_=y;
    width_=size;
    height_=size;
}


