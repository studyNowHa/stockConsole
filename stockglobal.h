#ifndef STOCKGLOBAL_H
#define STOCKGLOBAL_H
#include <QString>
#include <QVector>
#include "stockstruct.h"

extern QString stock_global_date;
extern QVector<QString> stock_global_harden_date;
extern QVector<stockStruct> stock_struct_qvector;

class stockGlobal
{
public:
    stockGlobal();
};

#endif // STOCKGLOBAL_H
