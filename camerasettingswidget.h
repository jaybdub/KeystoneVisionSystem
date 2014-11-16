#ifndef CAMERASETTINGSWIDGET_H
#define CAMERASETTINGSWIDGET_H

#include <QWidget>
#include <QComboBox>
#include <QSlider>
#include <QCheckBox>
#include <QSize>
#include <QGridLayout>
#include <QLabel>

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
    void setDeviceId(int deviceId);
    void setResolution(QSize resolution);
    void setSharpness(int sharpness);
    void setBrightness(int brightness);
    void setAutofocusEnabled(bool autofocusEnabled);
    void setFocusAbsolute(int focusAbsolute);
    void setDeviceIdOptions(QList<int> deviceIds);
    void setResolutionOptions(QList<QSize> resolutions);
private slots:
    void handleDeviceIdComboBoxIndexChanged();
    void handleResolutionComboBoxIndexChanged();
    void handleSharpnessSliderChanged();
    void handleBrightnessSliderChanged();
    void handleAutofocusEnabledCheckBoxChanged();
    void handleFocusAbsoluteSliderChanged();
    void disableFocusAbsoluteSlider(bool disabled);
private:
    QLabel *deviceIdLabel;
    QLabel *resolutionLabel;
    QLabel *sharpnessLabel;
    QLabel *brightnessLabel;
    QLabel *focusAbsoluteLabel;
    QComboBox *deviceIdComboBox;
    QComboBox *resolutionComboBox;
    QSlider *sharpnessSlider;
    QSlider *brightnessSlider;
    QCheckBox *autofocusEnabledCheckBox;
    QSlider *focusAbsoluteSlider;
    QGridLayout *mainGridLayout;
};

#endif // CAMERASETTINGSWIDGET_H
