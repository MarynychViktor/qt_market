//
// Created by marinich_v on 04.01.21.
//

#ifndef MARKET_QT_APPEXCEPTION_H
#define MARKET_QT_APPEXCEPTION_H


#include <QException>
#include <QString>

class AppException: public QException
{
public:
    explicit AppException(QString msg);
    void raise() const override;
    AppException *clone() const override;

    const QString &getMessage() const;

protected:
    QString message;
};


#endif //MARKET_QT_APPEXCEPTION_H
