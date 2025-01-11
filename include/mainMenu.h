#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QApplication>
class MainMenu : public QWidget {
    Q_OBJECT

public:
    MainMenu(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout* layout = new QVBoxLayout(this);

        QPushButton* startButton = new QPushButton("Start Game", this);
        QPushButton* exitButton = new QPushButton("Exit", this);

        layout->addWidget(startButton);
        layout->addWidget(exitButton);

        connect(startButton, &QPushButton::clicked, this, &MainMenu::startGame);
        connect(exitButton, &QPushButton::clicked, qApp, &QApplication::quit);
    }

signals:
    void startGame();
};
