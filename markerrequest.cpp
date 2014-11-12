#include "markerrequest.h"

MarkerRequest::MarkerRequest(int markerId)
{
    this->markerId = markerId;
}

MarkerRequest::MarkerRequest(int markerId, QTime requestTime)
{
    this->markerId = markerId;
    this->requestTime = requestTime;
}
//Equal if id and time match
bool MarkerRequest::operator ==(const MarkerRequest &other) const {
    return (this->markerId==other.markerId)&&(this->requestTime==other.requestTime);
}
bool MarkerRequest::operator ==(const int &i) const {
    return (this->markerId==i);
}
bool MarkerRequest::operator ==(const QTime &time) const {
    return (this->requestTime==time);
}
