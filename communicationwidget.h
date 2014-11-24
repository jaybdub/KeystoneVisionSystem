#ifndef COMMUNICATIONWIDGET_H
#define COMMUNICATIONWIDGET_H

#include <QWidget>
#include "markerrequestqueue.h"
#include "serialparser.h"
#include "serialportterminalwidget.h"
#include <QPushButton>
#include "serialportsettingswidget.h"
#include <QSerialPort>

class CommunicationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CommunicationWidget(QSerialPort* serialPort, QWidget *parent = 0);

signals:

public slots:
private:
    MarkerRequestQueue *markerRequestQueue;
    SerialPortTerminalWidget *serialPortTerminalWidget;
    SerialPortSettingsWidget *serialPortSettingsWidget;
    SerialParser *serialParser;
    QSerialPort *serialPort;
    QVBoxLayout *mainVBoxLayout;
    QPushButton *terminalPushButton;
    QPushButton *settingsPushButton;
};

#endif // COMMUNICATIONWIDGET_H
