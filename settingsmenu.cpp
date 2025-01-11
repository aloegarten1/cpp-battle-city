#include "settingsmenu.h"

SettingsMenu::SettingsMenu(Settings* settings, QWidget *parent)
    : QWidget(parent), m_settings(settings) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    // Enemies Count SpinBox
    QLabel* enemiesCountLabel = new QLabel("Enemies Count:", this);
    QSpinBox* enemiesCountSpinBox = new QSpinBox(this);
    enemiesCountSpinBox->setRange(1, 20);  // Set the range from 1 to 20
    enemiesCountSpinBox->setValue(m_settings->getEnemiesCount());
    layout->addWidget(enemiesCountLabel);
    layout->addWidget(enemiesCountSpinBox);

    // Fullscreen Checkbox
    QLabel* fullScreenLabel = new QLabel("Fullscreen:", this);
    QCheckBox* fullScreenCheckBox = new QCheckBox(this);
    fullScreenCheckBox->setChecked(m_settings->isFullScreen());
    layout->addWidget(fullScreenLabel);
    layout->addWidget(fullScreenCheckBox);

    // Save Button
    QPushButton* saveButton = new QPushButton("Save", this);
    layout->addWidget(saveButton);

    connect(enemiesCountSpinBox, static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged), this, &SettingsMenu::onEnemiesCountChanged);
    connect(fullScreenCheckBox, &QCheckBox::toggled, this, &SettingsMenu::onFullScreenToggled);
    connect(saveButton, &QPushButton::clicked, this, &SettingsMenu::onSaveClicked);
}

void SettingsMenu::onEnemiesCountChanged(int value) {
    m_settings->setEnemiesCount(value);
}

void SettingsMenu::onFullScreenToggled(bool checked) {
    m_settings->setFullScreen(checked);
}

void SettingsMenu::onSaveClicked() {
    emit settingsSaved();
}
