#include "camerasettingswidget.h"

CameraSettingsWidget::CameraSettingsWidget(QWidget *parent) :
    QWidget(parent)
{
    deviceIdComboBox = new QComboBox(this);
    resolutionComboBox = new QComboBox(this);
    sharpnessSlider = new QSlider(Qt::Horizontal, this);
    brightnessSlider = new QSlider(Qt::Horizontal, this);
    focusAbsoluteSlider = new QSlider(Qt::Horizontal, this);
    autofocusEnabledCheckBox = new QCheckBox("Autofocus Enabled", this);

    mainVBoxLayout = new QVBoxLayout(this);
    this->setLayout(mainVBoxLayout);
    mainVBoxLayout->addWidget(deviceIdComboBox);
    mainVBoxLayout->addWidget(resolutionComboBox);
    mainVBoxLayout->addWidget(sharpnessSlider);
    mainVBoxLayout->addWidget(brightnessSlider);
    mainVBoxLayout->addWidget(focusAbsoluteSlider);
    mainVBoxLayout->addWidget(autofocusEnabledCheckBox);
}

int CameraSettingsWidget::deviceId()
{
    return deviceIdComboBox->currentText().toInt();
}

QSize CameraSettingsWidget::resolution()
{
    QList<QString> dimStrings = resolutionComboBox->currentText().split("x",QString::SkipEmptyParts);
    if (dimStrings.size()==2)
        return QSize(dimStrings.at(0).toInt(),dimStrings.at(1).toInt());
    else
        return QSize(0,0);
}

int CameraSettingsWidget::sharpness()
{
    return sharpnessSlider->value();
}

int CameraSettingsWidget::brightness()
{
    return brightnessSlider->value();
}

bool CameraSettingsWidget::autofocusEnabled()
{
    return autofocusEnabledCheckBox->isChecked();
}

int CameraSettingsWidget::focusAbsolute()
{
    return focusAbsoluteSlider->value();
}


void CameraSettingsWidget::handleDeviceIdChanged(int deviceId)
{
    deviceIdComboBox->setCurrentText(QString::number(deviceId));
}

void CameraSettingsWidget::handleResolutionChanged(QSize resolution)
{
    // "<width>x<height>"
    resolutionComboBox->setCurrentText(QString::number(resolution.width())
                                       +QString("x")
                                       +QString::number(resolution.height()));
}

void CameraSettingsWidget::handleSharpnessChanged(int sharpness)
{
    sharpnessSlider->setValue(sharpness);
}

void CameraSettingsWidget::handleBrightnessChanged(int brightness)
{
    brightnessSlider->setValue(brightness);
}

void CameraSettingsWidget::handleAutofocusEnabledChanged(bool autofocusEnabled)
{
    autofocusEnabledCheckBox->setChecked(autofocusEnabled);
}

void CameraSettingsWidget::handleFocusAbsoluteChanged(int focusAbsolute)
{
    focusAbsoluteSlider->setValue(focusAbsolute);
}
