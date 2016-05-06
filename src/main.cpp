#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "extern.h"
#include "gate.h"
#include "linefollow.h"

int main() {
  init();
  open_gate();
  follow_line();
  return 0;
}


