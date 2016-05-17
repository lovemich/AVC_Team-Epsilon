#include <stdio.h>
#include <cmath>
#include <string.h>
#include "extern.h"

int main(){

  init();     //initialises hardware

  int frontSensor = 1;    //tells which sensor is which
  int leftSensor = 2;
  int rightSensor = 3;

  int front;      //decalre integer variables to store the ADC data
  int left;
  int right;


  front = read_analog(1);   //gather values from each sensor
  printf("%d\n", front);
  sleep(0, 5000000);

  left = read_analog(2);
  printf("%d\n", front);
  sleep(0, 5000000);

  right = read_analog(3);
  printf("%d\n", front);
  sleep(0, 5000000);

  if(front<50 && left<50 && right<50){    //if all sensor values are small, then dead end
    return true;
  }


}
