#include "mainwindow.h"
#include "gamecontroller.h"
#include "mainmenu.h"
#include "gamescene.h"
#include "settingsmenu.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_stackedWidget = new QStackedWidget(this);
    setCentralWidget(m_stackedWidget);

    m_mainMenu = new MainMenu(this);
    m_settingsMenu = new SettingsMenu(&m_settings, this);

    m_stackedWidget->addWidget(m_mainMenu);
    m_stackedWidget->addWidget(m_settingsMenu);

    connect(m_mainMenu, &MainMenu::startGame, this, &MainWindow::onStartGame);
    connect(m_mainMenu, &MainMenu::openSettings, this, &MainWindow::onOpenSettings);
    connect(m_settingsMenu, &SettingsMenu::settingsSaved, this, &MainWindow::onSettingsSaved);

    setFixedSize(800, 600);
}

void MainWindow::onStartGame()
{
    GameScene *gameScene = new GameScene(this);
    GameController *controller = new GameController(gameScene, &m_settings, this);
    gameScene->setController(controller);

    connect(controller, &GameController::backToMainMenu, this, &MainWindow::onBackToMainMenu);

    m_stackedWidget->addWidget(gameScene);
    m_stackedWidget->setCurrentWidget(gameScene);

    // Clean up old game scene when switching back to main menu
    connect(controller, &GameController::backToMainMenu, [this, gameScene, controller]()
            {
        m_stackedWidget->removeWidget(gameScene);
        gameScene->deleteLater();
        delete controller;
    });
}

void MainWindow::onOpenSettings()
{
    m_stackedWidget->setCurrentWidget(m_settingsMenu);
}

void MainWindow::onSettingsSaved()
{
    m_stackedWidget->setCurrentWidget(m_mainMenu);
}

void MainWindow::onBackToMainMenu()
{
    m_stackedWidget->setCurrentWidget(m_mainMenu);
}
