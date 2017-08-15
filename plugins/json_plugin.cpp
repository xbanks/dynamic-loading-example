//
// Created by xavier on 8/12/17.
//

#include <sstream>
#include <iostream>
#include <iomanip>
#include "json_plugin.h"
#include "plugin_base.h"

bool json_plugin::save(const netflix_show& show) {
    std::stringstream strm;
    std::string indent(2, ' ');
    std::string newline = ",\n";
    strm << "{\n";
    strm << indent << std::quoted("name") << " : " << std::quoted(show.name) << newline;
    strm << indent << std::quoted("genre") << " : " << std::quoted(show.genre) << newline;
    strm << indent << std::quoted("rating") << " : " << show.rating << "\n";
    strm << "}";

    std::cout << strm.str() << std::endl;

    return true;
}



extern "C" {

#ifdef __GNUC__
#if 0
    extern plugin_manager* plugin_mgr;
    __attribute__((constructor))
    void init() {
        if(plugin_mgr) {
            plugin_mgr->register_plugin(new json_plugin);
        }
    }
#endif
#endif

    plugin_base* get_plugin() {
        return new json_plugin();
    }
}
