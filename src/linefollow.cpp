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
    LineInfo line;
    int movement = 0;
    int integral = 0;
    int previous_error = 0;
    timeval prev_time;
    // Initialize prev_time with the current time
    gettimeofday(&prev_time, nullptr);

    set_speed(SPEED_DEF);

    for (int i = 0; true; i++)
    {
        int error = sample_image(line);

        // Check if we have reached the end of the curvy maze
        if (!line.north && line.east && line.south && line.west)
        {
            printf("ATTEMPT stop\n");
            break;
        }

        // Try reverse if line is lost
        if (line.white_count < STOP_COUNT)
        {
            if (line.east)
            {
                printf("ATTEMPT save right\n");
                set_speed(0);
                turn(75);
                while (!line.north)
                {
                    sample_image(line);
                }
            }
            else if (line.west)
            {
                printf("ATTEMPT save left\n");
                set_speed(0);
                turn(-75);
                while (!line.north)
                {
                    sample_image(line);
                }
            }
            else
            {
                printf("ATTEMPT reverse %i : %i\n", line.white_count, STOP_COUNT);
                set_speed(-SPEED_DEF);
                reset_turn();
                //turn(sign(previous_error) * SPEED_DEF * 1);
                move();
            }
            // We need to get time here as to not mess with the next
            // iteration's derivative
            gettimeofday(&prev_time, nullptr);
            Sleep(0, REVERSE_DELAY);
            i--;
            continue;
        }
        else
        {
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
        double d_time = get_seconds(prev_time);
        int derivative = (proportional_error - previous_error) / d_time;

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
    halt();
}

/*void follow_square_line()
{
    LineInfo line;
    int movement = 0;
    int previous_error = 0;
    timeval prev_time;
    // Initialize prev_time with the current time
    gettimeofday(&prev_time, nullptr);

    while (true)
    {
        int error = sample_image(line);

        // Check left
        if (line.west && line.south)
        {
            printf("ATTEMPT Going square left\n");
            set_speed(TURN_90_REVERSE);
            turn(0);
            Sleep(0, TURN_90_DELAY);
            set_speed(0);
            turn(-TURN_90_SPEED);
            square_line_rotate(line.north);
            set_speed(60);
            turn(0);
            Sleep(0, TURN_90_DELAY);
            gettimeofday(&prev_time, nullptr);
        }
        // Check right
        else if (!line.north && line.east && line.south && !line.west)
        {
            printf("ATTEMPT Going square right\n");
            set_speed(TURN_90_REVERSE);
            turn(0);
            Sleep(0, TURN_90_DELAY);
            set_speed(0);
            turn(TURN_90_SPEED);
            square_line_rotate(line.north);
            set_speed(60);
            turn(0);
            Sleep(0, TURN_90_DELAY);
            gettimeofday(&prev_time, nullptr);
        }
        // Check center line stop
        else if (!line.north && !line.east && line.south && !line.west)
        {
            printf("ATTEMPT Dead end! Do a barrel roll!\n");
            set_speed(0);
            turn(TURN_90_SPEED);
            square_line_rotate(false);
            turn(0);
            gettimeofday(&prev_time, nullptr);
            //Sleep(0, REVERSE_DELAY / 2);
        }

        // Try reverse if line is lost
        if (line.white_count < STOP_COUNT)
        {
            printf("ATTEMPT reversing\n");
            set_speed(-60);
            reset_turn();
            move();
            // We need to get time here as to not mess with the next
            // iteration's derivative
            gettimeofday(&prev_time, nullptr);
            Sleep(0, REVERSE_DELAY / 2);
            continue;
        }
        else {
            // This is here to make the robot go forward after reversing
            set_speed(60);
        }

        // Calculate how much to turn by
        int pixels_x = IMAGE_SIZE_X / SAMPLE_STEPS;
        int pixels_y = IMAGE_SIZE_Y / SAMPLE_STEPS;
        // Doing Proportional
        int proportional_error = error / (pow(pixels_x, SCALE_POW) * pixels_y);

        // No integral here; with sharp corners it is more likely to throw us
        // off than actually help

        // Doing Derivative
        // We need the time in seconds, but not rounded to a second as we'll
        // never spend that long and a time rounded to 0 is worthless. To
        // fix this we get the time in microseconds and add that to the seconds
        double d_time = get_seconds(prev_time);
        int derivative = (proportional_error - previous_error) / d_time;

        // Now to compile all the calculations
        // Start with the proportional component;
        movement = proportional_error * K_P;
        // Add the derivative component
        movement += derivative * K_D;
        // Store previous error for the derivative
        previous_error = proportional_error;

        // Turn
        turn(movement);
    }
    halt();
}*/

void follow_square_line()
{
    while (true)
    {
        take_picture();
        //int error_left = 0;
        //int error_right = 0;
        bool seen_left = false;
        bool seen_right = false;
        for (int i = -100; i < 0; i++) {
            int pixel = get_pixel(IMAGE_SIZE_X / 2 + i, IMAGE_SIZE_Y / 2, COLOR_WHITE);
            if (pixel >= WHITE_THRESHOLD) {
                seen_left = true;
                break;
            }
            //error_left += pixel * i;
        }
        for (int i = 1; i <= 100; i++) {
            int pixel = get_pixel(IMAGE_SIZE_X / 2 + i, IMAGE_SIZE_Y / 2, COLOR_WHITE);
            if (pixel >= WHITE_THRESHOLD) {
                seen_right = true;
                break;
            }
            //error_right += pixel * i;
        }

        if (!seen_left && !seen_right) {
            set_speed(30);
            turn(-65);
        } else if (seen_left && seen_right) {
            set_speed(0);
            turn(65);
        } else if (seen_left && !seen_right) { //(-error_left > error_right) {
            set_speed(30);
            turn(65);
        } else {
            set_speed(0);
            turn(-65); // (0);
        }
    }
    halt();
}

inline void square_line_rotate(bool start_on_line)
{
    int stage = start_on_line ? 0 : 1;
    while (true)
    {
        take_picture();
        for (int i = -10; i < 10; i++) {
        int north_center = get_pixel(IMAGE_SIZE_X / 2 + i, 0, COLOR_WHITE);
        if (stage == 0 && north_center < WHITE_THRESHOLD)
        {
            stage = 1;
            break;
        }
        else if (stage == 1 && north_center > WHITE_THRESHOLD)
        {
            printf("ATTEMPT seen: %i\n", north_center);
            return;
        }
        }
    }
}

/**
 * Samples a snapshot from the camera to retrieve the line following error
 *
 * @param white_count The number of white pixels detected, updated by reference.
 * @return The line-following error in the image
 */
inline int sample_image(LineInfo &line)
{
    line = {false, false, false, false, 0};

    int error = 0;
    take_picture();

    // Get pixels from across the entire image, not just one line
    for (int x = 0; x < IMAGE_SIZE_X; x += SAMPLE_STEPS) {
        for (int y = 0; y < IMAGE_SIZE_Y; y += SAMPLE_STEPS)
        {
            error += sample_pixel(line, x, y);
        }
    }
    return error;
}

inline int sample_pixel(LineInfo &line, int x, int y)
{
    int pixel_value = get_pixel(x, y, COLOR_WHITE);

    // Check if pixel is white
    if (pixel_value > WHITE_THRESHOLD)
    {
        // Add to counter if a pixel is 'white enough' to be part of a
        // line
        line.white_count++;

        if (y == 0)
        {
            line.north = true;
            //if (x == IMAGE_SIZE_X / 2)
            //{
            //    line.north_center = true;
            //}
        }
        else if (y > (IMAGE_SIZE_Y - 1) - SAMPLE_STEPS)
        {
            line.south = true;
        }

        if (x == 0)
        {
            line.west = true;
        }
        else if (x > (IMAGE_SIZE_X - 1) - SAMPLE_STEPS)
        {
            line.east = true;
        }

        // Now weigh the pixel into the error
        return sign(x - IMAGE_SIZE_X / 2) * pow((x - IMAGE_SIZE_X / 2), SCALE_POW);
    }
    // No pixel: no error
    return 0;
}

