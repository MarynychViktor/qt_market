TEMPLATE = app
TARGET = market_qt
QT += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    form.cpp \
    infrastructure/httpclient.cpp \
    main.cpp \
    markethttpclient.cpp \
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
    infrastructure/httpclient.h \
    markethttpclient.h \
    models/product.h \
    pages/orderswindow.h \
    pages/menu.h \
    models/producttablemodel.h

RESOURCES += \
    resources/images.qrc
