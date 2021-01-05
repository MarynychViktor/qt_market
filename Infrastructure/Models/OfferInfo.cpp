#include "OfferInfo.h"

OfferInfo::OfferInfo(
    int price,
    int count,
    int myCount
) {
    this->price = price;
    this->count = count;
    this->myCount = myCount;
}

QString OfferInfo::toString()
{
    return QString("Price: %1, Count: %2, My Count: %3").arg(QString::number(price), QString::number(count), QString::number(myCount));
}
