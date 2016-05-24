#include <sys/time.h>

#ifndef __UTIL_H__
#define __UTIL_H__

// Evaluates to 1 if positive, -1 if negative, and 0 if either 0
#define sign(x) ((x > 0) - (x < 0))

void stop(int signum);

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

#endif
