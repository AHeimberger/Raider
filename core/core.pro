TARGET = core

QT -= gui
QT += core
QT += network

CONFIG += qt
CONFIG += c++11
CONFIG += staticlib

TEMPLATE = lib

INCLUDEPATH += \
    includes

SOURCES += \
    sources/FileWatcher.cpp \
    sources/FileReadOperations.cpp \
    sources/Colors.cpp \
    sources/StringColourize.cpp \
    sources/UdpTransmission.cpp \
    sources/CommandLineArguments.cpp \
    sources/Settings.cpp \
    sources/Logger.cpp

HEADERS += \
    includes/Logger.h \
    includes/Colors.h \
    includes/CommandLineArguments.h \
    includes/Settings.h \
    includes/FileWatcher.h \
    includes/FileReadOperations.h \
    includes/StringColourize.h \
    includes/UdpTransmission.h \
    includes/IStringOperation.h \
    includes/StringColourizeSettings.h
