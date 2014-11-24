#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "SerialPortWidget.h"
#include <QGridLayout>
#include "camerasettingswidget.h"
#include "cameraviewportwidget.h"
#include "opencvcamera.h"
#include <QTimer>
#include <QHBoxLayout>
#include "linuxvideocontrol.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    CameraSettingsWidget *cameraSettingsWidget;
    CameraViewportWidget *cameraViewportWidget;
    OpenCvCamera *openCvCamera;
    LinuxVideoControl *linuxVideoControl;
    QTimer *cameraQTimer;
    Ui::MainWindow *ui;
    QHBoxLayout *mainQHBoxLayout;
};

#endif // MAINWINDOW_H
