#ifndef GAME_SCENE_H
#define GAME_SCENE_H

#include <QGraphicsView>

class GameController;

class GameScene : public QGraphicsView
{
    Q_OBJECT

public:
    GameScene(QWidget *parent = nullptr);
    ~GameScene() = default;

    void setController(GameController *controller);
    void update();

protected:
    void paintEvent(QPaintEvent *event) override;
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

private:
    void drawObject(QPainter &painter, const QPointF &position, const QString &textureKey);
    QGraphicsScene *scene_;
    GameController *controller_;
};

#endif // GAME_SCENE_H
