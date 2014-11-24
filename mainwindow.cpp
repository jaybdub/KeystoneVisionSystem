#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set up opencv camera
    openCvCamera = new OpenCvCamera(this);

    //Set up camera settings widget
    QList<int> cameraDeviceIds;
    cameraDeviceIds.append(0);
    cameraDeviceIds.append(1);

    QList<QSize> resolutions;
    resolutions.append(QSize(1920,1080));
    resolutions.append(QSize(640,480));

    cameraSettingsWidget = new CameraSettingsWidget(this);
    cameraSettingsWidget->setWindowFlags(Qt::Window | Qt::CustomizeWindowHint |
                                         Qt::WindowTitleHint | Qt::WindowSystemMenuHint |
                                         Qt::WindowCloseButtonHint);
    cameraSettingsWidget->setDeviceIdOptions(cameraDeviceIds);
    cameraSettingsWidget->setResolutionOptions(resolutions);
    cameraSettingsWidget->show();
    connect(cameraSettingsWidget,SIGNAL(deviceIdChanged(int)),openCvCamera,SLOT(setDeviceId(int)));
    connect(cameraSettingsWidget,SIGNAL(resolutionChanged(QSize)),openCvCamera,SLOT(setResolution(boolQSize)));
    connect(openCvCamera,SIGNAL(resolutionChanged(QSize)),cameraSettingsWidget,SLOT(setResolution(QSize)));
    connect(openCvCamera,SIGNAL(deviceIdChanged(int)),cameraSettingsWidget,SLOT(setDeviceId(int)));

    //Set up camera viewport
    cameraViewportWidget = new CameraViewportWidget(this);
    connect(openCvCamera,SIGNAL(newImageAvailable(QImage*)),cameraViewportWidget,SLOT(setImage(QImage*)));

    //Set up linux video control
    linuxVideoControl = new LinuxVideoControl(this);
    connect(openCvCamera,SIGNAL(deviceIdChanged(int)),linuxVideoControl,SLOT(setDeviceId(int)));
    connect(cameraSettingsWidget,SIGNAL(brightnessChanged(int)),linuxVideoControl,SLOT(setBrightness(int)));
    connect(cameraSettingsWidget,SIGNAL(sharpnessChanged(int)),linuxVideoControl,SLOT(setSharpness(int)));
    connect(cameraSettingsWidget,SIGNAL(focusAbsoluteChanged(int)),linuxVideoControl,SLOT(setFocusAbsolute(int)));
    connect(cameraSettingsWidget,SIGNAL(autofocusEnabledChanged(int)),linuxVideoControl,SLOT(setFocusAbsolute(int)));
    connect(cameraSettingsWidget,SIGNAL(autofocusEnabledChanged(bool)),linuxVideoControl,SLOT(setAutofocusEnabled(bool)));
    linuxVideoControl->setBrightness(cameraSettingsWidget->brightness());
    linuxVideoControl->setFocusAbsolute(cameraSettingsWidget->focusAbsolute());
    linuxVideoControl->setAutofocusEnabled(cameraSettingsWidget->autofocusEnabled());
    linuxVideoControl->setSharpness(cameraSettingsWidget->sharpness());

    //Set up camera timer
    cameraQTimer = new QTimer(this);
    cameraQTimer->start(20);
    connect(cameraQTimer,SIGNAL(timeout()),openCvCamera,SLOT(grabFrame()));

    //Add viewport to main widget
    ui->horizontalLayout_2->addWidget(cameraViewportWidget);

    //Apply initial settings
    openCvCamera->setDeviceId(cameraSettingsWidget->deviceId());
    openCvCamera->setResolution(cameraSettingsWidget->resolution());

}

MainWindow::~MainWindow()
{
    delete ui;
}
