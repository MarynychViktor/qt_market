//
// Created by marinich_v on 03.01.21.
//

#ifndef MARKET_QT_MARKETEXCEPTION_H
#define MARKET_QT_MARKETEXCEPTION_H


#include <exception>
#include <QString>
#include <QException>

class MarketException : public QException
{
public:
    MarketException(QString msg);
    void raise() const override;
    MarketException *clone() const override;

    const QString &getMessage() const;
private:
    QString message;
};
#endif //MARKET_QT_MARKETEXCEPTION_H
