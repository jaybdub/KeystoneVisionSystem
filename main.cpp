#include "mainwindow.h"
#include <QApplication>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include "serialportwidget.h"
#include <QList>
#include <QSerialPortInfo>
#include <QSerialPort>
#include "serialportlistwidget.h"
#include "requesthandlerwidget.h"
#include "serialportsettingswidget.h"
#include "serialportterminalwidget.h"
#include <QtCore>
#include "markerrequest.h"
#include "markerrequestqueue.h"
#include "marker.h"
#include "pose.h"
#include "camerasettingswidget.h"
#include <QCameraViewfinder>
#include <QCamera>
#include <QCameraImageCapture>
#include <QCameraInfo>
#include <QCameraInfoControl>

int main(int argc, char *argv[])
{
    //TODO:  1. Create SerialPortWidgetList
    //
    QApplication a(argc, argv);
    MarkerRequest mra(1,QTime::currentTime());
    MarkerRequest mrb(1,QTime::currentTime());
    qDebug() << QString::number(mra == mrb.markerId);
    MarkerRequestQueue *markerRequestQueue = new MarkerRequestQueue();
    markerRequestQueue->addMarkerRequest(mra);
    Marker *marker = new Marker(5,Pose(4.5,3.2,1.57),QTime::currentTime());

    QList<int> cameraDeviceIds;
    cameraDeviceIds.append(0);
    cameraDeviceIds.append(1);

    QList<QSize> resolutions;
    resolutions.append(QSize(1920,1080));
    resolutions.append(QSize(640,480));

    CameraSettingsWidget *csw = new CameraSettingsWidget;
    csw->setDeviceIdOptions(cameraDeviceIds);
    csw->setResolutionOptions(resolutions);
    csw->show();

    QCamera *camera = new QCamera;

    QCameraViewfinder *viewfinder = new QCameraViewfinder();
    viewfinder->show();

    QCameraInfo *caminfo = new QCameraInfo(camera);
    qDebug() << caminfo->deviceName();
    camera->setViewfinder(viewfinder);

    QCameraImageCapture *imageCapture = new QCameraImageCapture(camera);

    camera->setCaptureMode(QCamera::CaptureStillImage);
    camera->start();
    imageCapture->capture();

    qDebug() << marker->toQString();
    SerialPortTerminalWidget *sptw = new SerialPortTerminalWidget;
    sptw->show();

    return a.exec();
}
