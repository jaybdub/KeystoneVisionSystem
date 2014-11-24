#include "markerrequestqueue.h"

MarkerRequestQueue::MarkerRequestQueue(QObject *parent) :
    QObject(parent)
{

}

void MarkerRequestQueue::removeMarkerRequestsFromQueueWithId(int markerId)
{
    //todo (needs iterator since removing an element changes size)
}

void MarkerRequestQueue::removeMarkerRequestFromQueue(MarkerRequest markerRequest)
{
    if(markerRequests.removeAll(markerRequest)>0)
        emit markerRequestRemovedFromQueue(markerRequest);
}

void MarkerRequestQueue::removeOldMarkerRequestsFromQueue(int ageMilliseconds)
{
    QTime now = QTime::currentTime();
//    QListIterator<MarkerRequest> i(markerRequests);
//    i.toFront();
//    while(i.hasNext()){
//        if(i.next().requestTime.msecsTo(now) > ageMilliseconds)
//            i.remove();
//    }
}

void MarkerRequestQueue::handleMarkersDetected(QList<Marker> markers)
{
    //Go through queue and fulfill any eligible marker requests
    for(int i=0;i<markers.size();i++){
        for(int j=0;j<markerRequests.size();j++){
            if(markers.at(i).id == markerRequests.at(j).markerId){
                emit markerRequestMatched(markers.at(i),markerRequests.at(j));
                //emit markerRequestMatched(markers.at(i).toQString());
                emit markerRequestMatched(markers.at(i));
                emit markerRequestMatched(markerRequests.at(j));
                emit markerRequestMatched(markers.at(i).id);

                //Remove request from queue
            }
        }
    }
}

void MarkerRequestQueue::addMarkerRequest(MarkerRequest markerRequest)
{
    markerRequests.append(markerRequest);
}

