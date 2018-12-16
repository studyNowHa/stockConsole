#ifndef STOCKDATE_H
#define STOCKDATE_H
#include <QVector>
#include <QString>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QEventLoop>
#include "stockstruct.h"

class stockDate
{
public:
    stockDate();
    QString stockReturnDates(QVector<QString> stock_code);//增加股票长度判断
    QString stockReturnDate(QVector<QString> stock_code);//返回股票数据
    QVector<QString> stockReturnQVector(QVector<stockStruct> stock_struct);
public:
#define stock_max_len 900
};

#endif // STOCKDATE_H
