#ifndef __MOVEMENT_H__
#define __MOVEMENT_H__

const int MOTOR_LEFT = 1;
const int MOTOR_RIGHT = 2;

const int SPEED_MAX = 255;
const int SPEED_DEF = 90;

void move();
void turn(int amount);
void reset_turn();
void set_speed(int speed);
void halt();

#endif
