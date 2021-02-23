#include "helloboot.h"
#include <QDebug>


HelloBoot::HelloBoot(QObject *parent) : QWebBoot(parent)
{
    HelloBoot::rootUrl = "/";  // 当前实例负责URL

    this->bindFunction("/index",&HelloBoot::hello,this);
    this->bindFunction("/404",&HelloBoot::NotFound,this);
}

void HelloBoot::hello(QHttpanalysis &http)
{
    QByteArray out = http.response.toUtf8() + "[{\"volume\":289069,\"price\":38.6,\"avgPrice\":38.94762,\"time\":1595597400000},{\"volume\":58093,\"price\":39.45,\"avgPrice\":38.938198,\"time\":1595597460000},{\"volume\":41453,\"price\":39.64,\"avgPrice\":39.015503,\"time\":1595597520000},{\"volume\":40571,\"price\":39.64,\"avgPrice\":39.066486,\"time\":1595597580000},{\"volume\":26780,\"price\":39.02,\"avgPrice\":39.09142,\"time\":1595597640000},{\"volume\":22013,\"price\":39.51,\"avgPrice\":39.096222,\"time\":1595597700000}]";
    http.setMessage(out);
    //qDebug()<<"hello: "<<http.getMessage();
}

void HelloBoot::NotFound(QHttpanalysis &http)
{
    QByteArray out = http.response.toUtf8() + "404 NotFound";
    http.setMessage(out);
    //qDebug()<<"NotFound: "<<http.getMessage();
}

