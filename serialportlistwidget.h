#ifndef SERIALPORTLISTWIDGET_H
#define SERIALPORTLISTWIDGET_H

#include <QWidget>
#include <QList>
#include "serialportwidget.h"
#include <QVBoxLayout>
#include <QSerialPortInfo>

class SerialPortListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SerialPortListWidget(QWidget *parent = 0);

signals:

public slots:
    void refreshPorts();

private:
    QList<SerialPortWidget*> serialPortWidgets;
    QVBoxLayout *mainLayout;
    QTimer *refreshPortsTimer;
    QWidget *spacer;
};

#endif // SERIALPORTLISTWIDGET_H
