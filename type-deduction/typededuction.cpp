#include "include/typededuction.h"
#include <iostream>

namespace TypeDeduction {
    <template T>
    void funcPassByRef(T& param) {
        std::cout << "funcPassByRef" << decltype(param) << std::endl;
    }

    <template T>
    void funcPassByUniversalRef(T&& param) {
        std::cout << "funcPassByUniversalRef" << decltype(param) << std::endl;
    }

    <template T>
    void funcPassByValue(T param) {
        std::cout << "funcPassByValue" << decltype(param) << std::endl;

    }
}
