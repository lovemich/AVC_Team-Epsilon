#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "extern.h"
#include "movement.h"

extern "C" {
  int init(); // InitHardware()
  int read_analog(int ch_adc); // ReadAnalog(int ch_adc)
  int set_motor(int ch_motor, int dir, int speed);
  int Sleep(int sec, int usec);
}

int main() {
  init();
  move();
  Sleep(1, 0);
  halt();
  return 0;
}


