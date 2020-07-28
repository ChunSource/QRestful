#include <QCoreApplication>
#include <QFile>
#include "qhttpserver.h"
#include "qhttpanalysis.h"
#include "helloboot.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    QFile file("mess.txt");
//    file.open(QIODevice::ReadWrite);
//   QByteArray txt = file.readAll();
//   file.close();
//   QHttpanalysis http(txt);
   
   
//   QWebBoot* poot = new HelloBoot();
//   poot->callUrlFunction("/",http);
   
    QHttpServer server;
    server.startServer("127.0.0.1",8008);
    
    return a.exec();
}
