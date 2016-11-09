#-------------------------------------------------
#
# Project created by QtCreator 2016-11-07T17:05:38
#
#-------------------------------------------------

QT       += core gui \
        multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Game04
TEMPLATE = app


SOURCES += main.cpp \
    bullet.cpp \
    rect.cpp \
    enemy.cpp \
    game.cpp \
    score.cpp \
    health.cpp

HEADERS  += \
    bullet.h \
    rect.h \
    enemy.h \
    game.h \
    score.h \
    health.h

RESOURCES += \
    res.qrc
