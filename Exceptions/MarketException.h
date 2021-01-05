//
// Created by marinich_v on 03.01.21.
//

#ifndef MARKET_QT_MARKETEXCEPTION_H
#define MARKET_QT_MARKETEXCEPTION_H


#include <exception>
#include <QString>
#include <QException>
#include "AppException.h"

class MarketException : public AppException
{
public:
    explicit MarketException(QString msg);

};
#endif //MARKET_QT_MARKETEXCEPTION_H
