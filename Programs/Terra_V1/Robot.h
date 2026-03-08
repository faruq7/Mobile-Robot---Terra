#include "Motor.h"

#ifndef Robot_H
#define Robot_H

enum State{
  STOP,
  FORWARD,
  BACKWARD,
  TURN_LEFT,
  TURN_RIGHT
};


class Robot{

  public:
    Robot();
    void begin();
    void Drive_Forward();
    void Drive_Backwards();
    void Stop();
    void Turn_Left();
    void Turn_Right();
    void Point_Turn(Side s);
    void Deaccelerate();

    float get_distance();
    void Ultrasonic_Movement();

    void Encoded_Movement();
    void Encoded_Correction();
    void Reset_Encoder();

    void Update_Motion();
    void Set_Speed(int _speed);

    void Move_cm(float distance);

    State currentState = STOP;
    int speed = 150;

    float Kp = 0.05; 
    int error = 0;
    float correction;


  private:
  

  




};




#endif