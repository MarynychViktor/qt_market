#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include <string.h>


class Product
{
public:
    Product(std::string name, double order, double sell)
        : name(QString::fromStdString(name)), orderPrice(order), sellPrice(sell)
    {}

    QString name;
    double orderPrice;
    double sellPrice;
};

#endif // PRODUCT_H
