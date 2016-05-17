//It's a mess, but I have till next Wednesday to not make it a mess, bear with me

#include <stdio.h>
#include <cmath>
#include <string.h>

void deadendbackup() 
{
  while (front<50 && left<50 && right<50)
  {
    set_motor(MOTOR_LEFT, (-SPEED_DEF));
    set_motor(MOTOR_RIGHT, (-SPEED_DEF));
  }
  if((left > 50))
  {
  //something to make it turn left
  }
  else if(right > 50)
  {
  //something to make it turn right 
  }

}
