//
// Created by xavier on 8/12/17.
//

#ifndef PLUGINBASEDFILEFORMAT_NETFLIX_SHOW_H
#define PLUGINBASEDFILEFORMAT_NETFLIX_SHOW_H

#include <string>

struct netflix_show {
    std::string name;
    unsigned rating;
    std::string genre;

    friend std::ostream& operator<<(std::ostream&, const netflix_show&);
};


#endif //PLUGINBASEDFILEFORMAT_NETFLIX_SHOW_H
