#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern "C" {
  int init(); // InitHardware()
  int read_analog(int ch_adc); // ReadAnalog(int ch_adc)
  int set_motor(int ch_motor, int dir, int speed);
  int Sleep(int sec, int usec);
}

const int SPEED_MAX = 255;
// The difference between the motor speeds cannot exceed
// 	SPEED_MAX / DELTA_MAX_DIV
// At value 1 there is no limit aside from the hard limit at SPEED_MAX
const int DELTA_MAX_DIV = 4;
const int DELTA_MAX_DIFF = SPEED_MAX / DELTA_MAX_DIV;
// Speed is 100% at 255
int speed_base = SPEED_MAX / 2;
// These are the difference between the 
int speed_delta_left = 0;
int speed_delta_right = 0;

int main() {
  init();
  move();
  Sleep(1, 0);
  halt();
  return 0;
}

/**
 * Sets the motor speed for both motors
 */
void move() {
  set_motor(MOTOR_LEFT,  1,  speed_base + speed_delta_left);
  set_motor(MOTOR_RIGHT,  1,  speed_base + speed_delta_right);
}

/**
 * @param amount the amount to change the turning by, with negative as
 * towards left.
 */
void turn(int amount) {
  // Make sure the difference limit is not violated
  if (DELTA_MAX_DIFF < abs(-speed_delta_left + speed_delta_right)) {
    return;
  }
  int left_change = speed_delta_left - amount;
  int right_change = speed_delta_right + amount;
  if (left_change < -SPEED_MAX || left_change > SPEED_MAX) {
    speed_delta_left = left_change;
  }
  if (right_change < -SPEED_MAX || right_change > SPEED_MAX) {
    speed_delta_right = right_change;
  }
  move();
}

/**
 * Resets the deltas of the motors so that they move at the same speed.
 */
void reset_turn() {
  speed_delta_left = 0;
  speed_delta_right = 0;
  move();
}

/**
 * @param speed sets the base speed to a specified value
 */
void set_speed(int speed) {
  speed_base = speed;
  move();
}

/**
 * Stops the robot entirely
 */
void halt() {
  speed_base = 0;
  speed_delta_left = 0;
  speed_delta_right = 0;
  move();
}