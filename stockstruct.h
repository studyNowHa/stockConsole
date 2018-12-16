#ifndef STOCKSTRUCT_H
#define STOCKSTRUCT_H
#include <QString>
#include <QVector>


class stockStruct
{
public:
    stockStruct();
    //stockStruct(QString str);
    QString stock_name = "empty";                 //股票名字
    QString stock_num = "empty";                  //股票代码
    QString stock_price = "empty";                //当前价格
    QString stock_yest_price = "empty";           //昨收
    QString stock_today_price = "empty";          //今开
    QString stock_volume = "empty";               //成交量（手）
    QString stock_sell_volume = "empty";          //卖一量（手）
    QString stock_buy_volume = "empty";           //买一量（手）
    QString stock_uplift = "empty";               //涨幅
    QString stock_uplift_percent = "empty";       //涨跌%
    QString stock_limit_up_price = "empty";       //涨停价
    QString stock_limit_down_price = "empty";     //跌停价
    QString stock_time = "empty";                 //时间
    QVector<QString> stock_theme;                //股票题材
    bool    stock_get_data_state = false;       //获取数据的有效状态
    bool    stock_state = false;                //股票是否停牌
    float stock_sell_total_money = 0;     //股票卖一总金额
    float stock_buy_total_money = 0;     //股票买一总金额
};

#endif // STOCKSTRUCT_H
