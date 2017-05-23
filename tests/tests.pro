include(../core/core.pri)

TARGET = tests

QT -= gui
QT += core
QT += testlib

TEMPLATE = app

CONFIG += testcase
CONFIG += console
CONFIG += c++11
CONFIG -= app_bundle

INCLUDEPATH += \
    includes

SOURCES += \
    sources/main.cpp \
    sources/gmock-gtest-all.cc \
    sources/printto.cpp \
    sources/helpers.cpp \
    sources/test_filereadoperations.cpp \
    sources/test_colors.cpp \
    sources/test_stringcolourize.cpp

HEADERS += \
    includes/gtest/gtest.h \
    includes/gmock/gmock.h \
    includes/printto.h \
    includes/helpers.h

OTHER_FILES += \
    others/gtest-version.txt \
    others/get-gmock.sh

RESOURCES += \
    testobjects.qrc
