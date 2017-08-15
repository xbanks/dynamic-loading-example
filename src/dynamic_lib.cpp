//
// Created by xavier on 8/13/17.
//

#include "dynamic_lib.h"
#include <dlfcn.h>
#include <iostream>

bool dynamic_lib::load() {
    _handle = dlopen(_lib_name, RTLD_LAZY);
    if(!_handle) {
        std::cerr << "Couldn't load " << _lib_name << std::endl;
        std::cerr << dlerror() << std::endl;
        return false;
    }

    std::cout << "Loaded: " << _lib_name << std::endl;
    return true;
}

bool dynamic_lib::unload() {
    dlclose(_handle);
    _handle = nullptr;

    return true;
}

//template <typename FunctionType>
void* dynamic_lib::get_function(const char *func_name) {
    if(!_handle) {
        std::cerr << "no library loaded" << std::endl;
        return nullptr;
    }

    const auto sym = dlsym(_handle, func_name);
    if(!sym) {
        std::cerr << "Couldn't load symbol: " << func_name << std::endl;
        std::cerr << dlerror() << std::endl;
        return nullptr;
    }

//    const auto func = static_cast<FunctionType>(sym);

    return sym;
}

