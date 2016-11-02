#-------------------------------------------------
#
# Project created by QtCreator 2016-10-31T13:27:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ShoppingCart
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    shop.cpp \
    item.cpp \
    cart.cpp

HEADERS  += mainwindow.h \
    shop.h \
    item.h \
    cart.h

DISTFILES +=


RESOURCES += \
    Resources.qrc
