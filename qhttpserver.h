#ifndef QHTTPSERVER_H
#define QHTTPSERVER_H

#include <QObject>
#include <QTcpServer>
#include <QtConcurrent/QtConcurrent>
#include "qhttptask.h"

class QHttpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit QHttpServer(QObject *parent = nullptr);
    void startServer(QString ip,int port);
    void stopServer();
    
protected:
   void incomingConnection(qintptr handle);
   void run(qintptr id);
};

#endif // QHTTPSERVER_H
