#ifndef CAL_H
#define CAL_H

#include <Arduino.h>

class Cal {
  public:
    Cal();
    void reset();
    void compute();
    bool sample(int a, bool changed);
    int offset;
    int scale;
  private:
    int _min;
    int _max;
};
#endif
