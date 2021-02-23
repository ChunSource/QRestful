#ifndef QWEBBOOT_H
#define QWEBBOOT_H

#include <QObject>
#include <QMap>
#include <iostream>
#include <functional>
#include "qhttpanalysis.h"
#include <QTime>

class QWebBoot : public QObject
{
    Q_OBJECT
public:
    explicit QWebBoot(QObject *parent = nullptr);
    
    template <typename  T>
    void bindFunction(QString url,void (T::*pf)(QHttpanalysis&), T* point)
    {
        std::function<void (QHttpanalysis&)> tmpfunction = std::bind(pf, point, std::placeholders::_1);
        function_map[url] = tmpfunction;
    }
    
    virtual void callUrlFunction(QString url,QHttpanalysis& http);
    
    virtual std::function<void (QHttpanalysis&)> getFunction(QString url);
    
    static QString rootUrl;
private:
    QMap<QString,std::function<void (QHttpanalysis&)>> function_map;
    
};

#endif // QWEBBOOT_H
