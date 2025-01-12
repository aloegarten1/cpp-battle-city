#include "gameobject.h"

GameObject::GameObject(Game * game,int x, int y, int size): game_(game) {
    x_=x;
    y_=y;
    width_=size;
    height_=size;

    this->setPos(x,y);
}


void GameObject::SetTile(QString name){


    auto tl =  game_->getTileset();
    QPixmap img = tl->getTile(name+"1");
    setPixmap(img.scaled(QSize(50,50),Qt::KeepAspectRatio));
}
