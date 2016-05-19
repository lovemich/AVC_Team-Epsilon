#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <csignal>

#include "extern.h"
#include "gate.h"
#include "linefollow.h"

int main()
{
    init();
    signal(SIGINT, stop);
    #ifndef NOGATE
        open_gate();
    #endif
    Sleep(0, 500000);
    follow_line();
    follow_square_line();
    return 0;
}
