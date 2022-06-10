#include "Clearscreen.h"
#include <iostream>

namespace Helpers {
    // https://stackoverflow.com/questions/6486289/how-can-i-clear-console
    void clearscreen() {
        #if defined _WIN32
            system("cls");
        #elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
            std::cout << "\033[2J\033[1;1H";
        #elif defined (__APPLE__)
            std::cout << "\033[2J\033[1;1H";
        #endif
    }
}
