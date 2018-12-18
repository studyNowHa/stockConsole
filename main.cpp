#include <QCoreApplication>
#include "stockthreadalldate.h"
#include "stockglobal.h"
#include "stockthreadharden.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug(a.applicationFilePath().toStdString().c_str());
    stockThread stock_thread;
    stock_thread.start();
    stockThreadHarden stock_threadharden;
    stock_threadharden.start();
    return a.exec();
}
