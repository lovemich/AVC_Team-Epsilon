#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <csignal>

#include "extern.h"
#include "util.h"
#include "gate.h"
#include "linefollow.h"
#include "mazefollow.h"

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
    printf("ATTEMPT switching to maze\n");
    follow_wall();
    return 0;
}
