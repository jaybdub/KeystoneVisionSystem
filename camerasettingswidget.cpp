#include "camerasettingswidget.h"

CameraSettingsWidget::CameraSettingsWidget(QWidget *parent) :
    QWidget(parent)
{
    deviceIdLabel = new QLabel("Device Id",this);
    deviceIdComboBox = new QComboBox(this);
    resolutionLabel = new QLabel("Resolution",this);
    resolutionComboBox = new QComboBox(this);
    sharpnessLabel = new QLabel("Sharpness",this);
    sharpnessSlider = new QSlider(Qt::Horizontal, this);
    sharpnessSlider->setRange(0,255);
    brightnessLabel = new QLabel("Brightness",this);
    brightnessSlider = new QSlider(Qt::Horizontal, this);
    brightnessSlider->setRange(0,255);
    focusAbsoluteLabel = new QLabel("Focus",this);
    focusAbsoluteSlider = new QSlider(Qt::Horizontal, this);
    focusAbsoluteSlider->setRange(0,255);
    autofocusEnabledCheckBox = new QCheckBox("Autofocus Enabled", this);

    mainGridLayout = new QGridLayout(this);
    this->setLayout(mainGridLayout);
    mainGridLayout->addWidget(deviceIdLabel,0,0);
    mainGridLayout->addWidget(deviceIdComboBox,0,1);
    mainGridLayout->addWidget(resolutionLabel,1,0);
    mainGridLayout->addWidget(resolutionComboBox,1,1);
    mainGridLayout->addWidget(sharpnessLabel,2,0);
    mainGridLayout->addWidget(sharpnessSlider,2,1);
    mainGridLayout->addWidget(brightnessLabel,3,0);
    mainGridLayout->addWidget(brightnessSlider,3,1);
    mainGridLayout->addWidget(focusAbsoluteLabel,4,0);
    mainGridLayout->addWidget(focusAbsoluteSlider,4,1);
    mainGridLayout->addWidget(autofocusEnabledCheckBox,5,0,1,2);

    connect(deviceIdComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(handleDeviceIdComboBoxIndexChanged()));
    connect(resolutionComboBox,SIGNAL(currentIndexChanged(int)),this,SLOT(handleResolutionComboBoxIndexChanged()));
    connect(sharpnessSlider,SIGNAL(valueChanged(int)),this,SLOT(handleSharpnessSliderChanged()));
    connect(brightnessSlider,SIGNAL(valueChanged(int)),this,SLOT(handleBrightnessSliderChanged()));
    connect(focusAbsoluteSlider,SIGNAL(valueChanged(int)),this,SLOT(handleFocusAbsoluteSliderChanged()));
    connect(autofocusEnabledCheckBox,SIGNAL(toggled(bool)),this,SLOT(handleAutofocusEnabledCheckBoxChanged()));
    connect(autofocusEnabledCheckBox,SIGNAL(toggled(bool)),this,SLOT(disableFocusAbsoluteSlider(bool)));
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


void CameraSettingsWidget::setDeviceId(int deviceId)
{
    deviceIdComboBox->setCurrentText(QString::number(deviceId));
}

void CameraSettingsWidget::setResolution(QSize resolution)
{
    // "<width>x<height>"
    resolutionComboBox->setCurrentText(QString::number(resolution.width())
                                       +QString("x")
                                       +QString::number(resolution.height()));
}

void CameraSettingsWidget::setSharpness(int sharpness)
{
    sharpnessSlider->setValue(sharpness);
}

void CameraSettingsWidget::setBrightness(int brightness)
{
    brightnessSlider->setValue(brightness);
}

void CameraSettingsWidget::setAutofocusEnabled(bool autofocusEnabled)
{
    autofocusEnabledCheckBox->setChecked(autofocusEnabled);
}

void CameraSettingsWidget::setFocusAbsolute(int focusAbsolute)
{
    focusAbsoluteSlider->setValue(focusAbsolute);
}

void CameraSettingsWidget::setDeviceIdOptions(QList<int> deviceIds)
{
    QList<QString> deviceIdStrings;
    for(int i=0;i<deviceIds.length();i++)
        deviceIdStrings.append(QString::number(deviceIds.at(i)));

    deviceIdComboBox->clear();
    deviceIdComboBox->addItems(deviceIdStrings);
}

void CameraSettingsWidget::setResolutionOptions(QList<QSize> resolutions)
{
    QList<QString> resolutionStrings;
    for(int i=0;i<resolutions.length();i++){
        resolutionStrings.append(QString::number(resolutions.at(i).width())+QString("x")
                                 +QString::number(resolutions.at(i).height()));
    }

    resolutionComboBox->clear();
    resolutionComboBox->addItems(resolutionStrings);
}

void CameraSettingsWidget::handleDeviceIdComboBoxIndexChanged()
{
    emit deviceIdChanged(deviceId());
}

void CameraSettingsWidget::handleResolutionComboBoxIndexChanged()
{
    emit resolutionChanged(resolution());
}

void CameraSettingsWidget::handleSharpnessSliderChanged()
{
    emit sharpnessChanged(sharpness());
}

void CameraSettingsWidget::handleBrightnessSliderChanged()
{
    emit brightnessChanged(brightness());
}

void CameraSettingsWidget::handleAutofocusEnabledCheckBoxChanged()
{
    emit autofocusEnabledChanged(autofocusEnabled());
    emit autofocusEnabledChanged(focusAbsolute());
}

void CameraSettingsWidget::handleFocusAbsoluteSliderChanged()
{
    emit focusAbsoluteChanged(focusAbsolute());
}
void CameraSettingsWidget::disableFocusAbsoluteSlider(bool disabled)
{
    focusAbsoluteSlider->setDisabled(disabled);
}
