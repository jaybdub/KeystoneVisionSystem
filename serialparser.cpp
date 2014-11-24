#include "serialparser.h"

SerialParser::SerialParser(QObject *parent) :
    QObject(parent)
{
    state = 0;
    requestString = QString("");
    startChar = '#';
    endChar = '*';
}

void SerialParser::handleDataReceived(QByteArray data)
{

}
