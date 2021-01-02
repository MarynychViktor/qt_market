TEMPLATE = app
TARGET = market_qt
QT += core gui network sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    form.cpp \
    infrastructure/helpers/stringhelper.cpp \
    infrastructure/httpclient.cpp \
    infrastructure/markethttpclient.cpp \
    infrastructure/marketsettings.cpp \
    infrastructure/models/iteminfo.cpp \
    infrastructure/models/itemmassinforesult.cpp \
    infrastructure/models/offerinfo.cpp \
    infrastructure/models/traderesponse.cpp \
    infrastructure/repositories/productrepository.cpp \
    jobs/updatetradepricesjob.cpp \
    main.cpp \
    models/product.cpp \
    pages/orderswindow.cpp \
    pages/menu.cpp \
    models/producttablemodel.cpp

FORMS += \
    form.ui \
    pages/orderswindow.ui \
    pages/menu.ui

HEADERS += \
    consts.h \
    form.h \
    infrastructure/helpers/stringhelper.h \
    infrastructure/httpclient.h \
    infrastructure/markethttpclient.h \
    infrastructure/marketsettings.h \
    infrastructure/models/iteminfo.h \
    infrastructure/models/itemmassinforesult.h \
    infrastructure/models/offerinfo.h \
    infrastructure/models/traderesponse.h \
    infrastructure/repositories/productrepository.h \
    jobs/updatetradepricesjob.h \
    models/product.h \
    pages/orderswindow.h \
    pages/menu.h \
    models/producttablemodel.h

RESOURCES += \
    resources/images.qrc
