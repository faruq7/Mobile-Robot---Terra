//Call other libraries and scripts
//#include "Ultrasonic_Test.h"
//#include "Encoder.h"
//#include "Motor.h"
#include "Robot.h"

Robot Terra;


void setup(){
  Serial.begin(115200);  
  Terra.begin();
}




void loop(){
  //Plus_Ultra.get_distance();
  //Serial.print("LHS:  ");
  //Lhs_Encoder.debug();
  //Serial.print("RHS:  ");
  //Rhs_Encoder.debug();
  //Lhs_Encoder.Get_Pulses();
  //Rhs_Encoder.Get_Pulses();
  //Lhs_Encoder.Get_Revs();
  //Rhs_Encoder.Get_Revs();

 //Basic Motion()

  //Terra.Drive_Forward(100);
  //delay(812);
  
/*  Stop();
  Turn_Left();

  Drive_Backwards();
  Stop();
  Turn_Right();
  Stop();
  Point_Turn(Left);
  Stop();
  Point_Turn(Right);
  Stop();

*/
  //Ultrasonic Readings
  //Terra.get_distance();
  
  //Terra.Ultrasonic_Movement();
  //Terra.Set_Speed(120);
  //Terra.Encoded_Correction();


  //Encoded Motion
  //Terra.Encoded_Movement();
  //Terra.Stop();
  
  //Terra.Reset_Encoder();
  Terra.Move_cm(30);


  //delay(200);
}



