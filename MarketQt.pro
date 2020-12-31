TEMPLATE = app
TARGET = market_qt
QT += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    form.cpp \
    infrastructure/helpers/stringhelper.cpp \
    infrastructure/httpclient.cpp \
    infrastructure/markethttpclient.cpp \
    infrastructure/marketsettings.cpp \
    infrastructure/models/iteminfo.cpp \
    infrastructure/models/offerinfo.cpp \
    infrastructure/models/traderesponse.cpp \
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
    form.h \
    infrastructure/helpers/stringhelper.h \
    infrastructure/httpclient.h \
    infrastructure/markethttpclient.h \
    infrastructure/marketsettings.h \
    infrastructure/models/iteminfo.h \
    infrastructure/models/offerinfo.h \
    infrastructure/models/traderesponse.h \
    models/product.h \
    pages/orderswindow.h \
    pages/menu.h \
    models/producttablemodel.h

RESOURCES += \
    resources/images.qrc
