#ifndef QHTTPTASK_H
#define QHTTPTASK_H

#include <QObject>
#include <QThread>
#include <QTcpSocket>
#include "helloboot.h"
#include <QTime>

class QHttpTask : public QThread
{
    Q_OBJECT
public:
    explicit QHttpTask(qintptr handler,QObject *parent = nullptr);
    ~QHttpTask();
private:
    void run();
    
    qintptr ThreadId;//记录socketId
    
    QTcpSocket* socket = nullptr;
    
private slots:
    void readMessage();
};

#endif // QHTTPTASK_H
