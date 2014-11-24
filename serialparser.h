#ifndef SERIALPARSER_H
#define SERIALPARSER_H

#include <QObject>
#include "markerrequest.h"

class SerialParser : public QObject
{
    Q_OBJECT
public:
    explicit SerialParser(QObject *parent = 0);

signals:
    void newMarkerRequest(MarkerRequest markerRequest);

public slots:
    void handleDataReceived(QByteArray data);

private:
    int state;
    QString requestString;
    char startChar;
    char endChar;
};

#endif // SERIALPARSER_H
