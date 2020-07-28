#include "qhttpserver.h"

void run(int id)
{
    qDebug()<<"run..";
    QTcpSocket* socket = nullptr;
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(id))
    {
        qDebug()<<socket->errorString();
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
        //this->exit();
    }
    //Qt::DirectConnection   发送者执行
    //connect(socket,&QTcpSocket::readyRead,this,&QHttpTask::readMessage,Qt::DirectConnection);
    
}

QHttpServer::QHttpServer(QObject *parent) : QTcpServer(parent)
{
    
}

void QHttpServer::startServer(QString ip, int port)
{
    this->listen(QHostAddress(ip),port);
}

void QHttpServer::stopServer()
{
    if(this->isListening())
    {
        this->close();
    }
}

void QHttpServer::incomingConnection(qintptr handle)
{
    //QHttpTask *thread  = new QHttpTask(handle);
    QtConcurrent::run(this,&QHttpServer::run,handle);
    //connect(thread,&QHttpTask::finished,thread,&QHttpTask::deleteLater,Qt::QueuedConnection);
    //thread->start();
}

void QHttpServer::run(qintptr id)
{
    //qDebug()<<"run..";
    QTcpSocket* socket = nullptr;
    socket = new QTcpSocket();
    if(!socket->setSocketDescriptor(id))
    {
        qDebug()<<socket->errorString();
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
        //this->exit();
    }
    //Qt::DirectConnection   发送者执行
    //connect(socket,&QTcpSocket::readyRead,this,&QHttpTask::readMessage,Qt::DirectConnection);
    
}
