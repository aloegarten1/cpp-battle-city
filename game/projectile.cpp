#include "projectile.h"

QString Projectile::skin()
{

    int sprite = frame_ % 6;

    QString res = "projectile" + QString::number(sprite);
    return res;
}
