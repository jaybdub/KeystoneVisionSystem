#ifndef MARKERPOSEREQUESTHANDLER_H
#define MARKERPOSEREQUESTHANDLER_H

#include <QObject>
#include "MarkerPose"

class MarkerPoseRequestHandler : public QObject
{
    Q_OBJECT
public:
    explicit MarkerPoseRequestHandler(QObject *parent = 0);

signals:

public slots:

};

#endif // MARKERPOSEREQUESTHANDLER_H
