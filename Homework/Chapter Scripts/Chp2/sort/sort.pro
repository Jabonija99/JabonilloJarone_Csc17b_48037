QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sort

TEMPLATE      = app
HEADERS       = sortdialog.h
SOURCES       = main.cpp \
                sortdialog.cpp
FORMS         = sortdialog.ui
