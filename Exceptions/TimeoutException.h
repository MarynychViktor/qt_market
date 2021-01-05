//
// Created by marinich_v on 05.01.21.
//

#ifndef MARKET_QT_TIMEOUTEXCEPTION_H
#define MARKET_QT_TIMEOUTEXCEPTION_H


#include "AppException.h"

class TimeoutException : public AppException
{
public:
    explicit TimeoutException(QString msg);
};

#endif //MARKET_QT_TIMEOUTEXCEPTION_H
