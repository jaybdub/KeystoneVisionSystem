#ifndef CAMERAVIEWPORTWIDGET_H
#define CAMERAVIEWPORTWIDGET_H

#include <QWidget>
#include <QLabel>

class CameraViewportWidget : public QWidget
{
    Q_OBJECT
public:
    explicit CameraViewportWidget(QWidget *parent = 0);

signals:

public slots:

private:
    QLabel *imageLabel;
};

#endif // CAMERAVIEWPORTWIDGET_H
