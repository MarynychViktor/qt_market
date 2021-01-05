//
// Created by marinich_v on 04.01.21.
//

#include "NotFoundException.h"

#include <utility>

NotFoundException::NotFoundException(QString msg) : AppException(std::move(msg)) {
}
