#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsPixmapItem>

class GameObject : public QGraphicsPixmapItem
{
public:
    enum ColisionFlag : bool {
        SOLID,
        NOT_SOLID
    };

    GameObject();
    GameObject(const QPixmap& image);

    void setColisionFlag(ColisionFlag flag) noexcept { _isSolid = flag; }
    ColisionFlag isSolid() const noexcept { return _isSolid; }

    void update();

protected:
    ColisionFlag _isSolid;
};

#endif // GAMEOBJECT_H
