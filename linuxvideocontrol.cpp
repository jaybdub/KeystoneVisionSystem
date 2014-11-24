#include "linuxvideocontrol.h"

LinuxVideoControl::LinuxVideoControl(QObject *parent) :
    QObject(parent)
{
}

void LinuxVideoControl::setSharpness(int sharpness)
{
    QString command;
    command = command + QString("v4l2-ctl -d /dev/video");
    command = command + QString::number(deviceId);
    command = command + QString(" -c sharpness=");
    command = command + QString::number(sharpness);

    system(command.toStdString().c_str());
}

void LinuxVideoControl::setBrightness(int brightness)
{
    QString command;
    command = command + QString("v4l2-ctl -d /dev/video");
    command = command + QString::number(deviceId);
    command = command + QString(" -c brightness=");
    command = command + QString::number(brightness);

    system(command.toStdString().c_str());
}

void LinuxVideoControl::setFocusAbsolute(int focusAbsolute)
{
    QString command;
    command = command + QString("v4l2-ctl -d /dev/video");
    command = command + QString::number(deviceId);
    command = command + QString(" -c focus_absolute=");
    command = command + QString::number(focusAbsolute);

    system(command.toStdString().c_str());
}

void LinuxVideoControl::setAutofocusEnabled(bool autofocusEnabled)
{
    QString command;
    command = command + QString("v4l2-ctl -d /dev/video");
    command = command + QString::number(deviceId);
    command = command + QString(" -c focus_auto=");
    if(autofocusEnabled)
        command = command + QString("1");
    else {
        command = command + QString("0");
    }

    system(command.toStdString().c_str());
}

void LinuxVideoControl::setDeviceId(int deviceId)
{
    this->deviceId =  deviceId;
}
