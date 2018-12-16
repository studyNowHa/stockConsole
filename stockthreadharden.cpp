#include "stockthreadharden.h"

stockThreadHarden::stockThreadHarden()
{

}

void stockThreadHarden::run()
{
    QRegExp stock_regexp_9(tr("[0-9]{14}~.{1,2}\..{2}~9.9."));
    QRegExp stock_regexp_10("[0-9]{14}~.{1,2}\..{2}~10.{3}");
    stockStruct stock_struct;
    QVector<stockStruct> stock_vector_struct;
    qDebug("stockThreadHarden is runing!");
    while(1){
        if(stock_global_date.contains(";",Qt::CaseInsensitive)){
            qDebug("if");
            QString stock_date = stock_global_date;
            QStringList stock_list_date = stock_date.split(";");//分组
            qDebug("starting...");
            QStringList stock_list_date_filter_9 = stock_list_date.filter(stock_regexp_9);
            QStringList stock_list_date_filter_10 = stock_list_date.filter(stock_regexp_10);
            //qDebug("QStringList_9 size=%d",stock_list_date_filter_9.size());
            //qDebug("QStringList_10 size=%d",stock_list_date_filter_10.size());
            //涨幅超过10%的进一步筛选
            for(int i=0; i<stock_list_date_filter_10.size(); i++){
                if(stock_list_date_filter_10.at(i).contains("~",Qt::CaseInsensitive)){
                    QStringList stock_list_date_10 = stock_list_date_filter_10.at(i).split("~");
                    //判断是否真实涨停
                    if(stock_list_date_10.at(20) == "0"){
                        stock_struct.stock_name = stock_list_date_10.at(1).toStdString().c_str();
                        stock_struct.stock_num = stock_list_date_10.at(2).toStdString().c_str();
                        stock_struct.stock_uplift_percent = stock_list_date_10.at(32).toStdString().c_str();
                        stock_vector_struct.append(stock_struct);
                        //qDebug("stock_list_date_10=%s",stock_list_date_10.at(2).toStdString().c_str());
                    }
                }
            }
            //涨幅超过9%的进一步筛选
            for(int i=0; i<stock_list_date_filter_9.size(); i++){
                if(stock_list_date_filter_9.at(i).contains("~",Qt::CaseInsensitive)){
                    QStringList stock_list_date_9 = stock_list_date_filter_9.at(i).split("~");
                    //判断是否真实涨停
                    if(stock_list_date_9.at(20) == "0"){
                        stock_struct.stock_name = stock_list_date_9.at(1).toStdString().c_str();
                        stock_struct.stock_num = stock_list_date_9.at(2).toStdString().c_str();
                        stock_struct.stock_uplift_percent = stock_list_date_9.at(32).toStdString().c_str();
                        stock_vector_struct.append(stock_struct);
                        //qDebug("stock_list_date_9=%s",stock_list_date_9.at(2).toStdString().c_str());
                    }
                }
            }
            qDebug("涨停数量=%d",stock_vector_struct.size());
            //填充匹配的结构体
            stockStruct stock_struct_replace;
            for(int i=0; i<stock_vector_struct.size(); i++){
                for(int iIndex=0;iIndex<stock_struct_qvector.size();iIndex++){
                    if(stock_vector_struct.at(i).stock_num == stock_struct_qvector.at(iIndex).stock_num.mid(2)){
                            stock_struct_replace.stock_num = stock_vector_struct.at(i).stock_num;
                            stock_struct_replace.stock_name = stock_vector_struct.at(i).stock_name;
                            stock_struct_replace.stock_theme = stock_struct_qvector.at(iIndex).stock_theme;
                            stock_vector_struct.replace(i,stock_struct_replace);
                        break;
                    }
                }

                qDebug(stock_vector_struct.at(i).stock_name.toStdString().c_str());
                QString sTheme;
                for(int iTheme=0; iTheme<stock_vector_struct.at(i).stock_theme.size(); iTheme++){
                    sTheme += (stock_vector_struct.at(i).stock_theme.at(iTheme)+"+").toStdString().c_str();
                }
                qDebug((sTheme.toStdString()+"\r\n").c_str());
            }
            break;
        }
    }
}

