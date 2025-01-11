#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

class GameScene : public QGraphicsView {
    Q_OBJECT

public:
    GameScene(QWidget *parent = nullptr) : QGraphicsView(parent) {
        QGraphicsScene* scene = new QGraphicsScene(this);
        setScene(scene);

        // Add your tanks, bots, and other game elements here
        // For example:
        // scene->addItem(new Tank());
        // scene->addItem(new Bot());

        // Set up the view
        setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        setFixedSize(800, 600);  // Example size
        scene->setSceneRect(0, 0, 800, 600);
    }

signals:
    void backToMainMenu();
};