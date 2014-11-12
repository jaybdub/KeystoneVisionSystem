#ifndef MARKERREQUESTQUEUE_H
#define MARKERREQUESTQUEUE_H

#include <QObject>
#include "marker.h"
#include "markerrequest.h"

class MarkerRequestQueue : public QObject
{
    Q_OBJECT
public:
    explicit MarkerRequestQueue(QObject *parent = 0);

signals:
    void markerRequestMatched(Marker marker, MarkerRequest markerRequest);
    void markerRequestMatched(MarkerRequest markerRequest);
    void markerRequestMatched(Marker marker);
    //void markerRequestMatched(QString markerString);
    void markerRequestMatched(int markerId);
    void markerRequestRemovedFromQueue(MarkerRequest markerRequest);
public slots:
    void handleMarkersDetected(QList<Marker> markers);
    void addMarkerRequest(MarkerRequest markerRequest);
    void removeMarkerRequestsFromQueueWithId(int markerId);
    void removeMarkerRequestFromQueue(MarkerRequest markerRequest);
    void removeOldMarkerRequestsFromQueue(int ageMilliseconds);
private:
    QList<MarkerRequest> markerRequests;
    //max age (the max age of MarkerRequests that may remain in the queue)
    //max no. of requests
};

#endif // MARKERREQUESTQUEUE_H
