#ifndef __LINEFOLLOW_H__
#define __LINEFOLLOW_H__

const int IMAGE_SIZE_X = 320;
const int IMAGE_SIZE_Y = 240;
// The program samples every SAMPLE_STEPS pixels
const int SAMPLE_STEPS = 5;
const int COLOR_WHITE = 3;
// The time length of reverse, in microseconds
// Cannot exceed 999999μ
const int REVERSE_DELAY = 20000;
// A pixel is considered white (a line) if it exceeds this value
const int WHITE_THRESHOLD = 125;
// This number of white pixels is required for the bot to move
const int STOP_COUNT = (IMAGE_SIZE_X / SAMPLE_STEPS) * 3;
// The following are PID constants.
const double K_P = 1.55;
const double K_I = 0.01;
const double K_D = 0.225;
// An extra scaling constant applied prior to PID
const double SCALE_POW = 2;

struct LineInfo
{
    // Compass coordinates
    // Goes west to east for each row (including center row)
    int compass[9];
    // Other info
    int white_count;
};

void follow_line();
void follow_square_line();
void clear_line(LineInfo &line);
int sample_image(LineInfo &line);

#endif

