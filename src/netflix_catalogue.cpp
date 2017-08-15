//
// Created by xavier on 8/12/17.
//

#include "netflix_catalogue.h"

netflix_catalogue::ShowList netflix_catalogue::shows_by()
{
    return _shows;
}

void netflix_catalogue::add_show(const netflix_show &show) {
    _shows.emplace_back(show);
}