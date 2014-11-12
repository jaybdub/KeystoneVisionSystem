#-------------------------------------------------
#
# Project created by QtCreator 2014-10-26T13:20:40
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VisionSystem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    serialportwidget.cpp \
    serialportlistwidget.cpp \
    requesthandlerwidget.cpp \
    communicationwidget.cpp \
    camera.cpp \
    cameratoolbarwidget.cpp \
    cameraviewportwidget.cpp \
    linuxvideocontrol.cpp \
    markerdetector.cpp \
    serialportsettingswidget.cpp \
    serialportterminalwidget.cpp \
    marker.cpp \
    markerrequestqueue.cpp \
    markerrequest.cpp \
    pose.cpp \
    camerasettingswidget.cpp

HEADERS  += mainwindow.h \
    serialportwidget.h \
    serialportlistwidget.h \
    requesthandlerwidget.h \
    communicationwidget.h \
    camera.h \
    cameratoolbarwidget.h \
    cameraviewportwidget.h \
    linuxvideocontrol.h \
    markerdetector.h \
    serialportsettingswidget.h \
    serialportterminalwidget.h \
    marker.h \
    markerrequestqueue.h \
    markerrequest.h \
    pose.h \
    camerasettingswidget.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc