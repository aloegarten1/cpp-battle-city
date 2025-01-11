#ifndef TANK_H
#define TANK_H

#include "gameobject.h"
#include <QObject>
#include <QGraphicsPathItem>

enum class Direction {
    RIGHT, LEFT, UP, DOWN
};

class Tank : public QObject, public GameObject
{
    Q_OBJECT;

public:
    Tank() = default;
    /**
     * @brief Tank
     * @param pm - take from Tileset.
     */
    Tank(QPixmap& pm, uint16_t hp, qreal speed, Direction dir);
    virtual ~Tank() = default;

    virtual void updateObject();

    uint16_t hp() const noexcept;
    qreal speed() const noexcept;
    Direction dir() const noexcept;

    /**
     * @brief startMoving: forces tank to move in direction "dir".
     * @param dir: direction
     */
    void startMoving(Direction dir);

    /**
     * @brief stop: forces tank to stop.
     */
    void stop();

private:
    uint16_t hp_;
    qreal currSpeed_, maxSpeed_;
    Direction dir_;

private:
    void move();
};

#endif // TANK_H
