#include <sys/time.h>
#include <stdio.h>
#include <cmath>
#include <string.h>

#include "mazefollow.h"
#include "movement.h"
#include "extern.h"
#include "util.h"
#include "sensor_average.h"

//void follow_wall(){
  
  /**
   * Reads data from the IR sensors,
   * stores the values in 3 variables
   * and adjusts motors accordingly
   */
//	int frontVal, leftVal, rightVal = 0;
//	while (true) {
//		frontVal = get_sensor_average(FRONT_PIN, TESTS); // get_sensor_average
//		leftVal = get_sensor_average(LEFT_PIN, TESTS);
//		rightVal = get_sensor_average(RIGHT_PIN, TESTS);
//                int error = (rightVal - leftVal) / 7.5;
//		printf("Front: %i, Left: %i, Right: %i Error: %i\n", frontVal, leftVal, rightVal, error);
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
		else*/
//		if (frontVal < FRONT_MAX){
			//printf("Go Forward\n");
//			set_speed(SPEED_DEF);
			/*if (leftVal > LEFT_MIN){
				turn(SLIGHT_TURN);
			}
			if (rightVal > RIGHT_MIN){
				turn(-1 * SLIGHT_TURN);
			}*/
//                        turn(error);
//		}
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
//		else{
//			while(leftVal>=LEFT_MAX || rightVal>=RIGHT_MAX){
//				printf("Reversing\n");
//				set_motor(MOTOR_LEFT, (-SPEED_DEF) - error);
//				set_motor(MOTOR_RIGHT, (-SPEED_DEF) + error);
//                                leftVal = read_analog(LEFT_PIN);
//                                rightVal = read_analog(RIGHT_PIN);
//			}
//			if(rightVal<RIGHT_MAX){
//				turn(SHARP_TURN);
//			}
//			else if(leftVal<LEFT_MAX){
//				turn(-1 * SHARP_TURN);
//			}
//                        Sleep(0, TURN_WAIT);
//		}
//		// Sleeps to allow robot to move forward
//		// Sleep(0, 100);
//	}
//}

/*void follow_wall()
{
    set_speed(60);
    turn(0);
    while (true)
    {
        //printf("average: %d -- %d\n", read_analog(LEFT_PIN), read_analog(RIGHT_PIN));
        int turn_val = (read_analog(LEFT_PIN) - read_analog(RIGHT_PIN)) / 10;
        //turn(turn_val);
        printf("turning by %d\n", turn_val);
        if (turn > 0) {
           turn(-15);
           Sleep(0, 500000);
           turn(15);
           Sleep(0, 500000);
           turn(0);
        } else {
           turn(15);
           Sleep(0, 500000);
           turn(15);
           Sleep(0, 500000);
           turn(0);
        }
    }
    halt();
}*/

/*void follow_wall()
{
    set_speed(0);
    while (true)
    {
        take_picture();
        bool seen_wall = false;
        for (int i = -100; i < 100; i++) { for (int j = -50; j <= 50; j++) {
            int pixel = get_pixel(IMAGE_SIZE_X / 2 + i, IMAGE_SIZE_Y / 2 + j, COLOR_WHITE);
            if (pixel >= WHITE_THRESHOLD) {
                seen_wall = true;
                goto found_wall;
            }
        }}
        found_wall:

        if (seen_wall) {
            set_speed(20);//20
            turn(75);//-80
        } else {
            set_speed(30);//30
            turn(-75);//80
        }
    }
    halt();
}
*/
void follow_wall(){
	set_speed(60);
	turn(0);
	while(true){
		frontVal = read_analog(FRONT_PIN);
		leftVal = read_analog(LEFT_PIN);
		rightVal = read_analog(RIGHT_PIN);
		while(leftVal < (rightVal+70) && leftVal > (rightVal-70)){
			set_speed(80);
		}
		while(leftVal > (rightVal+70)){
			set_speed(40);			
			turn(10);
			Sleep(0, 500);
		}
		while(leftVal < (rightVal+70)){
			set_speed(40);			
			turn(-10);
			Sleep(0, 500);
		}
		if(frontVal > 550){
			if(rightVal < 200){
				turn(1 * SHARP_TURN);
				Sleep(0, TURN_WAIT);
			}
			if(leftVal < 200){
				turn(-1 * SHARP_TURN);
				Sleep(0, TURN_WAIT);
			}
		}
	}
}
