#include "qwebboot.h"
#include <QDebug>

QString QWebBoot::rootUrl = "";
QWebBoot::QWebBoot(QObject *parent) : QObject(parent)
{
    
}

void QWebBoot::callUrlFunction(QString url, QHttpanalysis& http)
{
    //QTime time;
    //time.start();
    std::function<void (QHttpanalysis&)> fun = getFunction(url);
    if(fun == nullptr)
    {
        return;
    }
    fun(http);
    //qDebug()<<">>>>>>>>>调用fun耗时 ="<<time.elapsed()<<"ms";
}

std::function<void (QHttpanalysis&)> QWebBoot::getFunction(QString url)
{
    return function_map[url];
}


