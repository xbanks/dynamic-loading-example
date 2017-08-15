//
// Created by xavier on 8/12/17.
//

#include "../include/netflix_show.h"
#include <iostream>

std::ostream &operator<<(std::ostream& ostream, const netflix_show &show) {
    ostream << "{name: " << show.name << ", genre: " << show.genre << ", rating: " << show.rating << "}";
    return ostream;
}


