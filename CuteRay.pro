#-------------------------------------------------
#
# Project created by QtCreator 2012-10-15T16:17:19
#
#-------------------------------------------------

QT       += core gui opengl script

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CuteRay
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    renderresultwidget.cpp \
    previewwidget.cpp \
    scriptwidget.cpp \
    scriptevaluator.cpp \
    world.cpp \
    directionallight.cpp \
    light.cpp

HEADERS  += mainwindow.h \
    renderresultwidget.h \
    previewwidget.h \
    scriptwidget.h \
    scriptevaluator.h \
    world.h \
    directionallight.h \
    light.h

FORMS    += mainwindow.ui \
    scriptwidget.ui
