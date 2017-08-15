//
// Created by xavier on 8/13/17.
//

#ifndef PLUGINBASEDFILEFORMAT_DYNAMIC_LIB_H
#define PLUGINBASEDFILEFORMAT_DYNAMIC_LIB_H

#include <string>

class dynamic_lib {
public:
    dynamic_lib(const char * lib_name)
            : _lib_name(lib_name)
    {

    }

    bool load();
    bool unload();

//    template <typename FunctionType>
    void* get_function(const char * func_name);

private:
    const char * _lib_name;
    void * _handle;
};


#endif //PLUGINBASEDFILEFORMAT_DYNAMIC_LIB_H
