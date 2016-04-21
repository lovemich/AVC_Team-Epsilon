#include "linefollow.h"
#include "movement.h"
#include "extern.h"

void follow_line() {
  take_picture();
  int total = 0;
  for (int i; i < IMAGE_SIZE_X; i += SAMPLE_STEPS) {
    int pixel_value = get_pixel(IMAGE_SIZE_Y / 2, i, COLOR_WHITE);
    total += (i - IMAGE_SIZE_X / 2) * pixel_value;
  }
  if (total < 0) {
    turn(-5);
  } else if (total > 0) {
    turn(5);
  } else {
    reset_turn();
  }
  Sleep(0, UPDATE_DELAY);
}
