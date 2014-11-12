#ifndef SERIALPORTTERMINALWIDGET_H
#define SERIALPORTTERMINALWIDGET_H

#include <QWidget>
#include <QPlainTextEdit>
#include <QLineEdit>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QCheckBox>
#include <QLabel>
#include <QScrollBar>
#include <QtCore>
class SerialPortTerminalWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SerialPortTerminalWidget(QWidget *parent = 0);

signals:
    void sendDataEntered(QString data);
    void sendDataEnteredNewlineAttached(QString data);
public slots:
    void handleDataReceived(QByteArray data);
    void handleDataSent(QByteArray data);
private slots:
    void handleSendDataEntered();
private:
    QPlainTextEdit *sentPlainTextEdit;
    QPlainTextEdit *receivedPlainTextEdit;
    QLineEdit *sendLineEdit;
    QPushButton *sendPushButton;
    QVBoxLayout *mainVBoxLayout;
    QHBoxLayout *sendHBoxLayout;
    QCheckBox *sentAutoscrollCheckBox;
    QCheckBox *receivedAutoscrollCheckBox;
    QLabel *sentLabel;
    QLabel *receivedLabel;
    QHBoxLayout *sentHBoxLayout;
    QHBoxLayout *receivedHBoxLayout;

};

#endif // SERIALPORTTERMINALWIDGET_H
