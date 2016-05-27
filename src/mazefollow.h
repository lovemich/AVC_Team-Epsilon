#ifndef __MAZEFOLLOW_H__
#define __MAZEFOLLOW_H__

// Thresholds for IR sensors
const int LEFT_MIN = 530;
const int RIGHT_MIN = 490;
const int FRONT_MIN = 520;

const int LEFT_MAX = 150;
const int RIGHT_MAX = 100;
// Pins for IR sensors
const int FRONT_PIN = 0;
const int LEFT_PIN = 1;
const int RIGHT_PIN = 2;
// Turn values
const int SHARP_TURN = 80;
const int SLIGHT_TURN = 10;
// Number of tests
const int TESTS = 10;
// Wait time for turning
const int TURN_WAIT = 1000;

void follow_wall();

#endif
