#ifndef OFFERINFO_H
#define OFFERINFO_H

#include <QString>



class OfferInfo
{
public:
    OfferInfo(
        double price,
        int count,
        int myCount
    );
    double price;
    int count;
    int myCount;

    QString toString();
};

#endif // OFFERINFO_H
