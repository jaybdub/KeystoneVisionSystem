#ifndef MARKERREQUEST_H
#define MARKERREQUEST_H

#include <QTime>

class MarkerRequest
{
public:
    MarkerRequest(int markerId);
    MarkerRequest(int markerId, QTime requestTime);
    int markerId;
    QTime requestTime;
    bool operator ==(const MarkerRequest &other) const;
    bool operator ==(const int &i) const;
    bool operator ==(const QTime &time) const;
};

#endif // MARKERREQUEST_H
