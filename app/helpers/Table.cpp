#include "Table.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std; 

/**
 * Copied from: https://stackoverflow.com/questions/14765155/how-can-i-easily- format-my-data-table-in-c
 */

namespace Table {
    string format(const string s, const int w) {
        stringstream ss, spaces; 
        int padding = w - s.size(); 
        for(int i=0; i<padding; ++i) {
            spaces << " ";
        }
        ss << s << spaces.str(); 
        return ss.str();
    }
}

