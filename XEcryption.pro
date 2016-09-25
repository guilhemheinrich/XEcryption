QT += core
QT -= gui

TARGET = XEcryption
CONFIG += console
CONFIG -= app_bundle
CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++0x

TEMPLATE = app

SOURCES += main.cpp \
    word.cpp \
    text.cpp \
    stringhelper.cpp

HEADERS += \
    word.h \
    stringhelper.h \
    text.h

