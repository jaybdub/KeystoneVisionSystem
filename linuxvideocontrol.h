#ifndef LINUXVIDEOCONTROL_H
#define LINUXVIDEOCONTROL_H

#include <QObject>
#include <stdlib.h>

class LinuxVideoControl : public QObject
{
    Q_OBJECT
public:
    explicit LinuxVideoControl(QObject *parent = 0);

signals:
    void sharpnessChanged(int sharpness);
    void brightnessChanged(int brightness);
    void focusAbsoluteChanged(int focusAbsolute);
    bool autofocusEnabledChanged(bool autofocusEnabled);

public slots:
    void setSharpness(int sharpness);
    void setBrightness(int brightness);
    void setFocusAbsolute(int focusAbsolute);
    void setAutofocusEnabled(bool autofocusEnabled);
    void setDeviceId(int deviceId);

private:
    int deviceId;
};

#endif // LINUXVIDEOCONTROL_H
