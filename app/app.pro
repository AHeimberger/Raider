include(../core/core.pri)

TARGET = raider

QT -= gui
QT += core
QT += network

CONFIG += c++11
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += \
    sources/main.cpp

OTHER_FILES += \
    settings/settings.json \
    settings/string-colourize.json \
    settings/udp-transmission.json \
    \
    python/file-writer.py \
    python/udp-receiver.py
