#include <stdlib.h>

#include "util.h"

void stop(int signum)
{
    set_motor(1, 0);
    set_motor(2, 0);
    exit(signum);
}

