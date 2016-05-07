#include "linefollow.h"
#include "movement.h"
#include "extern.h"

/**
 * Makes the robot attempt to follow a line, halting should it lose it.
 */
void follow_line() {
  int integral = 0;
  for (int i = 0; true; i++) {
    take_picture();
    int white_count = 0;
    int error = 0;
    // Get pixels from across the entire image, not just one line
    for (int x = 0; x < IMAGE_SIZE_X; x += SAMPLE_STEPS) {
      for (int y = 0; y < IMAGE_SIZE_Y; y += SAMPLE_STEPS) {
        int pixel_value = get_pixel(y, x, COLOR_WHITE);
        // Check if pixel is white
        if (pixel_value > STOP_THRESHOLD) {
          // Add to counter if a pixel is 'white enough' to be part of a line
          white_count++;
          // Now weigh the pixel into the error
          // I'm assuming y increases downwards when weighing
          weight = y > (IMAGE_SIZE_Y / 2) ? 2 : 1;
          error += (i - IMAGE_SIZE_X / 2) * weight;
        }
      }
    }
    // Break if there are not enough 'line worthy' pixels
    if (white_count < STOP_COUNT) {
      break;
    }
    // Calculate how much to turn by
    int pixels_x = IMAGE_SIZE_X / SAMPLE_STEPS;
    int pixels_y = (3 * (IMAGE_SIZE_Y / 2)) / SAMPLE_STEPS;
    int proportional_error = error / (pixels_x * pixels_y);
    int proportional_integral = i == 0 ? 0 : integral / i;
    int movement;
    // Start with the proportional component;
    movement = proportional_error * K_P;
    // Add the integral component
    movement += integral * K_I;
    // Update integral component
    integral += proportional_error;
    // Turn and then delay slightly before next iteration
    turn(movement);
    Sleep(0, UPDATE_DELAY);
  }
  halt();
}
