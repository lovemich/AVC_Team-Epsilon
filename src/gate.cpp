#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "extern.h"

int open_gate() {
  //Connects to the server IP: 135.195.6.196 port: 22
  char ip[15] = "130.195.6.196";
  connect_to_server(ip, 22);
  //Sends the opening message "please"
  char open[24] = "please";
  send_to_server(open);
  //Receives password back from server
  char message[24] = {0};
  receive_from_server(message);
  send_to_server(message);
  printf("%s", message);
  return 0;
}
