#ifndef __LINEFOLLOW_H__
#define __LINEFOLLOW_H__

const int IMAGE_SIZE_X = 320;
const int IMAGE_SIZE_Y = 240;
// The program samples every SAMPLE_STEPS pixels
const int SAMPLE_STEPS = 5;
const int COLOR_WHITE = 3;
// The time length of reverse, in microseconds
// Cannot exceed 999999Î
const int REVERSE_DELAY = 20000;
const int TURN_90_DELAY = 40000;
const int TURN_90_SPEED = 70;
// A pixel is considered white (a line) if it exceeds this value
const int WHITE_THRESHOLD = 125;
// This number of white pixels is required for the bot to move
const int STOP_COUNT = 30;
// The following are PID constants.
const double K_P = 1.55;
const double K_I = 0.01;
const double K_D = 0.225;
// An extra scaling constant applied prior to PID
const double SCALE_POW = 2;

const int NORTH = 0;
const int EAST = 1;
const int SOUTH = 2;
const int WEST = 3;
struct LineInfo
{
    // Compass coordinates
    bool north;
    bool east;
    bool south;
    bool west;
    // For knowing when to stop turning on square follow
    int north_error;
    // Other info
    int white_count;
};

void follow_line();
void follow_square_line();
inline void square_line_rotate(bool start_on_line);
inline int sample_image(LineInfo &line);
inline int sample_pixel(LineInfo &line, int x, int y);

#endif

