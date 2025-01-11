#ifndef TANK_H
#define TANK_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>

class Tank : public QGraphicsRectItem
{
public:
    Tank() : QGraphicsRectItem() {
        setRect(0, 0, 50, 50);
        setBrush(Qt::blue);
    }
};

#endif // TANK_H
