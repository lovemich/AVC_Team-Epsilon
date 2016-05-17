#ifndef __MAZEFOLLOW_H__
#define __MAZEFOLLOW_H__

// Thresholds for IR sensors
const int FRONT_MIN = 50;
const int LEFT_MIN = 50;
const int RIGHT_MIN = 50;
// Pins for IR sensors
const int FRONT_PIN = 0;
const int LEFT_PIN = 0;
const int RIGHT_PIN = 0;
// 90 degree turn values
const int SHARP_TURN = 50;
// Number of tests
const int TESTS = 10;

void follow_wall();
