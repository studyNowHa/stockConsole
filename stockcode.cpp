#include "stockcode.h"


stockCode::stockCode()
{
    //初始化COM
    HRESULT ret = OleInitialize(0);
    if(ret != S_OK && ret != S_FALSE){
        qDebug("Could not initialize OLE ,error code %x",ret);
    }
}

stockCode::~stockCode()
{
    OleUninitialize();//释放COM
}

QVector<stockStruct> stockCode::stockReturnCode(QString stock_string_dir)
{
    //读取Excel表格
    QAxObject excel("Excel.Application");
    excel.setProperty("Visible", false); //隐藏打开的excel文件界面
    QAxObject *workbooks = excel.querySubObject("WorkBooks");
    QAxObject *workbook = workbooks->querySubObject("Open(QString, QVariant)", /*"d:\\stock.xlsx"*/stock_string_dir); //打开文件
    QAxObject * worksheet = workbook->querySubObject("WorkSheets(int)", 1); //访问第一个工作表
    QAxObject * usedrange = worksheet->querySubObject("UsedRange");
    QVariant allEnvDataQVariant = usedrange->dynamicCall("Value");//allEnvData->property("Value");
    QVariantList allEnvDataList = allEnvDataQVariant.toList();
    QVector<stockStruct> str;
    stockStruct stock_struct;
    QString data1;
    QVariantList allEnvDataList_i;
    //加载初始化股票结构体
    for(int i=0; i< allEnvDataList.length(); i++)
    {
        allEnvDataList_i =  allEnvDataList[i].toList() ;
            stock_struct.stock_num = allEnvDataList_i[0].toString(); //第i行第int_columns_for列的数据
            QString strTheme = allEnvDataList_i[1].toString();//股票题材
            QStringList stockStrTheme = this->stockReturnTheme(strTheme);
            stock_struct.stock_theme.clear();
            for(int iTheme=0; iTheme<stockStrTheme.length(); iTheme++){
                stock_struct.stock_theme.append(stockStrTheme.at(iTheme));
            }
            str.append(stock_struct);
    }
    workbooks->dynamicCall("Close()");
    excel.dynamicCall("Quit()");
    //stock_struct_qvector =  str;
    return str;
    }


    QStringList stockCode::stockReturnTheme(QString str)
    {
        QStringList strListTheme = str.split(';');
        return strListTheme;
    }
