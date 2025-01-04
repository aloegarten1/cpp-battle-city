#ifndef GAME_H
#define GAME_H

#include "gameobject.h"

#include <QGraphicsScene>

class Game : public QGraphicsScene {
Q_OBJECT;

public:
    explicit Game(QObject *parent = nullptr);
    void updateScene();
protected:
    virtual void keyPressEvent(QKeyEvent * keyEvent);
    // virtual void keyReleaseEvent(QKeyEvent * keyEvent);

private:
    GameObject * obj;
};

#endif // GAME_H
