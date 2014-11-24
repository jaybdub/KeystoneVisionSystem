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
#include "opencvcamera.h"
#include "cameraviewportwidget.h"
#include "communicationwidget.h"

int main(int argc, char *argv[])
{
    //TODO:  1. Create SerialPortWidgetList
    //
    QApplication a(argc, argv);
//    MarkerRequest mra(1,QTime::currentTime());
//    MarkerRequest mrb(1,QTime::currentTime());
//    qDebug() << QString::number(mra == mrb.markerId);
//    MarkerRequestQueue *markerRequestQueue = new MarkerRequestQueue();
//    markerRequestQueue->addMarkerRequest(mra);
//    Marker *marker = new Marker(5,Pose(4.5,3.2,1.57),QTime::currentTime());

//    QList<int> cameraDeviceIds;
//    cameraDeviceIds.append(0);
//    cameraDeviceIds.append(1);

//    QList<QSize> resolutions;
//    resolutions.append(QSize(1920,1080));
//    resolutions.append(QSize(640,480));

//    CameraSettingsWidget *csw = new CameraSettingsWidget;
//    csw->setDeviceIdOptions(cameraDeviceIds);
//    csw->setResolutionOptions(resolutions);
//    csw->show();

//    CameraViewportWidget *cvpw = new CameraViewportWidget;

//    cvpw->show();
//    OpenCvCamera *cvcam = new OpenCvCamera;
//    cvcam->setDeviceId(1);
//    //cvcam->reopenDevice();
//    cvcam->grabFrame();

//    cvpw->setImage(&cvcam->qImage);
    //QImage("")

    //qDebug() << marker->toQString();
    //SerialPortTerminalWidget *sptw = new SerialPortTerminalWidget;
    //sptw->show();
    QSerialPort *sp = new QSerialPort();
    CommunicationWidget *cw = new CommunicationWidget(sp);
    cw->show();
    MainWindow *mw = new MainWindow;
    mw->show();
    return a.exec();
}
