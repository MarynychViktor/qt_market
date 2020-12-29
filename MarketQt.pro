TEMPLATE = app
TARGET = market_qt
QT += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += \
    form.cpp \
    main.cpp \
    model/product.cpp \
    orderswindow.cpp \
    pages/menu.cpp \
    producttablemodel.cpp

FORMS += \
    form.ui \
    orderswindow.ui \
    pages/menu.ui

HEADERS += \
    form.h \
    model/product.h \
    orderswindow.h \
    pages/menu.h \
    producttablemodel.h

RESOURCES += \
    resources/images.qrc
