#ifndef STOCKTHREAD_H
#define STOCKTHREAD_H
#include <QThread>
#include "stockcode.h"
#include "stockdata.h"
#include "stockdataparse.h"
#include "stockglobal.h"

extern QVector<stockStruct> stock_struct_qvector;

class stockThread : public QThread
{
public:
    stockThread();
    void run();
    bool getStockDateAll();
};

#endif // STOCKTHREAD_H
