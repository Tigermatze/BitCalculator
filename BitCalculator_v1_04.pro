#-------------------------------------------------
#
# Project created by QtCreator 2015-10-09T22:42:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 5): QT += widgets

TARGET = BitCalculator
TEMPLATE = app


SOURCES += main.cpp\
        BitCalcResourcen.cpp \
    BitCalculator.cpp

HEADERS  += BitCalculator.h

FORMS    += BitCalculator.ui

#unix|win32: LIBS += -L/usr/lib/x86_64-linux-gnu -lusb-1.0

RESOURCES += \
    BitCalculator.qrc
