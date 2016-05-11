#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "extern.h"
#include "movement.h"
#include "util.h"

// Speed is 100% at 255
static int speed_base = SPEED_DEF;
// Negative speed_delta gives
static int speed_delta = 0;

/**
 * Sets the motor speed for both motors
 */
void move() {
  int left_speed = speed_base - speed_delta;
  int right_speed = speed_base + speed_delta;
  printf("Movement L:R = %i : %i", left_speed, right_speed);
  set_motor(MOTOR_LEFT,  left_speed);
  set_motor(MOTOR_RIGHT,  right_speed);
}

/**
 * @param amount the amount to change the turning by, with negative as
 * towards left.
 */
void turn(int amount) {
  // Make sure the speed limit is not violated
  int left_speed = speed_base - amount;
  int right_speed = speed_base + amount;
  if (left_speed < -SPEED_MAX || left_speed > SPEED_MAX || right_speed < -SPEED_MAX || right_speed > SPEED_MAX) {
    amount = sign(amount) * (SPEED_MAX - speed_base);
  }
  // Actually update the turning now
  speed_delta = amount;
  printf("Turning by %i\n", amount);
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
