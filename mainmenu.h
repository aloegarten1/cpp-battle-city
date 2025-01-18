#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QVBoxLayout>

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);

signals:
    void startGame();
    void openSettings();
};

#endif // MAINMENU_H
