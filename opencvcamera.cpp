#include "opencvcamera.h"

OpenCvCamera::OpenCvCamera(QObject *parent) :
    QObject(parent)
{
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
    //Code to grab frame
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

void OpenCvCamera::openDevice()
{
    //open this->deviceId();
    //set resolution etc.
    //emit device opened
}

void OpenCvCamera::closeDevice()
{
    //close device
    //emit device closed
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

//inline QImage OpenCvCamera::cvMatToQImage( const cv::Mat &inMat )
//{
//    switch ( inMat.type() )
//    {
//       // 8-bit, 4 channel
//       case CV_8UC4:
//       {
//          QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB32 );

//          return image;
//       }

//       // 8-bit, 3 channel
//       case CV_8UC3:
//       {
//          QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB888 );

//          return image.rgbSwapped();
//       }

//       // 8-bit, 1 channel
//       case CV_8UC1:
//       {
//          static QVector<QRgb>  sColorTable;

//          // only create our color table once
//          if ( sColorTable.isEmpty() )
//          {
//             for ( int i = 0; i < 256; ++i )
//                sColorTable.push_back( qRgb( i, i, i ) );
//          }

//          QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_Indexed8 );

//          image.setColorTable( sColorTable );

//          return image;
//       }

//       default:
//          //qWarning() << "ASM::cvMatToQImage() - cv::Mat image type not handled in switch:" << inMat.type();
//          break;
//    }

//    return QImage();
//}
