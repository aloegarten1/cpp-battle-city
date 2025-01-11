#ifndef SETTINGSMENU_H
#define SETTINGSMENU_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QSpinBox>
#include <QCheckBox>
#include <QPushButton>
#include "settings.h"

class SettingsMenu : public QWidget {
    Q_OBJECT

public:
    explicit SettingsMenu(Settings* settings, QWidget *parent = nullptr);

signals:
    void settingsSaved();

private slots:
    void onEnemiesCountChanged(int value);
    void onFullScreenToggled(bool checked);
    void onSaveClicked();

private:
    Settings* m_settings;
};

#endif // SETTINGSMENU_H
