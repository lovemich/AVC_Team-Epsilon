#ifndef __EXTERN_H__
#define __EXTERN_H__

extern "C" {
  int init(); // InitHardware()
  int read_analog(int ch_adc); // ReadAnalog(int ch_adc)
  int set_motor(int ch_motor, int dir, int speed);
  int Sleep(int sec, int usec);
}

#endif
