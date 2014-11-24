#include "communicationwidget.h"

CommunicationWidget::CommunicationWidget(QSerialPort *serialPort, QWidget *parent) :
    QWidget(parent)
{
    this->serialPort = serialPort;
    mainVBoxLayout = new QVBoxLayout(this);
    this->setLayout(mainVBoxLayout);
    markerRequestQueue = new MarkerRequestQueue(this);
    serialParser = new SerialParser(this);
    serialPortTerminalWidget = new SerialPortTerminalWidget(this);
    serialPortTerminalWidget->setWindowFlags(Qt::Window | Qt::CustomizeWindowHint |
                                        Qt::WindowTitleHint | Qt::WindowSystemMenuHint |
                                        Qt::WindowCloseButtonHint);//Make the config a pop-up window
    terminalPushButton = new QPushButton("Terminal",this);
    settingsPushButton = new QPushButton("Settings",this);
    settingsPushButton->hide();

    serialPortSettingsWidget = new SerialPortSettingsWidget(this);

    mainVBoxLayout->addWidget(serialPortSettingsWidget);
    mainVBoxLayout->addWidget(terminalPushButton);
}
