//It's a mess, but I have till next Wednesday to not make it a mess, bear with me

#include <stdio.h>
#include <cmath>
#include <string.h>

void deadendbackup() 
{
  while (front<50 && (left<50 || right<50))
  {
    set_motor(MOTOR_LEFT, (-SPEED_DEF));
    set_motor(MOTOR_RIGHT, (-SPEED_DEF));
  }
  
  int left_speed = SPEED_DEF - amount;
  int right_speed = SPEED_DEF + amount;
  
  if((left > 50))
  {
  set_motor(MOTOR_LEFT, left_speed);
  }
  else if(right > 50)
  {
  set_motor(MOTOR_RIGHT, right_speed);
  }

}
