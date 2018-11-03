#pragma once

namespace TypeDeduction {
    <template T>
    void funcPassByRef(T& param);

    <template T>
    void funcPassByUniversalRef(T&& param);

    <template T>
    void funcPassByValue(T param);
}
