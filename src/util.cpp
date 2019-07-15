#include "util.h"
#include <cstdlib>
#include <time.h>


namespace Util {

    int generate_random(int min , int max) {
        srand(time(nullptr));

        return ( rand() % max ) + min;
    }
};
