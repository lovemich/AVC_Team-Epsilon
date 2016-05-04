#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern "C" int init(int d_lev);
extern "C" int connect_to_server( char server_addr[15],int port);
extern "C" int send_to_server(char message[8]);

int main(){
  init(1);
  //Connects to the server IP: 135.195.6.196 port: 22
  connect_to_server(135.195.6.196, 22);
  //Sends the opening message "please"
  send_to_server("please");
  return 0;
}
