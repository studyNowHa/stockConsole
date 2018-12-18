#include "stockcodenotepad.h"

stockCodeNotepad::stockCodeNotepad()
{

}

QVector<stockStruct> stockCodeNotepad::stockReturnCode(QString stock_string_dir)
{
    QVector<stockStruct> stock_code;
    stockStruct stock_struct;
    QFile file(stock_string_dir);
     if (!file.open(QIODevice::ReadOnly | QIODevice::Text)){
         qDebug("open notepad filed!");
         return stock_code;
      }
     QTextStream in(&file);
     QString line = in.readLine();
     QStringList sTmp;
     QStringList stockStrTheme;
     while (!line.isNull()) {
         stock_struct.stock_theme.clear();
         sTmp = line.split("~");
         stock_struct.stock_num = sTmp.at(0);
         stockStrTheme = sTmp.at(1).split(";");
         for(int i=0; i<stockStrTheme.length(); i++){
            stock_struct.stock_theme.append(stockStrTheme.at(i));
     }
         stock_code.append(stock_struct);
         line = in.readLine();
     }
     return stock_code;
}
