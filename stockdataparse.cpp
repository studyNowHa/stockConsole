#include "stockdataparse.h"

stockDataParse::stockDataParse()
{

}

QVector<QString> stockDataParse::stockReturnDataParse(QString stock_data_parse)
{
    if(stock_data_parse.contains(";",Qt::CaseInsensitive)){
        QStringList stock_list = stock_data_parse.split(";");//分组

    }
}
