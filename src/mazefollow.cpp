#include <sys/time.h>
#include <stdio.h>
#include <cmath>
#include <string.h>

#include "mazefollow.h"
#include "movement.h"
#include "extern.h"
#include "util.h"
#include "sensor_average.h"

void follow_wall(){
  
  /**
   * Reads data from the IR sensors,
   * stores the values in 3 variables
   * and adjusts motors accordingly
   */
	int frontVal, leftVal, rightVal = 0;
	while (true) {
		frontVal = get_sensor_average(FRONT_PIN, TESTS); // get_sensor_average
		leftVal = get_sensor_average(LEFT_PIN, TESTS);
		rightVal = get_sensor_average(RIGHT_PIN, TESTS);
                int error = (rightVal - leftVal) / 7.5;
		printf("Front: %i, Left: %i, Right: %i Error: %i\n", frontVal, leftVal, rightVal, error);
		// If there is room on the left
		/*if (leftVal < LEFT_MAX){
			printf("Turn Left\n");
			set_speed(0);
			turn(-1 * SHARP_TURN);
			Sleep(0, TURN_WAIT);
			reset_turn();
			set_speed(SPEED_DEF);
			move();
		}
		// If there is room at the front
		else*/ if (frontVal < FRONT_MAX){
			//printf("Go Forward\n");
			set_speed(SPEED_DEF);
			/*if (leftVal > LEFT_MIN){
				turn(SLIGHT_TURN);
			}
			if (rightVal > RIGHT_MIN){
				turn(-1 * SLIGHT_TURN);
			}*/
                        turn(error);
		}
		// If there is room on the right
		/*else if (rightVal < RIGHT_MAX){
			printf("Turn Right\n");
			set_speed(0);
			turn(SHARP_TURN);
			Sleep(0, TURN_WAIT);
			reset_turn();
			set_speed(SPEED_DEF);
			move();
		}*/
		// If there is no room to the front or either side
		else{
			while(leftVal>=LEFT_MAX || rightVal>=RIGHT_MAX){
				printf("Reversing\n");
				set_motor(MOTOR_LEFT, (-SPEED_DEF) - error);
				set_motor(MOTOR_RIGHT, (-SPEED_DEF) + error);
                                leftVal = read_analog(LEFT_PIN);
                                rightVal = read_analog(RIGHT_PIN);
			}
			if(rightVal<RIGHT_MAX){
				turn(SHARP_TURN);
			}
			else if(leftVal<LEFT_MAX){
				turn(-1 * SHARP_TURN);
			}
                        Sleep(0, TURN_WAIT);
		}
		// Sleeps to allow robot to move forward
		// Sleep(0, 100);
	}
}
