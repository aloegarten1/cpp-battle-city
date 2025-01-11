#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QGraphicsScene>

class Player : public QGraphicsRectItem
{

public:
    Player() : QGraphicsRectItem()
    {
        setRect(0, 0, 50, 50);
        setBrush(Qt::blue);
    }

public slots:
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // PLAYER_H
