#include "gameobject.h"
#include "tileset.h"

GameObject::GameObject(Game *game, float x, float y, bool collide, bool destructable) : game_(game)
{
    x_ = x;
    y_ = y;
    collide_ = collide;
    destructable_ = destructable;
    frame_ = 0;
}

// void GameObject::setTile()
// {
//     QString sk;
//     try
//     {
//         TileSet *tl = TileSet::getInstance();
//         sk = skin();
//         QPixmap img = tl->getTile(sk);
//         int s = tl->scale();
//         setPixmap(img.scaled(QSize(s, s), Qt::KeepAspectRatio));
//     }
//     catch (...)
//     {
//         qDebug() << "setTile " << sk;
//         // TODO
//     }
// }

void GameObject::update()
{
    frame_++;
}
