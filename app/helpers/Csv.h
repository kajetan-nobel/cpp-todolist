#ifndef __APP_CSV__H
#define __APP_CSV__H

#include <vector>
#include <string>
#include <iostream>

namespace CSV {
    std::vector<std::string> read_row(std::string &line, char delimiter);
    std::vector<std::string> read_row(std::istream &in, char delimiter);
}

#endif