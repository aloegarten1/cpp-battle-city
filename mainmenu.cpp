#include "mainmenu.h"

MainMenu::MainMenu(QWidget *parent)
    : QWidget(parent) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    QPushButton* settingsButton = new QPushButton("Settings", this);
    QPushButton* exitButton = new QPushButton("Exit", this);

    layout->addWidget(settingsButton);
    layout->addWidget(exitButton);

    connect(settingsButton, &QPushButton::clicked, this, &MainMenu::openSettings);
    connect(exitButton, &QPushButton::clicked, qApp, &QApplication::quit);
}
