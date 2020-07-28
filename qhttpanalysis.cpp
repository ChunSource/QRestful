#include "qhttpanalysis.h"
#include <QDebug>

QHttpanalysis::QHttpanalysis(QByteArray inputMessage)
{
    this->message = inputMessage;
    analysis();
}

QHttpanalysis::QHttpanalysis(const QHttpanalysis &http)
{
    this->message = http.message;
    analysis();
}

void QHttpanalysis::analysis()
{
    
    QStringList list = QString(this->message).split("\r\n");
    if(list.size() ==0)
    {
        isError = true;
        errorString = "没有报文";
        return;
    }
    
    analysisHead(list[0]);
    
    for( int i=1;i<list.size();i++)
    {
        if(i+1 >= list.size())
        {
            map["body"] = list[i].toUtf8();
        }else
        {
            analysisHeader(list[i]);
        }
        
    }
}

void QHttpanalysis::analysisHead(QString headstr)
{
    //qDebug()<<"head: "<<headstr.toUtf8();
    QStringList list = headstr.split(" ");
    if(list.size() != 3)
    {
        isError = true;
        errorString = "请求头错误";
        qDebug()<<errorString;
        return;
    }
    
    QString method = list.at(0);  //method
    if(method !="GET" && method != "POST")
    {
        isError = true;
        errorString = "method 错误: "+method;
        qDebug()<<errorString;
        return;
    }
    
    QString url = list.at(1);  //url
    if(url =="")
    {
        isError = true;
        errorString = "路径为空";
        qDebug()<<errorString;
        return;
    }
    
    QString protocol = list.at(2);
    if(protocol.indexOf("HTTP") == 1)
    {
        isError = true;
        errorString = "协议错误";
        qDebug()<<errorString;
        return;
    }
    
    
    map["method"]=method.toUtf8();
    map["url"]=url.toUtf8();
    map["protocol"]=protocol.toUtf8();
}

void QHttpanalysis::analysisHeader(QString headerstr)
{
    //qDebug()<<"header: "<<headerstr;
    QStringList list = headerstr.split("\r\n");
    for(int i=0;i<list.size();i++)  //处理每一行的header
    {
        QString tmp = list.at(i);
        int midIndex = tmp.indexOf(":");
        int rightLength = tmp.length() -midIndex -1;  //右边开始的长度
        
        
        if(midIndex ==-1)
        {
            continue;
        }
        
        QString left = tmp.mid(0,midIndex);
        QString right = tmp.mid(midIndex+1,rightLength);
        //qDebug()<<"left: "<<left;
        //qDebug()<<"right: "<<right;
        map[left] = right.toUtf8();
    }
}


QString QHttpanalysis::getUrl()
{
    return map["url"];
}

QString QHttpanalysis::getMethod()
{
    return map["method"];
}

QString QHttpanalysis::getProtocol()
{
    return map["protocol"];
}

QString QHttpanalysis::getHeader(QString header)
{
    QString  result = "";
    result = map[header];
    return result;
}

QByteArray QHttpanalysis::getBody()
{
    return map["body"];
}

QByteArray QHttpanalysis::build()
{
//    QByteArray buffer;
//    QMapIterator<QString,QString>i(map);
    
//    for(;i.hasNext();)
//    {
//        qDebug()<<""<<i.key()<<""<<i.next().value();
//        if(i.key() != "url" && i.key() != "protocol" && i.key() != "method")
//        {
//            buffer += i.key()+":"+i.value()+"\r\n";
//        }
//    }
}

QByteArray QHttpanalysis::getMessage()
{
    return this->message;
}

void QHttpanalysis::setMessage(QByteArray inputMessage)
{
    this->message = inputMessage;
}

bool QHttpanalysis::checkNegative(const int &number)
{
    if(number == -1)
    {
        isError = true;
        return true;
    }
    return false;
}
