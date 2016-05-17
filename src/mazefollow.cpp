#include <sys/time.h>
#include <stdio.h>
#include <cmath>
#include <string.h>

#include "linefollow.h"
#include "movement.h"
#include "extern.h"
#include "util.h"

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
		frontVal = get_sensor_average(, int total)
		// While there is room in front
		while (frontVal > 0){
			move();
			// Checks left and right side for room
			leftVal = get_sensor_average(L, 5);
			rightVal = get_sensor_average(R, 5);
			//If there is room on the left
			if (leftVal > 0){
				turn(-10);
			}
			// If there is room on the right
			else if (rightVal > 0){
				turn(10);
			}
		}
		// If there is no room to the front or either side
		while ((frontVal <= 0) && (leftVal <= 0) && (rightVal <= 0)){
			//Reverse
		}
	}
	}
}
