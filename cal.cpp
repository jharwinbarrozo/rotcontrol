//Provides calibration objects for each axis
//The offset and scaling factors are accumulated by sampling data

#include "cal.h"

//Public methods

Cal::Cal() {
  //Constructor
  reset();
}

void Cal::reset() {
  //Reset the maximum and minimum values
  _min = 32767;
  _max = -32768;  
}

void Cal::compute() {
  //Compute the offset and scaling factors
  offset = int((long(_max) + long(_min)) / 2L);
  scale = int((long(_max) - long(_min)) / 2L);
}
bool Cal::sample(int a, bool changed) {
  //Process a new calibration sample
  if (a > _max) {
    _max = a;
    compute();
    changed = true;
  }
  if (a < _min) {
    _min = a;
    compute();
    changed = true;
  }
  return changed;
}
