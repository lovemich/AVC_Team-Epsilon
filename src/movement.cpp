#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "extern.h"
#include "movement.h"
#include "util.h"

// Speed is 100% at 255
static int speed_base = SPEED_MAX / 4;
// Negative speed_delta gives
static int speed_delta = 0;

/**
 * Sets the motor speed for both motors
 */
void move() {
  int left_direction = (speed_base - speed_delta) >= 0 ? 1 : 2;
  int right_direction = (speed_base + speed_delta) >= 0 ? 1 : 2;
  int left_speed = abs(speed_base - speed_delta);
  int right_speed = abs(speed_base + speed_delta);
  set_motor(MOTOR_LEFT,  left_direction,  left_speed);
  set_motor(MOTOR_RIGHT,  right_direction,  right_speed);
}

/**
 * @param amount the amount to change the turning by, with negative as
 * towards left.
 */
void turn(int amount) {
  // Make sure the difference limit is not violated
  if (DELTA_MAX < abs(amount)) {
    amount = sign(amount) * DELTA_MAX;
  }
  // Make sure the speed limit is not violated
  int left = speed_base - amount;
  int right = speed_base + amount;
  if (left < -SPEED_MAX || left > SPEED_MAX || right < -SPEED_MAX || right > SPEED_MAX) {
    amount = sign(amount) * (SPEED_MAX - speed_base);
  }
  // Actually update the turning now
  speed_delta = amount;
  printf("Turning by %i", amount);
  move();
}

/**
 * Resets the deltas of the motors so that they move at the same speed.
 */
void reset_turn() {
  speed_delta = 0;
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
  speed_delta = 0;
  move();
}
