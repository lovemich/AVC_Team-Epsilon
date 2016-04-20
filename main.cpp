#include <stdio.h>
#include <string.h>

extern "C" {
  int init(); // InitHardware()
  int read_analog(int ch_adc); // ReadAnalog(int ch_adc)
  int set_motor(int ch_motor, int dir, int speed);
  int Sleep(int sec, int usec);
}

// 100% at 255
int speed_base = 127;
int speed_delta_m1 = 0;
int speed_delta_m2 = 0;

int main() {
  init();
  return 0;
}

void move() {
  set_motor(1,  1,  speed_base + speed_delta_m1);
  set_motor(2,  1,  speed_base + speed_delta_m2);
}