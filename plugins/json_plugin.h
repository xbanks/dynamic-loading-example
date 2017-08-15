//
// Created by xavier on 8/12/17.
//

#ifndef PLUGINBASEDFILEFORMAT_JSON_PLUGIN_H
#define PLUGINBASEDFILEFORMAT_JSON_PLUGIN_H

#include "plugin_base.h"
#include "netflix_show.h"

class json_plugin : public plugin_base {
public:
    bool save(const DataType&) override;
    std::string name() const { return "libjson"; }
};


#endif //PLUGINBASEDFILEFORMAT_JSON_PLUGIN_H
