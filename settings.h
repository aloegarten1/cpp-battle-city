#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>

class Settings : public QObject {
    Q_OBJECT

public:
    explicit Settings(QObject *parent = nullptr);

    int getEnemiesCount() const;
    void setEnemiesCount(int count);

    bool isFullScreen() const;
    void setFullScreen(bool fullScreen);

signals:
    void enemiesCountChanged(int count);
    void fullScreenChanged(bool fullScreen);

private:
    void loadSettings();
    void saveSettings();

    int m_enemiesCount;
    bool m_fullScreen;
};

#endif // SETTINGS_H
