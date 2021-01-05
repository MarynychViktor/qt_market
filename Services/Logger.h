//
// Created by marinich_v on 05.01.21.
//

#ifndef MARKET_QT_LOGGER_H
#define MARKET_QT_LOGGER_H

#include <QString>
#include <QDebug>
#include <QDateTime>

class Logger {
public:
    static void error(const QString& message);
    static void warning(const QString& message);
    static void info(const QString& message);
    static void debug(const QString& message);
    static QString isoDateString();
};


#endif //MARKET_QT_LOGGER_H
