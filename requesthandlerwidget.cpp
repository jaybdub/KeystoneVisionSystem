#include "requesthandlerwidget.h"

RequestHandlerWidget::RequestHandlerWidget(QWidget *parent) :
    QWidget(parent)
{
    state = 0;
    //Connect data received.
    connect(serialPortWidget,SIGNAL(dataReceived(QByteArray)),this,SLOT(handleDataReceived(QByteArray)));
    //Connect marker request received.
    connect(this,SIGNAL(requestReceived(MarkerRequest)),SLOT(handleRequestReceived(MarkerRequest)));
}

void RequestHandlerWidget::resetState()
{
    state = 0;
    emit stateChanged(state);
}

void RequestHandlerWidget::handleDataReceived(QByteArray data)
{
    //Handle each character received.
    for(int i=0;i<data.length();i++)
        handleNewChar(data[i]);
}

void RequestHandlerWidget::handleMarkersDetected(int markers)
{
    //Check if a request exists for each marker.  If so, fulfill the request.
}

void RequestHandlerWidget::handleRequestReceived(MarkerRequest r)
{
    //Remove any old duplicate marker request from the queue.
    removeFromQueue(r.markerId);

    //Add the new marker request to the queue.
    queue.append(r);
}

void RequestHandlerWidget::handleNewChar(char c)
{
    switch(state){
    case 0:
        if(c=='#'){
            state = 1;
            emit stateChanged(state);
        }
        break;
    case 1:
        if(c=='*'){
            //Set request time to now.
            QTime requestTime = QTime::currentTime();

            //Determine requested marker ids.
            QList<int> requestedMarkerIds = parseRequestString(this->requestString);

            for(int i=0;i<requestedMarkerIds.size();i++){
                //Create new marker request.
                MarkerRequest req(requestedMarkerIds.at(i),requestTime);

                //Generate request received signal.
                emit requestReceived(req);
            }

            //Reset state to 0 (waiting)
            state = 0;
            emit stateChanged(state);
        }
        else {
            //Add character to request string.
            requestString.append(c);
        }
        break;
    default:
        state = 0;
    }
}

QList<int> RequestHandlerWidget::parseRequestString(QString rs)
{
    QList<int> markerIds;

    //Split string at comma (',') into a list of marker strings
    QStringList markerStrings = rs.split(",",QString::SkipEmptyParts);

    for(int i=0;i<markerStrings.size();i++) {

        //Convert each markerString to an integer and add it to
        //the list of ids.
        markerIds.append(markerStrings.at(i).toInt());
    }

    return markerIds;
}

void RequestHandlerWidget::removeFromQueue(int markerId)
{
    //Iterate through queue, removing all markers with matching markerId
    for(int i=0;i<queue.size();i++){
        if(queue.at(i).markerId==markerId)
            queue.removeAt(i);
    }
}
