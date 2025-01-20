#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include "mainmenu.h"
#include "settingsmenu.h"
#include "settings.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private slots:
    void onOpenSettings();
    void onSettingsSaved();
    void onBackToMainMenu();

private:
    QStackedWidget* m_stackedWidget;
    MainMenu* m_mainMenu;
    SettingsMenu* m_settingsMenu;
    Settings m_settings;
};

#endif // MAINWINDOW_H
