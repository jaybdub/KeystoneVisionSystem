#ifndef CAMERASETTINGSWIDGET_H
#define CAMERASETTINGSWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QSlider>
#include <QCheckBox>
#include <QSize>
#include <QVBoxLayout>

class CameraSettingsWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CameraSettingsWidget(QWidget *parent = 0);
    int deviceId();
    QSize resolution();
    int sharpness();
    int brightness();
    bool autofocusEnabled();
    int focusAbsolute();

signals:
    void deviceIdChanged(int deviceId);
    void resolutionChanged(QSize resolution);
    void sharpnessChanged(int sharpness);
    void brightnessChanged(int brightness);
    void autofocusEnabledChanged(bool autofocusEnabled);
    void focusAbsoluteChanged(int focusAbsolute);

public slots:
    void handleDeviceIdChanged(int deviceId);
    void handleResolutionChanged(QSize resolution);
    void handleSharpnessChanged(int sharpness);
    void handleBrightnessChanged(int brightness);
    void handleAutofocusEnabledChanged(bool autofocusEnabled);
    void handleFocusAbsoluteChanged(int focusAbsolute);

private:
    QComboBox *deviceIdComboBox;
    QComboBox *resolutionComboBox;
    QSlider *sharpnessSlider;
    QSlider *brightnessSlider;
    QCheckBox *autofocusEnabledCheckBox;
    QSlider *focusAbsoluteSlider;
    QVBoxLayout *mainVBoxLayout;
};

#endif // CAMERASETTINGSWIDGET_H
