//
// Created by xavier on 8/12/17.
//

#ifndef PLUGINBASEDFILEFORMAT_NETFLIX_CATALOGUE_H
#define PLUGINBASEDFILEFORMAT_NETFLIX_CATALOGUE_H

#include "../include/netflix_show.h"
#include <vector>

class netflix_catalogue {
    using ShowList = std::vector<netflix_show>;
    enum FilterTypes
    {
        GENRE = 0,
        RATING
    };
public:
    explicit netflix_catalogue(ShowList shows = ShowList{})
            : _shows{shows}
    {}

    ShowList shows_by();
    void add_show(const netflix_show& show);

private:
    ShowList _shows;
};


#endif //PLUGINBASEDFILEFORMAT_NETFLIX_CATALOGUE_H
