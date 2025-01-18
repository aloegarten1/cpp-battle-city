#include "settings.h"

Settings::Settings(QObject *parent)
    : QObject(parent), m_enemiesCount(5), m_fullScreen(false)
{
    loadSettings();
}

int Settings::getEnemiesCount() const
{
    return m_enemiesCount;
}

void Settings::setEnemiesCount(int count)
{
    if (m_enemiesCount != count)
    {
        m_enemiesCount = count;
        emit enemiesCountChanged(m_enemiesCount);
        saveSettings();
    }
}

bool Settings::isFullScreen() const
{
    return m_fullScreen;
}

void Settings::setFullScreen(bool fullScreen)
{
    if (m_fullScreen != fullScreen)
    {
        m_fullScreen = fullScreen;
        emit fullScreenChanged(m_fullScreen);
        saveSettings();
    }
}

void Settings::loadSettings()
{
    QSettings settings("YourCompany", "TankBattle");
    m_enemiesCount = settings.value("enemiesCount", 5).toInt();
    m_fullScreen = settings.value("fullScreen", false).toBool();
}

void Settings::saveSettings()
{
    QSettings settings("YourCompany", "TankBattle");
    settings.setValue("enemiesCount", m_enemiesCount);
    settings.setValue("fullScreen", m_fullScreen);
}
