//
// Created by xavier on 8/12/17.
//

#ifndef PLUGINBASEDFILEFORMAT_PLUGIN_BASE_H
#define PLUGINBASEDFILEFORMAT_PLUGIN_BASE_H


#include <vector>
#include "netflix_show.h"

class plugin_base
{
public:
    using DataType = netflix_show;
    virtual bool save(const DataType & data) = 0;
    virtual std::string name() const = 0;
private:

};


class plugin_manager {
    using PluginList = std::vector<plugin_base*>;
public:
    bool register_plugin(plugin_base *);
private:
    PluginList _list;
};

bool plugin_manager::register_plugin(plugin_base * plugin) {
    if(plugin == nullptr) {
        return false;
    }

    _list.emplace_back(std::move(plugin));
    return true;
}

#endif //PLUGINBASEDFILEFORMAT_PLUGIN_BASE_H
