#include <sys/time.h>
#include <stdio.h>
#include <cmath>
#include <string.h>

#include "linefollow.h"
#include "movement.h"
#include "extern.h"
#include "util.h"

/**
 * Makes the robot attempt to follow a line, halting should it lose it.
 */
void follow_line()
{
    int movement = 0;
    int integral = 0;
    int previous_error = 0;
    timeval prev_time;
    // Initialize prev_time with the current time
    gettimeofday(&prev_time, nullptr);

    for (int i = 0; true; i++)
    {
        // Delay slightly before next iteration
        //Sleep(0, UPDATE_DELAY);
        LineInfo line = {{0,0,0,0,0,0,0,0,0},0};
        int error = sample_image(line);

        // Check if we have reached the end of the curvy maze
        if (line.compass[3] > 0 && line.compass[4] > 0 && line.compass[5] > 0 &&
            line.compass[0] + line.compass[1] + line.compass[2] == 0)
	{
	    break;
	}

        // Try reverse if line is lost
        if (line.white_count < STOP_COUNT)
        {
            set_speed(-SPEED_DEF);
            reset_turn();
            //turn(sign(previous_error) * SPEED_DEF * 1);
            move();
            // We need to get time here as to not mess with the next
            // iteration's derivative
            gettimeofday(&prev_time, nullptr);
            Sleep(0, REVERSE_DELAY);
            i--;
            continue;
        }
        else {
            // This is here to make the robot go forward after reversing
            set_speed(SPEED_DEF);
        }

        // Calculate how much to turn by
        int pixels_x = IMAGE_SIZE_X / SAMPLE_STEPS;
        int pixels_y = IMAGE_SIZE_Y / SAMPLE_STEPS;
        // Doing Proportional
        int proportional_error = error / (pow(pixels_x, SCALE_POW) * pixels_y);
        // Doing Integral
        int proportional_integral = i == 0 ? 0 : integral / i;

        // Doing Derivative
        // We need the time in seconds, but not rounded to a second as we'll
        // never spend that long and a time rounded to 0 is worthless. To
        // fix this we get the time in microseconds and add that to the seconds
        timeval curr_time;
        gettimeofday(&curr_time, nullptr);
        long d_sec = curr_time.tv_sec - prev_time.tv_sec;
        int d_usec = curr_time.tv_usec - prev_time.tv_usec;
        double d_time = d_usec / 1000000.0 + d_sec;
        int derivative = (proportional_error - previous_error) / d_time;
        prev_time = curr_time;

        // Now to compile all the calculations
        // Start with the proportional component;
        movement = proportional_error * K_P;
        // Add the integral component
        movement += proportional_integral * K_I;
        // Add the derivative component
        movement += derivative * K_D;
        // Update integral component
        integral += proportional_error;
        // Store previous error for the derivative
        previous_error = proportional_error;

	// Turn
	turn(movement);
    }
}

void follow_square_line() 
{
    halt();
}

/**
 * Samples a snapshot from the camera to retrieve the line following error
 *
 * @param white_count The number of white pixels detected, updated by reference.
 * @return The line-following error in the image
 */
int sample_image(LineInfo &line)
{
    int error = 0;
    take_picture();

    // Get pixels from across the entire image, not just one line
    for (int x = 0; x < IMAGE_SIZE_X; x += SAMPLE_STEPS) {
        for (int y = 0; y < IMAGE_SIZE_Y; y += SAMPLE_STEPS)
        {
            int pixel_value = get_pixel(x, y, COLOR_WHITE);

            // Check if pixel is white
            if (pixel_value > WHITE_THRESHOLD)
            {
                // Add to counter if a pixel is 'white enough' to be part of a
                // line
                line.white_count++;
	        int location = x / (IMAGE_SIZE_X / 3) + 3 * (y / (IMAGE_SIZE_Y / 3));
	        line.compass[location]++;
                // Now weigh the pixel into the error
                error += sign(x - IMAGE_SIZE_X / 2) * pow((x - IMAGE_SIZE_X / 2), SCALE_POW);
            }
        }
    }
    return error;
}
