//Provides filters for gyro and motors
#include "fil.h"

//Public methods

Fil::Fil(float Alpha) {
  //Constructor
  alpha = Alpha;
  last = 0;
}

float Fil::lpf(float Value) {
  //Low pass filter - Decrease alpha to increase damping factor
  float result = (alpha * Value) + last * (1 - alpha);
  last = result;
  return result;
}
