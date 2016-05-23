#ifndef __UTIL_H__
#define __UTIL_H__

// Evaluates to 1 if positive, -1 if negative, and 0 if either 0
#define sign(x) ((x > 0) - (x < 0))

void stop(int signum);
inline double get_seconds(timeval &prev_time);

#endif
