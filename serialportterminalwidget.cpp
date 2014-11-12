#include "serialportterminalwidget.h"

SerialPortTerminalWidget::SerialPortTerminalWidget(QWidget *parent) :
    QWidget(parent)
{
    //Initialize widgets/layouts
    sentPlainTextEdit = new QPlainTextEdit(this);
    receivedPlainTextEdit = new QPlainTextEdit(this);
    sendLineEdit = new QLineEdit(this);
    sendPushButton = new QPushButton("Send",this);
    mainVBoxLayout = new QVBoxLayout(this);
    sendHBoxLayout = new QHBoxLayout(this);
    sentHBoxLayout = new QHBoxLayout(this);
    receivedHBoxLayout = new QHBoxLayout(this);
    sentAutoscrollCheckBox = new QCheckBox("Autoscroll",this);
    sentAutoscrollCheckBox->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    receivedAutoscrollCheckBox = new QCheckBox("Autoscroll",this);
    receivedAutoscrollCheckBox->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    sentLabel = new QLabel("Sent",this);
    receivedLabel = new QLabel("Received",this);

    //Define widget structure
    sendHBoxLayout->addWidget(sendLineEdit);
    sendHBoxLayout->addWidget(sendPushButton);

    sentHBoxLayout->addWidget(sentLabel);
    sentHBoxLayout->addWidget(sentAutoscrollCheckBox);

    receivedHBoxLayout->addWidget(receivedLabel);
    receivedHBoxLayout->addWidget(receivedAutoscrollCheckBox);

    this->setLayout(mainVBoxLayout);
    mainVBoxLayout->addLayout(sendHBoxLayout);
    mainVBoxLayout->addLayout(sentHBoxLayout);
    mainVBoxLayout->addWidget(sentPlainTextEdit);
    mainVBoxLayout->addLayout(receivedHBoxLayout);
    mainVBoxLayout->addWidget(receivedPlainTextEdit);

    connect(sendLineEdit,SIGNAL(returnPressed()),this,SLOT(handleSendDataEntered()));
    connect(sendPushButton,SIGNAL(pressed()),this,SLOT(handleSendDataEntered()));
}

void SerialPortTerminalWidget::handleDataReceived(QByteArray data)
{
    receivedPlainTextEdit->insertPlainText(QString(data));

    //Scroll to bottom if autoscrolling is enabled.
    if(receivedAutoscrollCheckBox->isChecked())
        receivedPlainTextEdit->verticalScrollBar()->setValue(receivedPlainTextEdit->verticalScrollBar()->maximum());
}

void SerialPortTerminalWidget::handleDataSent(QByteArray data)
{
    sentPlainTextEdit->insertPlainText(QString(data));

    //Scroll to bottom if autoscrolling is enabled.
    if(sentAutoscrollCheckBox->isChecked())
        sentPlainTextEdit->verticalScrollBar()->setValue(sentPlainTextEdit->verticalScrollBar()->maximum());
}

void SerialPortTerminalWidget::handleSendDataEntered()
{
    emit sendDataEntered(sendLineEdit->text());
    emit sendDataEnteredNewlineAttached(sendLineEdit->text()+QChar('\n'));
    qDebug() << sendLineEdit->text();
    sendLineEdit->clear();
}
