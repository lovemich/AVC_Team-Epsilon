#ifndef __LINEFOLLOW_H__
#define __LINEFOLLOW_H__

const int IMAGE_SIZE_X = 320;
const int IMAGE_SIZE_Y = 240;
// The program samples every SAMPLE_STEPS pixels
const int SAMPLE_STEPS = 5;
const int COLOR_WHITE = 3;
// The time before the next update, in microseconds
// Cannot exceed 999999μ
const int UPDATE_DELAY = 1000;
const int REVERSE_DELAY = 50000;
// A pixel is considered white (a line) if it exceeds this value
const int WHITE_THRESHOLD = 120;
// This number of white pixels is required for the bot to move
const int STOP_COUNT = (IMAGE_SIZE_X / SAMPLE_STEPS) * 1.5;
// The following are PID constants.
const double K_P = 1;
const double K_I = 0.05;
const double K_D = 0.1;

void follow_line();
int sample_image(int &white_count);

#endif

