//
// Created by marinich_v on 05.01.21.
//

#include "ServiceLocator.h"

shared_ptr<ServiceLocator> ServiceLocator::instance;

shared_ptr<ServiceLocator> ServiceLocator::Instance() {
    if (instance == nullptr) {
        instance = make_shared<ServiceLocator>(ServiceLocator());
    }

    return instance;
}
