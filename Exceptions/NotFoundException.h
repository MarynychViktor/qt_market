//
// Created by marinich_v on 04.01.21.
//

#ifndef MARKET_QT_NOTFOUNDEXCEPTION_H
#define MARKET_QT_NOTFOUNDEXCEPTION_H


#include "AppException.h"

class NotFoundException : public AppException
{
public:
    explicit NotFoundException(QString msg);
};


#endif //MARKET_QT_NOTFOUNDEXCEPTION_H
