#include "WString.h"
#include "HardwareSerial.h"
#include "Arduino.h"
#include "Robot.h"
#include "Ultrasonic_Test.h"
#include "Encoder.h"


// Left Motor
const int AIN_1 = 22;
const int AIN_2 = 23;
const int PWMA = 2;

//Right Motor
const int BIN_1 = 24;
const int BIN_2 = 25;
const int PWMB = 3;


Ultrasonic_Test Plus_Ultra;
Encoder Lhs_Encoder(20,21);
Encoder Rhs_Encoder(18,19);
Motor Lhs_Motor(AIN_1,AIN_2,PWMA, Left);
Motor Rhs_Motor(BIN_1,BIN_2,PWMB, Right);


bool flag_1 = false;
int val = 100;
float distance;

static long prevL = 0;
static long prevR = 0;

float distance_per_pulse = 0.0453;

Robot::Robot(){

}

void Robot::begin(){
  Lhs_Encoder.begin();
  Rhs_Encoder.begin();
  //Serial.println("started");

}

// Stop Robot dead in tracks
void Robot::Stop(){
  Lhs_Motor.Stop();
  Rhs_Motor.Stop();
  flag_1 = false;
  delay(1000);
}

// Robot Drive forward
void Robot::Drive_Forward(){
    Lhs_Motor.Straight_cm(speed);
    Rhs_Motor.Straight_cm(speed);
}


void Robot::Drive_Backwards(){
  Lhs_Motor.Backwards(100);
  Rhs_Motor.Backwards(100);
}






void Robot::Turn_Left(){
  Lhs_Motor.Turn_Left();
  Rhs_Motor.Turn_Left();
}


void Robot::Turn_Right(){
  Lhs_Motor.Turn_Right();
  Rhs_Motor.Turn_Right();
}

void Robot::Point_Turn(Side s){
  Lhs_Motor.Single_Point_Turn(s);
  Rhs_Motor.Single_Point_Turn(s);
  delay(1150);
}


void Robot::Deaccelerate(){
  Encoded_Movement();

  if (distance < 7.5 || distance > 1000) {
    Drive_Backwards();
  }

  if (distance >= 10 && distance <= 20){
    Lhs_Motor.Slow_Down(50);
    Rhs_Motor.Slow_Down(50);
  }
  else if(distance > 20 && distance <= 30){
    Lhs_Motor.Slow_Down(80);
    Rhs_Motor.Slow_Down(80);
  }
  else if(distance > 40 && distance <= 50){
    Lhs_Motor.Slow_Down(120);
    Rhs_Motor.Slow_Down(120);
  }
  else if(distance > 50 && distance <= 60){
    Lhs_Motor.Slow_Down(160);
    Rhs_Motor.Slow_Down(160);
  }
  else if(distance > 60 && distance <= 100){
    Lhs_Motor.Slow_Down(200);
    Rhs_Motor.Slow_Down(200);
  }
  else if(distance >= 7.5 && distance < 10){
    Stop();
  }

  Encoded_Movement();
}


void Robot::Encoded_Movement(){
  Lhs_Encoder.getCount();
  Rhs_Encoder.getCount();
  //Lhs_Encoder.debug();
  //Rhs_Encoder.debug();

}

float Robot::get_distance(){
  distance = Plus_Ultra.get_distance();
}


void Robot::Ultrasonic_Movement(){
  get_distance();
  Encoded_Correction();

  while (distance > 100 && distance < 1000){
    Drive_Forward(); 
    get_distance();
    Encoded_Correction();

  }

  Deaccelerate();
}



void Robot::Encoded_Correction(){
  long currL = Lhs_Encoder.Get_Pulses();
  long currR = Rhs_Encoder.Get_Pulses();

  long dL = currL - prevL;
  long dR = currR - prevR;

  prevL = currL;
  prevR = currR;

  Encoded_Movement();
  error = dL - dR;
  correction = constrain(Kp * error,-100,100);

  Serial.println("Display:" + String(error));

  if (error > 0){
    Lhs_Motor.Straight_cm(constrain(speed - correction,0,255));
    Rhs_Motor.Straight_cm(constrain(speed + correction,0,255));
    Serial.println("new RHS speed:" + String(speed + correction));
  }

    if (error < 0){
    Lhs_Motor.Straight_cm(constrain(speed + correction,0,255));
    Rhs_Motor.Straight_cm(constrain(speed - correction,0,255));
    Serial.println("new LHS speed:" + String(speed + correction));
  }

}

void Robot::Reset_Encoder(){
  if (Lhs_Motor.get_pins() == 0  && Rhs_Motor.get_pins() == 0){
    Lhs_Encoder.Reset_Counter();
    Rhs_Encoder.Reset_Counter();
  }
}


void Robot::Set_Speed(int _speed){
  speed = _speed;
}


void Robot::Move_cm(float distance){

  float current_pulse_L = Lhs_Encoder.Get_Pulses();
  float current_pulse_R = Rhs_Encoder.Get_Pulses();

  float pulses_required = distance/distance_per_pulse;

  while(Lhs_Encoder.Get_Pulses() < current_pulse_L + pulses_required){
    Drive_Forward();
  }
  Stop();
  delay(5000);

}













//V2
void Robot::Update_Motion(){

  switch (currentState) {

    case STOP:
      Stop();
      break;

    case FORWARD:
      Drive_Forward();
      break;

    case BACKWARD:
      Turn_Right();
      break;

    case TURN_LEFT:
      Turn_Left();
      break;

    case TURN_RIGHT:
      Turn_Right();
      break;
  }
}






