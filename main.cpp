#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "extern.h"
#include "movement.h"

int main() {
  init();
  move();
  Sleep(1, 0);
  halt();
  return 0;
}


