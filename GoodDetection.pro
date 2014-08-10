#-------------------------------------------------
#
# Project created by QtCreator 2014-08-09T21:05:23
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = GoodDetection
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    detection.cpp \
    config.cpp

HEADERS += \
    detection.h


INCLUDEPATH += "/usr/local/include/opencv" \
               "/usr/local/include"

LIBS += `pkg-config --libs opencv`
