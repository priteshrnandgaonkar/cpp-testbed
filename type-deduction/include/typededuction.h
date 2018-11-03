#pragma once
#include <type_traits>
#include <typeinfo>
#ifndef _MSC_VER
#   include <cxxabi.h>
#endif
#include <memory>
#include <string>
#include <cstdlib>
#include <iostream>
namespace TypeDeduction {

template <class T>
std::string
type_name()
{
    typedef typename std::remove_reference<T>::type TR;
    std::unique_ptr<char, void(*)(void*)> own
           (
#ifndef _MSC_VER
                abi::__cxa_demangle(typeid(TR).name(), nullptr,
                                           nullptr, nullptr),
#else
                nullptr,
#endif
                std::free
           );
    std::string r = own != nullptr ? own.get() : typeid(TR).name();
    if (std::is_const<TR>::value)
        r += " const";
    if (std::is_volatile<TR>::value)
        r += " volatile";
    if (std::is_lvalue_reference<T>::value)
        r += "&";
    else if (std::is_rvalue_reference<T>::value)
        r += "&&";
    return r;
};
    template<typename T>
    void funcPassByRef(T& param) {
        std::cout << "Template type is " << type_name<T>() << std::endl;
        std::cout << "Param type is " << type_name<decltype(param)>() << std::endl;
    }

    template<class T>
    void funcPassByUniversalRef(T&& param) {
        std::cout << "Template type is " << type_name<T>() << std::endl;
        std::cout << "Param type is " << type_name<decltype(std::move(param))>() << std::endl;
    }

    template<typename T>
    void funcPassByValue(T param) {
        std::cout << "Template type is " << type_name<T>() << std::endl;
        std::cout << "Param type is " << type_name<decltype(param)>() << std::endl;
    }
}
