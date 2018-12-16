#include "stockthreadalldate.h"
#include "stockstruct.h"

stockThread::stockThread()
{

}

void stockThread::run()
{
    getStockDateAll();
}

bool stockThread::getStockDateAll()
{
    qDebug("stockThread is run!");
    //读取股票代码
    stockCode stock_code;
    QVector<stockStruct> stock_return_struct = stock_code.stockReturnCode("D:\\stock\\stock\\stockNum.xlsm");
    stock_struct_qvector = stock_return_struct;
    //返回股票数据
    stockDate stock_date;
    QVector<QString>stock_return_code = stock_date.stockReturnQVector(stock_return_struct);
    qDebug("start while");
    while(1){
    stock_global_date = stock_date.stockReturnDates(stock_return_code);
    //qDebug(stock_global_date.toStdString().c_str());
    }
}
