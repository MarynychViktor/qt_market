//
// Created by marinich_v on 05.01.21.
//

#ifndef MARKET_QT_SERVICELOCATOR_H
#define MARKET_QT_SERVICELOCATOR_H


#include <QString>
#include <QMap>
#include <memory>
#include <QDebug>

using namespace std;

class ServiceLocator {
public:
    template<class T>
    shared_ptr<T> GetService() {
        auto typeName = typeid(T).name();

        if (registry.contains(typeName)) {
            shared_ptr<void> value = registry.value(typeName);
            return static_pointer_cast<T>(value);
        }

        if (factoryRegistry.contains(typeName)) {
            auto factory = factoryRegistry.value(typeName);
            shared_ptr<void> value = factory();
            return static_pointer_cast<T>(value);
        }

        throw runtime_error("Service with given type not found");
    }

    template<class T>
    void Register(shared_ptr<T> value) {
        auto typeName = typeid(T).name();

        if (registry.contains(typeName)) {
            throw runtime_error("Service already registered");
        }

        registry.insert(typeName, value);
    }

    template<class T>
    void Register(function<shared_ptr<T>(void)> factory) {
        auto typeName = typeid(T).name();

        if (factoryRegistry.contains(typeName)) {
            throw runtime_error("Service factory already registered");
        }

        factoryRegistry.insert(typeName, factory);
    }

    static shared_ptr<ServiceLocator> Instance();
protected:
    ServiceLocator() = default;

private:
    static shared_ptr<ServiceLocator> instance;
    QMap<QString, shared_ptr<void>> registry;
    QMap<QString, function<shared_ptr<void>()>> factoryRegistry;
};


#endif //MARKET_QT_SERVICELOCATOR_H
