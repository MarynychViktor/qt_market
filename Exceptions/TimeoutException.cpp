//
// Created by marinich_v on 05.01.21.
//

#include "TimeoutException.h"

#include <utility>

TimeoutException::TimeoutException(QString msg) : AppException(std::move(msg)) {
}
