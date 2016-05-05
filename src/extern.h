#ifndef __EXTERN_H__
#define __EXTERN_H__

extern "C" {
  int init(); // InitHardware()
  int read_analog(int ch_adc); // ReadAnalog(int ch_adc)
  int set_motor(int ch_motor, int dir, int speed);
  int Sleep(int sec, int usec);
  int take_picture();
  int get_pixel(int row, int col, int color);
  int connect_to_server(char server_addr[15], int port);
  int send_to_server(char message[24]);
  int receive_from_server(char message[24]);
}

#endif
