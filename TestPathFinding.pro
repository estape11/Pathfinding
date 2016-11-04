QT += core
QT -= gui

CONFIG += c++11

TARGET = TestPathFinding
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    node.cpp

HEADERS += \
    node.h \
    pathfinding.h
