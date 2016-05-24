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
	int frontVal = 0;
	int leftVal = 0;
	int rightVal = 0;
	while true{
		frontVal = get_sensor_average(FRONT_PIN, TESTS);
		leftVal = get_sensor_average(LEFT_PIN, TESTS);
		rightVal = get_sensor_average(RIGHT_PIN, TESTS);
		// If there is room on the left
		if (leftVal > LEFT_MIN){
			set_speed(0);
			turn(-1 * SHARP_TURN);
		}
		// If there is room at the front
		else if (frontVal > FRONT_MIN){
			set_speed(SPEED_DEF);
			move();
		}
		// If there is room on the right
		else if (rightVal > RIGHT_MIN){
			set_speed(0);
			turn(SHARP_TURN);
		}
		// If there is no room to the front or either side
		else{
			//Reverse
		}
		sleep(0, 5000000);
	}
	
}
