#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsRectItem>
#include <QObject>

class Player : public QObject, public QGraphicsRectItem {
    Q_OBJECT

public:
    explicit Player(QGraphicsScene* scene, QObject *parent = nullptr);

public slots:
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void keyPressEvent(QKeyEvent *event) override;

protected:

private:
    QGraphicsScene* m_scene;
};

#endif // PLAYER_H
