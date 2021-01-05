//
// Created by marinich_v on 04.01.21.
//

#include "AppException.h"

#include <utility>

AppException::AppException(QString msg)
    : message(std::move(msg))
{
}

void AppException::raise() const {
    throw *this;
}

AppException * AppException::clone() const {
    return new AppException(*this);
}

const QString &AppException::getMessage() const {
    return message;
}
