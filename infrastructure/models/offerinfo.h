#ifndef OFFERINFO_H
#define OFFERINFO_H

#include <QString>



class OfferInfo
{
public:
    OfferInfo(
        int price,
        int count,
        int myCount
    );
    int price;
    int count;
    int myCount;

    QString toString();
};

#endif // OFFERINFO_H
