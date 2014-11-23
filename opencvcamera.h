#ifndef OPENCVCAMERA_H
#define OPENCVCAMERA_H

#include <QObject>
#include <QImage>
#include <opencv2/opencv.hpp>

class OpenCvCamera : public QObject
{
    Q_OBJECT
public:
    explicit OpenCvCamera(QObject *parent = 0);
    ~OpenCvCamera();
    inline QImage cvMatToQImage( const cv::Mat &inMat );
    int getDeviceId();
    QSize getResolution();
    QImage qImage;

signals:
    void deviceIdChanged(int deviceId);
    void resolutionChanged(QSize resolution);
    void newImageAvailable(QImage *image);
    void newImageAvailable(cv::Mat *image);
    void deviceClosed();
    void deviceOpened();

public slots:
    void grabFrame();
    void setDeviceId(int deviceId);
    void setResolution(QSize resolution);
    void openDevice();
    void closeDevice();
    void changeDevice(int deviceId);
    void reopenDevice();

private slots:
    void applySetResolution();

private:
    int deviceId;
    QSize resolution;
    //inline QImage OpenCvCamera::cvMatToQImage( const cv::Mat &inMat );
    cv::Mat cvImage;
    cv::VideoCapture videoCapture;
};

#endif // OPENCVCAMERA_H
