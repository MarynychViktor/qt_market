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
        Http/HttpClient.cpp
        Http/MarketHttpClient.cpp
        Infrastructure/MarketSettings.cpp
        Infrastructure/Models/ItemInfo.cpp
        Infrastructure/Models/ItemMassInfoResult.cpp
        Infrastructure/Models/OfferInfo.cpp
        Infrastructure/Models/TradeResponse.cpp
        Infrastructure/Repositories/ProductRepository.cpp
        Jobs/UpdateTradePricesJob.cpp
        Models/Product.cpp
        ui/ProductsTableWidget.cpp
        pages/menu.cpp
        Models/ProductTableModel.cpp
        workers/Worker.cpp
        ui/MarketManagementContent.cpp
        )
set(HEADERS
        consts.h
        Http/HttpClient.h
        Http/MarketHttpClient.h
        Infrastructure/MarketSettings.h
        Infrastructure/Models/ItemInfo.h
        Infrastructure/Models/ItemMassInfoResult.h
        Infrastructure/Models/OfferInfo.h
        Infrastructure/Models/TradeResponse.h
        Infrastructure/Repositories/ProductRepository.h
        Jobs/UpdateTradePricesJob.h
        Models/Product.h
        ui/ProductsTableWidget.h
        pages/menu.h
        Models/ProductTableModel.h
        workers/Worker.h
        ui/MarketManagementContent.h
        )

set(RESOURCE_FILES
        resources/images.qrc Exceptions/MarketException.cpp Exceptions/MarketException.h workers/WorkerManager.cpp workers/WorkerManager.h ui/MainWindow.cpp ui/MainWindow.h workers/TradeWorker.cpp workers/TradeWorker.h Services/ProductManager.cpp Services/ProductManager.h Exceptions/AppException.cpp Exceptions/AppException.h Exceptions/NotFoundException.cpp Exceptions/NotFoundException.h Infrastructure/DI/ServiceLocator.cpp Infrastructure/DI/ServiceLocator.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
#include_directories( ${CMAKE_BINARY_DIR} )
add_executable(${PROJECT_NAME} ${HEADERS}  ${SOURCES} ${RESOURCE_FILES} )
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(Qt5 COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})


