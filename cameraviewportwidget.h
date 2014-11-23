#ifndef CAMERAVIEWPORTWIDGET_H
#define CAMERAVIEWPORTWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class CameraViewportWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CameraViewportWidget(QWidget *parent = 0);

signals:

public slots:
    void setImage(QImage *image);

private:
    QVBoxLayout *mainVBoxLayout;
    QLabel *imageLabel;
    QImage *qImage;
};

#endif // CAMERAVIEWPORTWIDGET_H
