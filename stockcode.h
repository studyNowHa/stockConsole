#ifndef STOCKCODE_H
#define STOCKCODE_H
#include <QString>
#include <QVector>
#include <QAxObject>
#include <QVariantList>
#include "qt_windows.h"
#include "stockstruct.h"
#include <QStringList>

extern QVector<stockStruct> stock_struct_qvector;

class stockCode
{
public:
    stockCode();
    ~stockCode();
    QVector<stockStruct> stockReturnCode(QString stock_string_dir);//返回股票代码
    QStringList stockReturnTheme(QString str);//返回股票题材
};

#endif // STOCKCODE_H
