#-------------------------------------------------
#
# Project created by QtCreator 2014-10-26T13:20:40
#
#-------------------------------------------------

QT       += core gui serialport multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VisionSystem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    serialportwidget.cpp \
    serialportlistwidget.cpp \
    requesthandlerwidget.cpp \
    communicationwidget.cpp \
    linuxvideocontrol.cpp \
    markerdetector.cpp \
    serialportsettingswidget.cpp \
    serialportterminalwidget.cpp \
    marker.cpp \
    markerrequestqueue.cpp \
    markerrequest.cpp \
    pose.cpp \
    camerasettingswidget.cpp \
    cameraviewportwidget.cpp \
    opencvcamera.cpp

HEADERS  += mainwindow.h \
    serialportwidget.h \
    serialportlistwidget.h \
    requesthandlerwidget.h \
    communicationwidget.h \
    linuxvideocontrol.h \
    markerdetector.h \
    serialportsettingswidget.h \
    serialportterminalwidget.h \
    marker.h \
    markerrequestqueue.h \
    markerrequest.h \
    pose.h \
    camerasettingswidget.h \
    cameraviewportwidget.h \
    opencvcamera.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc

unix|win32: LIBS += -L/usr/local/lib -laruco -lopencv_highgui -lopencv_core

INCLUDEPATH += /usr/local/include
DEPENDPATH += /usr/local/include
