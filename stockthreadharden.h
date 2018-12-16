#ifndef STOCKTHREADHARDEN_H
#define STOCKTHREADHARDEN_H
#include <QThread>
#include "stockglobal.h"
#include <QStringList>
#include <QString>
#include <QRegExp>
#include "stockstruct.h"
#include <QVector>

class stockThreadHarden : public QThread
{
public:
    stockThreadHarden();
    void run();
};

#endif // STOCKTHREADHARDEN_H
