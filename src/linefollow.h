#ifndef __LINEFOLLOW_H__
#define __LINEFOLLOW_H__

const int IMAGE_SIZE_X = 320;
const int IMAGE_SIZE_Y = 240;
// The offset towards right at which sampling begins
// Currently unused
const int SAMPLE_OFFSET = (IMAGE_SIZE_X / 3) * 2;
// The program samples every SAMPLE_STEPS pixels
const int SAMPLE_STEPS = 5;
const int COLOR_WHITE = 3;
// The time before the next update, in microseconds
// Cannot excede 999999μs
const int UPDATE_DELAY = 5000;
// A pixel is considered white (a line) if it excedes this value
const int WHITE_THRESHOLD = 150;
// This number of white pixels is required for the bot to move
const int STOP_COUNT = (IMAGE_SIZE_X / SAMPLE_STEPS) * 2;
// The following are PID constants. Their sum should probably not excede 1.
const double K_P = 1.5;
const double K_I = 0;
const double K_D = 0;

void follow_line();
int sample_image(int &white_count);

#endif

