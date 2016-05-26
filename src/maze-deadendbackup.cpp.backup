//It's a mess, but I have till next Wednesday to not make it a mess, bear with me

#include <stdio.h>
#include <cmath>
#include <string.h>

#include "movement.h"
#include "mazefollow.h"

void deadendbackup(){
	if (frontVal<50 && leftVal<50 && rightVal<50){
		while(leftVal<50 && rightVal<50){
			set_motor(MOTOR_LEFT, (-SPEED_DEF));
			set_motor(MOTOR_RIGHT, (-SPEED_DEF)):
		}
		if(rightVal>50){
		turn(SHARP_TURN);
		}
		else if(leftVal>50){
		turn(-1 * SHARP_TURN);
		}
	}
}
