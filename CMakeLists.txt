cmake_minimum_required(VERSION 3.17)
project(market_qt)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(REQUIRED_LIBS Core Gui Widgets Sql Network)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core Qt5::Gui Qt5::Widgets Qt5::Sql Qt5::Network)
set(CMAKE_PREFIX_PATH C:/Qt/5.15.2/mingw81_64/lib/cmake)
set(QT_VERSION 5)

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

set(RESOURCE_FILES Exceptions/MarketException.cpp Exceptions/MarketException.h workers/WorkerManager.cpp workers/WorkerManager.h ui/MainWindow.cpp ui/MainWindow.h workers/TradeWorker.cpp workers/TradeWorker.h Services/ProductManager.cpp Services/ProductManager.h Exceptions/AppException.cpp Exceptions/AppException.h Exceptions/NotFoundException.cpp Exceptions/NotFoundException.h Infrastructure/DI/ServiceLocator.cpp Infrastructure/DI/ServiceLocator.h Services/Logger.cpp Services/Logger.h Exceptions/TimeoutException.cpp Exceptions/TimeoutException.h Infrastructure/Models/OrderResponse.cpp Infrastructure/Models/OrderResponse.h workers/OrderWorker.cpp workers/OrderWorker.h Http/MarketRequestInterceptor.cpp Http/MarketRequestInterceptor.h Trades/TradesContext.cpp Trades/TradesContext.h Orders/OrdersContext.cpp Orders/OrdersContext.h)

include_directories(${CMAKE_CURRENT_SOURCE_DIR})
if (WIN32)
    add_executable(${PROJECT_NAME} ${HEADERS}  ${SOURCES} ${RESOURCE_FILES} )
#    add_executable(${PROJECT_NAME} WIN32 ${HEADERS}  ${SOURCES} ${RESOURCE_FILES} )
else()
    add_executable(${PROJECT_NAME} ${HEADERS}  ${SOURCES} ${RESOURCE_FILES} )
endif()

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

find_package(Qt5 COMPONENTS ${REQUIRED_LIBS} REQUIRED)
target_link_libraries(${PROJECT_NAME} ${REQUIRED_LIBS_QUALIFIED})

if (WIN32)
    set(DEBUG_SUFFIX)
    if (CMAKE_BUILD_TYPE MATCHES "Debug")
        set(DEBUG_SUFFIX "d")
    endif ()
    set(QT_INSTALL_PATH "${CMAKE_PREFIX_PATH}")
    if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
        set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        if (NOT EXISTS "${QT_INSTALL_PATH}/bin")
            set(QT_INSTALL_PATH "${QT_INSTALL_PATH}/..")
        endif ()
    endif ()
    if (EXISTS "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E make_directory
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/plugins/platforms/qwindows${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>/plugins/platforms/")
    endif ()
    foreach (QT_LIB ${REQUIRED_LIBS})
        add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
                COMMAND ${CMAKE_COMMAND} -E copy
                "${QT_INSTALL_PATH}/bin/Qt${QT_VERSION}${QT_LIB}${DEBUG_SUFFIX}.dll"
                "$<TARGET_FILE_DIR:${PROJECT_NAME}>")
    endforeach (QT_LIB)
endif ()

