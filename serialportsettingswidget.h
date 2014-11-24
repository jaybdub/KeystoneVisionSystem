#ifndef SERIALPORTSETTINGSWIDGET_H
#define SERIALPORTSETTINGSWIDGET_H

#include <QWidget>
#include <QSerialPort>
#include <QPushButton>
#include <QComboBox>
#include <QVBoxLayout>

class SerialPortSettingsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SerialPortSettingsWidget(QWidget *parent = 0);

signals:
    void baudRateChanged(qint32 baudRate);
    void parityChanged(QSerialPort::Parity parity);
    void stopBitsChanged(QSerialPort::StopBits stopBits);
    void dataBitsChanged(QSerialPort::DataBits dataBits);

public slots:
    void handleBaudRateChanged(qint32 baudRate);
    void handleParityChanged(QSerialPort::Parity parity);
    void handleStopBitsChanged(QSerialPort::StopBits stopBits);
    void handleDataBitsChanged(QSerialPort::DataBits dataBits);

private slots:
    void handleBaudRateComboBoxCurrentIndexChanged(QString text);
    void handleParityComboBoxCurrentIndexChanged(int index);
    void handleStopBitsComboBoxCurrentIndexChanged(int index);
    void handleDataBitsComboBoxCurrentIndexChanged(int index);

private:
    void initBaudRateComboBox(qint32 baudRate);
    void initParityComboBox(QSerialPort::Parity parity);
    void initStopBitsComboBox(QSerialPort::StopBits stopBits);
    void initDataBitsComboBox(QSerialPort::DataBits dataBits);
    QPushButton *applyPushButton;
    QComboBox *baudRateComboBox;
    QComboBox *parityComboBox;
    QComboBox *stopBitsComboBox;
    QComboBox *dataBitsComboBox;
    QVBoxLayout *mainVBoxLayout;

};

#endif // SERIALPORTSETTINGSWIDGET_H
