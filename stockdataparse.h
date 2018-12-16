#ifndef STOCKDATAPARSE_H
#define STOCKDATAPARSE_H
#include <QVector>
#include <QString>

class stockDataParse
{
public:
    stockDataParse();
    QVector<QString> stockReturnDataParse(QString stock_data_parse);
};

#endif // STOCKDATAPARSE_H
