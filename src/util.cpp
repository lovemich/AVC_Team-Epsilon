#include <stdlib.h>
#include <sys/time.h>

#include "util.h"

void stop(int signum)
{
    set_motor(1, 0);
    set_motor(2, 0);
    exit(signum);
}

inline double get_seconds(timeval &prev_time)
{
    timeval curr_time;
    gettimeofday(&curr_time, nullptr);
    long d_sec = curr_time.tv_sec - prev_time.tv_sec;
    int d_usec = curr_time.tv_usec - prev_time.tv_usec;
    double d_time = d_usec / 1000000.0 + d_sec;
    prev_time = curr_time;
    return d_time;
}
