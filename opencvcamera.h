#ifndef OPENCVCAMERA_H
#define OPENCVCAMERA_H

#include <QObject>
#include <QImage>

class OpenCvCamera : public QObject
{
    Q_OBJECT
public:
    explicit OpenCvCamera(QObject *parent = 0);
    //inline QImage OpenCvCamera::cvMatToQImage( const cv::Mat &inMat );
    int getDeviceId();
    QSize getResolution();

signals:
    void deviceIdChanged(int deviceId);
    void resolutionChanged(QSize resolution);
    void newFrameGrabbed(QImage *image);
    void deviceClosed();
    void deviceOpened();
//    void newImage(cv::Mat *image);

public slots:
    void grabFrame();
    void setDeviceId(int deviceId);
    void setResolution(QSize resolution);
    void openDevice();
    void closeDevice();
    void changeDevice(int deviceId);
    void reopenDevice();

private:
    int deviceId;
    QSize resolution;
    cv::VideoCapture videoCapture;
};

#endif // OPENCVCAMERA_H
