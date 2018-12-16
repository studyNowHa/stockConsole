#include "stockdata.h"

stockDate::stockDate()
{

}

QString stockDate::stockReturnDates(QVector<QString> stock_code)
{
    QString stock_date;
    QVector <QString> stock_qvector_date;
    if(stock_code.size()<stock_max_len){
        return stockReturnDate(stock_code);
    }else while(1){
        stock_qvector_date = stock_code.mid(0,stock_max_len-1);
        stock_code.remove(0,stock_max_len);
        stock_date += stockReturnDate(stock_qvector_date);
        if(stock_code.size()<stock_max_len){
            return stock_date += stockReturnDate(stock_code);
        }
    }
}

QString stockDate::stockReturnDate(QVector<QString> stock_code)
{
    QString str_tmp;
    for(int i=0; i<stock_code.size(); i++){
        str_tmp.append(stock_code.at(i));
        str_tmp.append(",");
    }
    QNetworkReply *replys;
    QNetworkAccessManager netWork;
    QEventLoop eventLoop;
    QObject::connect(&netWork, SIGNAL(finished(QNetworkReply*)),&eventLoop,SLOT(quit()));
    replys =netWork.get(QNetworkRequest(QUrl("http://qt.gtimg.cn/q="+str_tmp )));
    eventLoop.exec();
    QString stock_data_return = QString::fromLocal8Bit(replys->readAll());
    delete replys;
    return stock_data_return;
}

QVector<QString> stockDate::stockReturnQVector(QVector<stockStruct> stock_struct)
{
    QVector<QString> stock_vector_string;
    for(int i=0; i<stock_struct.size(); i++){
        stock_vector_string.append(stock_struct.at(i).stock_num);
    }
    return stock_vector_string;
}
