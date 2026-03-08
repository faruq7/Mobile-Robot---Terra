#ifndef ULtrasonic_Test_H
#define ULtrasonic_Test_H

#include <Arduino.h>

class Ultrasonic_Test{

  public:
    Ultrasonic_Test();
    float get_distance();
    void debug();
    float distance = 0;

  private:
    const int Trig = 52;
    const int Echo = 53;
    
};


#endif