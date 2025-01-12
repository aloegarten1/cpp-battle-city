#include "gameobject.h"

GameObject::GameObject(Game * game,float x, float y, bool collide): game_(game) {
    x_=x;
    y_=y;
    collide_=collide;

    int s = game_->scale();
    this->setPos(x*s,y*s);
}


void GameObject::SetTile(QString name){


    auto tl =  game_->getTileset();
    QPixmap img = tl->getTile(name+"1");

    int s = game_->scale();
    setPixmap(img.scaled(QSize(s,s),Qt::KeepAspectRatio));

}
