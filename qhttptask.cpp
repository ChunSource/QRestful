#include "qhttptask.h"
#include <QDebug>

QHttpTask::QHttpTask(qintptr handler, QObject *parent) : QThread(parent)
{
    this->ThreadId = handler;
}

QHttpTask::~QHttpTask()
{
}

void QHttpTask::run()
{
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(ThreadId))
    {
        //qDebug()<<socket->errorString();
        return;
    }
    
    if(socket->waitForReadyRead())
    {
        QTime startTime;
        startTime.start();
        QByteArray httpBuffer = socket->readAll();
        
        //qDebug()<<"新接收到的报文: "<<httpBuffer;
        
        
        QWebBoot* poot = new HelloBoot();
        //qDebug()<<"实例化耗时 ="<<startTime.elapsed()<<"ms";
        
        QHttpanalysis http(httpBuffer);
        //qDebug()<<"解析耗时 ="<<startTime.elapsed()<<"ms";
            
        poot->callUrlFunction(http.getUrl(),http);
        //qDebug()<<"调用耗时 ="<<startTime.elapsed()<<"ms";
        socket->write(http.getMessage());
        socket->waitForBytesWritten();
        //qDebug()<<"发送完成 ="<<startTime.elapsed()<<"ms";
        socket->disconnectFromHost();
        socket->deleteLater();
        this->exit();
    }
    //Qt::DirectConnection   发送者执行
    //connect(socket,&QTcpSocket::readyRead,this,&QHttpTask::readMessage,Qt::DirectConnection);
    
    
    this->exec();
}

void QHttpTask::readMessage()
{
//    QTime startTime;
//    startTime.start();
//    QByteArray httpBuffer = socket->readAll();
    
//    qDebug()<<"新接收到的报文: "<<httpBuffer;
    
    
//    QWebBoot* poot = new HelloBoot();
//    qDebug()<<"实例化耗时 ="<<startTime.elapsed()<<"ms";
    
//    QHttpanalysis http(httpBuffer);
//    qDebug()<<"解析耗时 ="<<startTime.elapsed()<<"ms";
        
//    poot->callUrlFunction(http.getUrl(),http);
//    qDebug()<<"调用耗时 ="<<startTime.elapsed()<<"ms";
//    socket->write(http.getMessage());
//    socket->waitForBytesWritten();
//    qDebug()<<"发送完成 ="<<startTime.elapsed()<<"ms";
//    socket->disconnectFromHost();
//    socket->deleteLater();
//    this->exit();
}
