#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <QGraphicsPixmapItem>
#include <QObject>

class GameObject : public QGraphicsPixmapItem
{
public:
    GameObject() = default;

    virtual ~GameObject() = default;

    /**
     * @brief updateObject: updates object state everytime whene scene was updated
     */
    virtual void updateObject() = 0;
};

#endif // GAMEOBJECT_H
