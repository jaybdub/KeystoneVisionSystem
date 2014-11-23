#include "cameraviewportwidget.h"

CameraViewportWidget::CameraViewportWidget(QWidget *parent) :
    QWidget(parent)
{
    imageLabel = new QLabel(this);
    imageLabel->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    mainVBoxLayout = new QVBoxLayout(this);
    this->setLayout(mainVBoxLayout);
    mainVBoxLayout->addWidget(imageLabel);


}

void CameraViewportWidget::setImage(QImage *image)
{
    qImage = image;
    imageLabel->setPixmap(QPixmap::fromImage(qImage->scaled(imageLabel->size(),Qt::KeepAspectRatio)));
}

