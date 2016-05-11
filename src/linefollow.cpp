#include <sys/time.h>
#include <stdio.h>
#include <cmath>

#include "linefollow.h"
#include "movement.h"
#include "extern.h"
#include "util.h"

/**
 * Makes the robot attempt to follow a line, halting should it lose it.
 */
void follow_line() {
  int movement = 0;
  int integral = 0;
  int previous_error = 0;
  timeval prev_time;
  gettimeofday(&prev_time, nullptr);
  for (int i = 0; true; i++) {
    // Delay slightly before next iteration
    Sleep(0, UPDATE_DELAY);
    int white_count = 0;
    int error = sample_image(white_count);
    // Break if there are not enough 'line worthy' pixels
    if (white_count < STOP_COUNT) {
      set_speed(-SPEED_DEF);
      //turn(-movement);
      reset_turn();
      move();
      gettimeofday(&prev_time, nullptr);
      Sleep(0, REVERSE_DELAY);
      i--;
      continue;
    } else {
      set_speed(SPEED_DEF);
    }
    // Calculate how much to turn by
    int pixels_x = IMAGE_SIZE_X / SAMPLE_STEPS;
    int pixels_y = IMAGE_SIZE_Y / SAMPLE_STEPS;
    int proportional_error = error / (pow(pixels_x, 2) * pixels_y);
    int proportional_integral = i == 0 ? 0 : integral / i;
    timeval curr_time;
    gettimeofday(&curr_time, nullptr);
    long d_sec = (curr_time.tv_sec - prev_time.tv_sec);
    double d_time = (curr_time.tv_usec - prev_time.tv_usec) / 1000000.0 + d_sec;
    int derivative = (proportional_error - previous_error) / d_time;
    prev_time = curr_time;
    // Start with the proportional component;
    movement = proportional_error * K_P;
    // Add the integral component
    movement += proportional_integral * K_I;
    // Add the derivative component
    movement += derivative * K_D;
    // Update integral component
    integral += proportional_error;
    // Store previous error
    previous_error = proportional_error;
    // Turn
    turn(movement);
  }
  halt();
}

/**
 * Samples a snapshot from the camera to retrieve the line following error
 *
 * @param white_count The number of white pixels detected, updated by reference.
 * @return The line-following error in the image
 */
int sample_image(int &white_count) {
  int error = 0;
  take_picture();
  // Get pixels from across the entire image, not just one line
  for (int x = 0; x < IMAGE_SIZE_X; x += SAMPLE_STEPS) {
    for (int y = 0; y < IMAGE_SIZE_Y; y += SAMPLE_STEPS) {
      int pixel_value = get_pixel(x, y, COLOR_WHITE);
      // Check if pixel is white
      if (pixel_value > WHITE_THRESHOLD) {
        // Add to counter if a pixel is 'white enough' to be part of a line
        white_count++;
        // Now weigh the pixel into the error
        error += sign(x - IMAGE_SIZE_X / 2) * pow((x - IMAGE_SIZE_X / 2), 2);
      }
    }
  }
  return error;
}
