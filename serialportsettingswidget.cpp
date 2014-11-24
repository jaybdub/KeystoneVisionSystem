#include "serialportsettingswidget.h"

SerialPortSettingsWidget::SerialPortSettingsWidget(QWidget *parent) :
    QWidget(parent)
{
    applyPushButton = new QPushButton("Apply",this);
    applyPushButton->hide();
    baudRateComboBox = new QComboBox(this);
    initBaudRateComboBox(9600);
    parityComboBox = new QComboBox(this);
    parityComboBox->hide();
    stopBitsComboBox = new QComboBox(this);
    stopBitsComboBox->hide();
    dataBitsComboBox = new QComboBox(this);
    dataBitsComboBox->hide();
    mainVBoxLayout = new QVBoxLayout;
    this->setLayout(mainVBoxLayout);
}

void SerialPortSettingsWidget::handleBaudRateChanged(qint32 baudRate)
{
    //TODO
}

void SerialPortSettingsWidget::handleParityChanged(QSerialPort::Parity parity)
{
    //TODO
}

void SerialPortSettingsWidget::handleStopBitsChanged(QSerialPort::StopBits stopBits)
{
    //TODO
}

void SerialPortSettingsWidget::handleDataBitsChanged(QSerialPort::DataBits dataBits)
{
    //TODO
}

void SerialPortSettingsWidget::handleBaudRateComboBoxCurrentIndexChanged(QString text)
{
    emit baudRateChanged(text.toInt());
}

void SerialPortSettingsWidget::handleParityComboBoxCurrentIndexChanged(int index)
{
    //TODO
}

void SerialPortSettingsWidget::handleStopBitsComboBoxCurrentIndexChanged(int index)
{
    //TODO
}

void SerialPortSettingsWidget::handleDataBitsComboBoxCurrentIndexChanged(int index)
{
    //TODO
}

void SerialPortSettingsWidget::initBaudRateComboBox(qint32 baudRate)
{
    baudRateComboBox->clear();
    baudRateComboBox->addItem(QString::number(QSerialPort::Baud1200));//0
    baudRateComboBox->addItem(QString::number(QSerialPort::Baud2400));//1
    baudRateComboBox->addItem(QString::number(QSerialPort::Baud4800));//2
    baudRateComboBox->addItem(QString::number(QSerialPort::Baud9600));//3
    baudRateComboBox->addItem(QString::number(QSerialPort::Baud19200));//4
    baudRateComboBox->addItem(QString::number(QSerialPort::Baud38400));//5
    baudRateComboBox->addItem(QString::number(QSerialPort::Baud57600));//6
    baudRateComboBox->addItem(QString::number(QSerialPort::Baud115200));//7
    connect(baudRateComboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(handleBaudRateComboBoxCurrentIndexChanged(QString)));
    baudRateComboBox->setCurrentIndex(3);
}

void SerialPortSettingsWidget::initParityComboBox(QSerialPort::Parity parity)
{
    //TODO
}

void SerialPortSettingsWidget::initStopBitsComboBox(QSerialPort::StopBits stopBits)
{
    //TODO
}

void SerialPortSettingsWidget::initDataBitsComboBox(QSerialPort::DataBits dataBits)
{
    //TODO
}
