//
// Created by marinich_v on 05.01.21.
//

#include "Logger.h"


void Logger::error(const QString& message)
{
    qWarning() << QString("[Error][%1]: %2").arg(isoDateString(), message);
}

void Logger::warning(const QString& message)
{
    qWarning() << QString("[Warning][%1]: %2").arg(isoDateString(), message);
}

void Logger::info(const QString& message)
{
    qInfo() << QString("[Info][%1]: %2").arg(isoDateString(), message);
}

void Logger::debug(const QString& message)
{
    qDebug() << QString("[Debug][%1]: %2").arg(isoDateString(), message);
}

QString Logger::isoDateString()
{
    QDateTime date = QDateTime::currentDateTime();
    return date.toUTC().toString(Qt::DateFormat::ISODate);
}