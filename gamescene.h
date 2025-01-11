#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <QGraphicsView>
#include "settings.h"
#include "game.h"

class GameScene : public QGraphicsView {
    Q_OBJECT

public:
    GameScene(Settings* settings, QWidget *parent = nullptr);

signals:
    void backToMainMenu();
    
protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    Game* m_game;
};

#endif // GAME_SCENE_H
