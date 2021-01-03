cmake_minimum_required(VERSION 3.1.0)
project(market_qt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5Core REQUIRED)
find_package(Qt5Gui REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Sql REQUIRED)
find_package(Qt5Widgets REQUIRED)

set(SOURCES
        form.cpp
        infrastructure/helpers/stringhelper.cpp
        infrastructure/httpclient.cpp
        infrastructure/markethttpclient.cpp
        infrastructure/marketsettings.cpp
        infrastructure/models/iteminfo.cpp
        infrastructure/models/itemmassinforesult.cpp
        infrastructure/models/offerinfo.cpp
        infrastructure/models/traderesponse.cpp
        infrastructure/repositories/productrepository.cpp
        jobs/updatetradepricesjob.cpp
        main.cpp
        models/product.cpp
        pages/orderswindow.cpp
        pages/menu.cpp
        models/producttablemodel.cpp
        workers/worker.cpp
    )
set(HEADERS
        consts.h
        form.h
        infrastructure/helpers/stringhelper.h
        infrastructure/httpclient.h
        infrastructure/markethttpclient.h
        infrastructure/marketsettings.h
        infrastructure/models/iteminfo.h
        infrastructure/models/itemmassinforesult.h
        infrastructure/models/offerinfo.h
        infrastructure/models/traderesponse.h
        infrastructure/repositories/productrepository.h
        jobs/updatetradepricesjob.h
        models/product.h
        pages/orderswindow.h
        pages/menu.h
        models/producttablemodel.h
        workers/worker.h
        )

 set(RESOURCE_FILES
     resources/images.qrc)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(resources/)
add_executable(market_qt ${HEADERS} ${RESOURCE_FILES} ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC include)

target_link_libraries(market_qt Qt5::Core Qt5::Gui Qt5::Sql Qt5::Network Qt5::Widgets)

