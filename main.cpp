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

    qDebug() << marker->toQString();
    SerialPortTerminalWidget *sptw = new SerialPortTerminalWidget;
    sptw->show();

    return a.exec();
}
