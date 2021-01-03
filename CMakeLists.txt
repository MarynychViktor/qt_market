cmake_minimum_required(VERSION 3.17)
project(market_qt VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)


set(CMAKE_CURRENT_SOURCE_DIR home/marinich_v/Qt/5.15.2/gcc_64)
set(REQUIRED_LIBS Core Gui Widgets Sql Network)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Sql Qt5::Network)
set(CMAKE_PREFIX_PATH   /home/marinich_v/Qt/5.15.2/gcc_64/lib/cmake/Qt5)

set(Qt5_DIR /home/marinich_v/Qt/5.15.2/gcc_64/lib/cmake)

set(Qt5Core_DIR /home/marinich_v/Qt/5.15.2/gcc_64/lib/cmake/Qt5Core)
set(Qt5_DIR /home/marinich_v/Qt/5.15.2/gcc_64/lib/cmake/Qt5)
set(QT_QMAKE_EXECUTABLE /home/marinich_v/Qt/5.15.2/gcc_64/bin/qmake)
set(NO_CMAKE_SYSTEM_PATH true)
set(SOURCES
        main.cpp
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
        ./infrastructure/markethttpclient.h
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
#include_directories( ${CMAKE_BINARY_DIR} )
add_executable(${PROJECT_NAME} ${HEADERS}  ${SOURCES} ${RESOURCE_FILES} )
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(Qt5 COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})


