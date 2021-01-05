//
// Created by marinich_v on 03.01.21.
//

#include "MarketException.h"

#include <utility>

MarketException::MarketException(QString msg) : AppException(std::move(msg)) {}

