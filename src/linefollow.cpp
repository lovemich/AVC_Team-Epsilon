#include "linefollow.h"
#include "movement.h"
#include "extern.h"

/**
 * Makes the robot attempt to follow a line, halting should it lose it.
 */
void follow_line() {
  while (true) {
    int threshold_count = 0;
    int movement = 0;
    for (int i = SAMPLE_OFFSET; i < IMAGE_SIZE_X; i += SAMPLE_STEPS) {
      int pixel_value = get_pixel(IMAGE_SIZE_Y / 2, i, COLOR_WHITE);
      // Add to counter if a pixel is 'white enough' to be part of a line
      if (pixel_value > STOP_THRESHOLD) {
        threshold_count++;
      }
      movement += (i - IMAGE_SIZE_X / 2) * pixel_value;
    }
    // Break if there are not enough 'line worthy' pixels
    if (threshold_count < STOP_COUNT) {
      break;
    }
    if (movement < 0) {
      turn(-5);
    } else if (movement > 0) {
      turn(5);
    } else {
      reset_turn();
    }
    Sleep(0, UPDATE_DELAY);
  }
  halt();
}
