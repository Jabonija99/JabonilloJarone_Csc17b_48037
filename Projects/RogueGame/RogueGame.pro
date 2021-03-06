#-------------------------------------------------
#
# Project created by QtCreator 2016-11-09T16:25:19
#
#-------------------------------------------------

QT       += core gui \
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RogueGame
TEMPLATE = app


SOURCES += main.cpp \
    bullet.cpp \
    enemy.cpp \
    game.cpp \
    health.cpp \
    rect.cpp \
    score.cpp \
    player.cpp \
    detectbx.cpp

HEADERS  += \
    bullet.h \
    enemy.h \
    game.h \
    health.h \
    rect.h \
    score.h \
    player.h \
    detectbx.h

RESOURCES += \
    res.qrc
