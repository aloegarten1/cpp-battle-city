QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    concretewall.cpp \
    enemy.cpp \
    enemyhq.cpp \
    game.cpp \
    gameobject.cpp \
    gameobjectm.cpp \
    gamescene.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    player.cpp \
    projectile.cpp \
    settings.cpp \
    settingsmenu.cpp \
    tank.cpp \
    tankdriver.cpp \
    tileset.cpp \
    wall.cpp

HEADERS += \
    concretewall.h \
    enemy.h \
    enemyhq.h \
    game.h \
    gameobject.h \
    gameobjectm.h \
    gamescene.h \
    mainmenu.h \
    mainwindow.h \
    player.h \
    projectile.h \
    settings.h \
    settingsmenu.h \
    tank.h \
    tankdriver.h \
    tileset.h \
    wall.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
