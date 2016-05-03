#ifndef __MOVEMENT_H__
#define __MOVEMENT_H__

const int MOTOR_LEFT = 1;
const int MOTOR_RIGHT = 2;

const int SPEED_MAX = 255;
// The difference between the motor speeds cannot exceed
// 	SPEED_MAX / DELTA_MAX_DIV
// At value 1 there is no limit aside from the hard limit at SPEED_MAX
const int DELTA_MAX_DIV = 4;
const int DELTA_MAX = SPEED_MAX / DELTA_MAX_DIV;

void move();
void turn(int amount);
void reset_turn();
void set_speed(int speed);
void halt();

#endif
