#ifndef __LINEFOLLOW_H__
#define __LINEFOLLOW_H__

const int IMAGE_SIZE_X = 320;
const int IMAGE_SIZE_Y = 240;
// The offset towards right at which sampling begins
const int SAMPLE_OFFSET = (IMAGE_SIZE_X / 3) * 2;
// The program samples every SAMPLE_STEPS pixels
const int SAMPLE_STEPS = 10;
const int COLOR_WHITE = 3;
// The time before the next update, in microseconds
// Cannot excede 999999μs
const int UPDATE_DELAY = 500000;
// A pixel is considered white (a line) if it excedes this value
const int STOP_THRESHOLD = 255/2;
// This number of white pixels is required for the bot to move
const int STOP_COUNT = (IMAGE_SIZE_X / SAMPLE_STEPS) / 10;

void follow_line();

#endif

