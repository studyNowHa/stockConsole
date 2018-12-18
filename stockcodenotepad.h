#ifndef STOCKCODENOTEPAD_H
#define STOCKCODENOTEPAD_H
#include <QString>
#include <QTextStream>
#include <QFile>
#include "stockstruct.h"

class stockCodeNotepad
{
public:
    stockCodeNotepad();
    QVector<stockStruct> stockReturnCode(QString stock_string_dir);//获取股票代码
};

#endif // STOCKCODENOTEPAD_H
