#ifndef REQUESTHANDLERWIDGET_H
#define REQUESTHANDLERWIDGET_H

#include <QWidget>
#include <QByteArray>
#include <QString>
#include <QTime>
#include "serialportwidget.h"
#include "markerrequest.h"

/*class MarkerRequest
{
    public:
        MarkerRequest(int markerId, QTime requestTime){
            this->markerId = markerId;
            this->requestTime = requestTime;
        }
        int markerId;
        QTime requestTime;
};*/

class RequestHandlerWidget : public QWidget
{
    Q_OBJECT
public:
    explicit RequestHandlerWidget(QWidget *parent = 0);

signals:
    void dataSent(QByteArray data);
    void requestReceived(MarkerRequest r);
    void stateChanged(int state);
public slots:
    void resetState();
    void handleDataReceived(QByteArray data);
    void handleMarkersDetected(int markers);
    void handleRequestReceived(MarkerRequest r);
private:
    void handleNewChar(char c);
    QList<int> parseRequestString(QString rs);
    void removeFromQueue(int markerId);
    int state;
    QList<MarkerRequest> queue;
    QString requestString;
    SerialPortWidget *serialPortWidget;
    QWidget *markerDetectorWidget;

};

#endif // REQUESTHANDLERWIDGET_H
