//
// Created by marinich_v on 03.01.21.
//

#include "MarketException.h"

MarketException::MarketException(QString msg) : message(msg) {}

void MarketException::raise() const {
    throw *this;
}

MarketException * MarketException::clone() const {
    return new MarketException(*this);
}

const QString &MarketException::getMessage() const {
    return message;
}
