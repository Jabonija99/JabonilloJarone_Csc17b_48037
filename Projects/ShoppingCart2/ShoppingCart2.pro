#-------------------------------------------------
#
# Project created by QtCreator 2016-11-23T10:34:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ShoppingCart2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    item.cpp \
    store.cpp \
    info.cpp \
    cart.cpp \
    checkout.cpp \
    complete.cpp

HEADERS  += mainwindow.h \
    item.h \
    store.h \
    info.h \
    cart.h \
    checkout.h \
    complete.h

RESOURCES += \
    res.qrc
