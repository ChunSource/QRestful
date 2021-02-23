#ifndef HELLOBOOT_H
#define HELLOBOOT_H

#include <QObject>
#include <functional>
#include "qwebboot.h"

class HelloBoot : public QWebBoot
{
    Q_OBJECT
public:
    explicit HelloBoot(QObject *parent = nullptr);
    
    void hello(QHttpanalysis& http);
    void NotFound(QHttpanalysis& http);
signals:
    
};

#endif // HELLOBOOT_H
