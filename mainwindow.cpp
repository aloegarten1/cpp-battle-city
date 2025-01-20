#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) {
    m_stackedWidget = new QStackedWidget(this);
    setCentralWidget(m_stackedWidget);

    m_mainMenu = new MainMenu(this);
    m_settingsMenu = new SettingsMenu(&m_settings, this);

    m_stackedWidget->addWidget(m_mainMenu);
    m_stackedWidget->addWidget(m_settingsMenu);

    connect(m_mainMenu, &MainMenu::openSettings, this, &MainWindow::onOpenSettings);
    connect(m_settingsMenu, &SettingsMenu::settingsSaved, this, &MainWindow::onSettingsSaved);
}


void MainWindow::onOpenSettings() {
    m_stackedWidget->setCurrentWidget(m_settingsMenu);
}

void MainWindow::onSettingsSaved() {
    m_stackedWidget->setCurrentWidget(m_mainMenu);
}

void MainWindow::onBackToMainMenu() {
    m_stackedWidget->setCurrentWidget(m_mainMenu);
}
