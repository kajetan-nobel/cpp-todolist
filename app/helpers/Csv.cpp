#include "Csv.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

/**
 * Copied from http://www.zedwood.com/article/cpp-csv-parser
 */

namespace CSV {
    std::vector<std::string> read_row(std::string &line, char delimiter)
    {
        std::stringstream ss(line);
        return read_row(ss, delimiter);
    }
    
    std::vector<std::string> read_row(std::istream &in, char delimiter)
    {
        std::stringstream ss;
        bool inquotes = false;
        std::vector<std::string> row;//relying on RVO
        while(in.good())
        {
            char c = in.get();
            if (!inquotes && c=='"') //beginquotechar
            {
                inquotes=true;
            }
            else if (inquotes && c=='"') //quotechar
            {
                if ( in.peek() == '"')//2 consecutive quotes resolve to 1
                {
                    ss << (char)in.get();
                }
                else //endquotechar
                {
                    inquotes=false;
                }
            }
            else if (!inquotes && c==delimiter) //end of field
            {
                row.push_back( ss.str() );
                ss.str("");
            }
            else if (!inquotes && (c=='\r' || c=='\n') )
            {
                if(in.peek()=='\n') { in.get(); }
                row.push_back( ss.str() );
                return row;
            }
            else
            {
                ss << c;
            }
        }

        return row;
    }
}