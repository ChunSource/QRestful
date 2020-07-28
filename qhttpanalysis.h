#ifndef QHTTPANALYSIS_H
#define QHTTPANALYSIS_H

#include <QObject>
#include <QByteArray>
#include <QStringList>
#include <QMap>
#include <QTime>


class QHttpanalysis
{
public:
    QHttpanalysis(QByteArray inputMessage);
    QHttpanalysis(const QHttpanalysis& http);
    QString getUrl();
    QString getMethod();
    QString getProtocol();
    QString getHeader(QString header);
    QByteArray getBody();
    QByteArray build();
    QByteArray getMessage();
    void setMessage(QByteArray inputMessage);
    
    QString response="HTTP/1.1200OK\r\nServer:ChunSource\r\nContent-Type:application/json;charset=utf-8\r\n\r\n";
private:
    QByteArray message;  //接受的报文
    
    QMap<QString,QByteArray> map;  //保存路由
    
    bool isError = false;    //错误则返回
    
    QString errorString = "";  //错误信息
    
    
    inline bool checkNegative(const int& number);  //检查indexof的结果
    
    void analysis();
    
    void analysisHead(QString headstr);
    
    void analysisHeader(QString headerstr);
};

#endif // QHTTPANALYSIS_H
