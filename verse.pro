TEMPLATE = app

CONFIG += c++11
CONFIG += debug
QT += gui
QT += qml
QT += quick
QT += core
QT += svg
QT += charts
QT += 3dcore
QT += opengl
QT += core gui

QMAKE_CC = gcc
QMAKE_CXX = g++

INCLUDEPATH += include/

HEADERS = include/version.h \
    include/agpl2.h \
    include/deliberate.h

SOURCES = src/main.cpp \
      src/version.cpp \
    src/deliberate.cpp

