QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    game/concretewall.cpp \
    game/enemy.cpp \
    game/enemyhq.cpp \
    game/game.cpp \
    game/gameobject.cpp \
    game/gameobjectm.cpp \
    game/player.cpp \
    game/projectile.cpp \
    game/tank.cpp \
    game/tankdriver.cpp \
    game/wall.cpp \
    gamecontroller.cpp \
    gamescene.cpp \
    main.cpp \
    mainmenu.cpp \
    mainwindow.cpp \
    settings.cpp \
    settingsmenu.cpp \
    tileset.cpp 

HEADERS += \
    game/concretewall.h \
    game/enemy.h \
    game/enemyhq.h \
    game/game.h \
    game/gameobject.h \
    game/gameobjectm.h \
    game/player.h \
    game/projectile.h \
    game/tank.h \
    game/tankdriver.h \
    game/wall.h \
    gamecontroller.h \
    gamescene.h \
    mainmenu.h \
    mainwindow.h \
    settings.h \
    settingsmenu.h \
    tileset.h 


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc
