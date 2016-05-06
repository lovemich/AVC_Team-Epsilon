#include <string.h>
#include <stdio.h>

#include "extern.h"
#include "gate.h"

char ip[15] = "130.195.6.196";
int port = 1024;
char request[24] = "Please";
char password[24] = "123456";

/**
 * Sends a request to the gate server to open the gate.
 */
void open_gate() {
  // Establishes a connection to the gate's server
  connect_to_server(ip, port);
  // Sends the request to open the gate
  send_to_server(request);
  // Sends the password for the gate
  send_to_server(password);
}
