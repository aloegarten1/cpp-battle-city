#include "gamescene.h"
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QRandomGenerator>

class Tank : public QGraphicsRectItem {
public:
    Tank() : QGraphicsRectItem() {
        setRect(0, 0, 50, 50);
        setBrush(Qt::blue);
    }
};

class Enemy : public QGraphicsRectItem {
public:
    Enemy() : QGraphicsRectItem() {
        setRect(0, 0, 40, 40);
        setBrush(Qt::red);
    }
};

GameScene::GameScene(Settings* settings, QWidget *parent)
    : QGraphicsView(parent), m_settings(settings), m_player(nullptr) {
    QGraphicsScene* scene = new QGraphicsScene(this);
    setScene(scene);

    // Initialize the player
    initializePlayer();

    // Initialize enemies
    initializeEnemies();

    // Set up the view
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800, 600);  // Example size
    scene->setSceneRect(0, 0, 800, 600);
}

void GameScene::initializeEnemies() {
    QGraphicsScene* scene = this->scene();

    int enemiesCount = m_settings->getEnemiesCount();
    for (int i = 0; i < enemiesCount; ++i) {
        Enemy* enemy = new Enemy();
        // Place enemies at random positions within the scene
        int x = QRandomGenerator::global()->bounded(760);  // 800 - 40 (enemy width)
        int y = QRandomGenerator::global()->bounded(560);  // 600 - 40 (enemy height)
        enemy->setPos(x, y);
        scene->addItem(enemy);
    }
}

void GameScene::initializePlayer() {
    m_player = new Player(this->scene(), this);
    // Optionally, set an initial position for the player
    m_player->setPos(400, 300);
}

void GameScene::keyPressEvent(QKeyEvent *event) {
    if (m_player) {
        m_player->keyPressEvent(event);
    }
}
