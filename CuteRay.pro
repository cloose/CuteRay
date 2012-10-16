#-------------------------------------------------
#
# Project created by QtCreator 2012-10-15T16:17:19
#
#-------------------------------------------------

QT       += core gui opengl

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CuteRay
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    renderresultwidget.cpp \
    previewwidget.cpp

HEADERS  += mainwindow.h \
    renderresultwidget.h \
    previewwidget.h

FORMS    += mainwindow.ui
