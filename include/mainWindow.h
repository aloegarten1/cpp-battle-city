#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "mainMenu.h"
#include "gameScene.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
        // Initialize the main menu scene
        MainMenu* mainMenu = new MainMenu(this);
        setCentralWidget(mainMenu);

        connect(mainMenu, &MainMenu::startGame, this, &MainWindow::onStartGame);
    }

private slots:
    void onStartGame() {
        // Switch to the game scene when the start button is clicked
        GameScene* gameScene = new GameScene(this);
        setCentralWidget(gameScene);

        connect(gameScene, &GameScene::backToMainMenu, this, &MainWindow::onBackToMainMenu);
    }

    void onBackToMainMenu() {
        // Switch back to the main menu when the game ends or the player quits
        MainMenu* mainMenu = new MainMenu(this);
        setCentralWidget(mainMenu);

        connect(mainMenu, &MainMenu::startGame, this, &MainWindow::onStartGame);
    }
};