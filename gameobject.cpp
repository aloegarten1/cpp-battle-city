#include "gameobject.h"

GameObject::GameObject()
    : _isSolid(NOT_SOLID)
{}

GameObject::GameObject(const QPixmap& image)
    : _isSolid(NOT_SOLID)
{
    this->setPixmap(image);
}
