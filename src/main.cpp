#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <csignal>

#include "extern.h"
#include "gate.h"
#include "linefollow.h"

void stop(int signum)
{
    set_motor(1, 0);
    set_motor(2, 0);
    exit(signum);
}

int main()
{
    init();
    signal(SIGINT, stop);
    #ifndef NOGATE
        open_gate();
    #endif
    Sleep(0, 500000);
    follow_line();
    return 0;
}
