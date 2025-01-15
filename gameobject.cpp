#include "gameobject.h"
#include "tileset.h"

GameObject::GameObject(Game *game, float x, float y, bool collide, bool destructable) : game_(game)
{
    x_ = x;
    y_ = y;
    collide_ = collide;
    destructable_ = destructable;

    int s = game_->scale();
    this->setPos(x * s, y * s);
}

void GameObject::SetTile()
{

    try
    {
        TileSet *tl = TileSet::getInstance();
        QString sk = skin();
        QPixmap img = tl->getTile(sk);
        int s = game_->scale();
        setPixmap(img.scaled(QSize(s, s), Qt::KeepAspectRatio));
    }
    catch (...)
    {
        // TODO
    }
}
