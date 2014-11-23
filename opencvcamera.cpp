#include "opencvcamera.h"

OpenCvCamera::OpenCvCamera(QObject *parent) :
    QObject(parent)
{
    resolution = QSize(640,480);
    connect(this,SIGNAL(resolutionChanged(QSize)),this,SLOT(applySetResolution()));
    connect(this,SIGNAL(deviceIdChanged(int)),this,SLOT(reopenDevice()));
    connect(this,SIGNAL(deviceOpened()),this,SLOT(applySetResolution()));
}
OpenCvCamera::~OpenCvCamera(){
    videoCapture.release();
}

int OpenCvCamera::getDeviceId()
{
    return deviceId;
}

QSize OpenCvCamera::getResolution()
{
    return resolution;
}

void OpenCvCamera::grabFrame()
{
    if(videoCapture.isOpened()) {
        //_video_capture.
        //_video_capture >> _image;
        videoCapture.read(cvImage);
        qImage = cvMatToQImage(cvImage);
        emit newImageAvailable(&cvImage);
        emit newImageAvailable(&qImage);
    }
}

void OpenCvCamera::setDeviceId(int deviceId)
{
    if(this->deviceId!=deviceId){
        this->deviceId = deviceId;
        emit deviceIdChanged(this->deviceId);
    }
}

void OpenCvCamera::setResolution(QSize resolution)
{
    if(this->resolution!=resolution){
        this->resolution = resolution;
        emit resolutionChanged(this->resolution);
    }
}
void OpenCvCamera::applySetResolution()
{
    if(videoCapture.isOpened()){
        connect(this,SIGNAL(deviceOpened()),this,SLOT(applySetResolution()));
        videoCapture.set(CV_CAP_PROP_FRAME_WIDTH,resolution.width());
        videoCapture.set(CV_CAP_PROP_FRAME_HEIGHT, resolution.height());
    }
}

void OpenCvCamera::openDevice()//close device
//emit device closed
{
    //open this->deviceId();
    if(videoCapture.open(deviceId))
        emit deviceOpened();
}

void OpenCvCamera::closeDevice()
{
    videoCapture.release();
    emit deviceClosed();
}

void OpenCvCamera::reopenDevice()
{
    this->closeDevice();
    this->openDevice();
}

void OpenCvCamera::changeDevice(int deviceId)
{
    this->setDeviceId(deviceId);
}

inline QImage OpenCvCamera::cvMatToQImage( const cv::Mat &inMat )
{
    switch ( inMat.type() )
    {
       // 8-bit, 4 channel
       case CV_8UC4:
       {
          QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB32 );

          return image;
       }

       // 8-bit, 3 channel
       case CV_8UC3:
       {
          QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB888 );

          return image.rgbSwapped();
       }

       // 8-bit, 1 channel
       case CV_8UC1:
       {
          static QVector<QRgb>  sColorTable;

          // only create our color table once
          if ( sColorTable.isEmpty() )
          {
             for ( int i = 0; i < 256; ++i )
                sColorTable.push_back( qRgb( i, i, i ) );
          }

          QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_Indexed8 );

          image.setColorTable( sColorTable );

          return image;
       }

       default:
          //qWarning() << "ASM::cvMatToQImage() - cv::Mat image type not handled in switch:" << inMat.type();
          break;
    }

    return QImage();
}
