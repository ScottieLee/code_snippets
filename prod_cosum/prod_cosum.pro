#-------------------------------------------------
#
# Project created by QtCreator 2013-08-20T17:38:35
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = prod_cosum
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    circular_buffer.cpp \
    producer.cpp \
    consumer.cpp

HEADERS += \
    circular_buffer.h \
    producer.h \
    consumer.h
