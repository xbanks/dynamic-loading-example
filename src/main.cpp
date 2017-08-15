#include <iostream>
#include <algorithm>
#include <plugin_base.h>

#include "netflix_catalogue.h"
#include "netflix_show.h"
#include "dynamic_lib.h"

using Func = plugin_base*(*)(void);
plugin_manager* plugin_mgr = new plugin_manager();
int main() {
    std::cout << "Hello, World!" << std::endl;

    netflix_catalogue catalogue;
    catalogue.add_show({"Something", 5, "New"});
    catalogue.add_show({"The Heartbreak kid", 4, "RomCom"});
    catalogue.add_show({"Annabelle: The Creation", 4, "Thriller"});


    auto shows = catalogue.shows_by();

    std::for_each(shows.begin(), shows.end(), [](netflix_show& show){ std::cout << show << std::endl; });

    auto lib = dynamic_lib("../lib/libjson.so");
    if(lib.load()) {
        auto func = (Func)lib.get_function("get_plugin");
        auto plugin = func();
        std::cout << plugin->name() << std::endl;

        for(const auto& show : shows) {
            plugin->save(show);
        }

        lib.unload();
    }

    return 0;
}