#include "HardwareSerial.h"
#include "Arduino.h"
#include "Motor.h"


Motor::Motor(int fwd, int bwd, int pwm, Side s){
  pinMode(fwd, OUTPUT);
  pinMode(bwd, OUTPUT);
  pinMode(pwm, OUTPUT);
  _fwd = fwd;
  _bwd = bwd;
  _pwm = pwm;
  _side = s;
}

int Motor::get_pins(){
  return digitalRead(_fwd);
}


void Motor::Straight_cm(int distance){
  digitalWrite(_fwd, HIGH);
  digitalWrite(_bwd, LOW);
  analogWrite(_pwm, distance);
}


void Motor::Stop(){
  digitalWrite(_fwd, LOW);
  digitalWrite(_bwd, LOW);
  analogWrite(_pwm, 0);
}


void Motor::Backwards(int pwm){
  digitalWrite(_fwd, LOW);
  digitalWrite(_bwd, HIGH);
  analogWrite(_pwm, pwm);
}


void Motor::Turn_Left(){
  if (_side == Right){
    digitalWrite(_fwd, HIGH);
    digitalWrite(_bwd, LOW);
    analogWrite(_pwm, 255);

    delay(700);
    
    digitalWrite(_fwd, LOW);
    digitalWrite(_bwd, LOW);
    analogWrite(_pwm, 0);
  }
}


void Motor::Turn_Right(){
  if (_side == Left){
    digitalWrite(_fwd, HIGH);
    digitalWrite(_bwd, LOW);
    analogWrite(_pwm, 255);

    delay(700);
    
    digitalWrite(_fwd, LOW);
    digitalWrite(_bwd, LOW);
    analogWrite(_pwm, 0);

  }
}


void Motor::Single_Point_Turn(Side s){
  if (s == Left and _side == Right){
    digitalWrite(_fwd, HIGH);
    digitalWrite(_bwd, LOW);
    analogWrite(_pwm, 255);
  }

  else if(s == Left and _side == Left){
    digitalWrite(_fwd, LOW);
    digitalWrite(_bwd, HIGH);
    analogWrite(_pwm, 255);
  }

  else if(s == Right and _side == Right){
    digitalWrite(_fwd, LOW);
    digitalWrite(_bwd, HIGH);
    analogWrite(_pwm, 255);
  }


  else if(s == Right and _side == Left){
    digitalWrite(_fwd, HIGH);
    digitalWrite(_bwd, LOW);
    analogWrite(_pwm, 255);
  }
}


void Motor::Slow_Down(int slow_down_pwm){
  digitalWrite(_fwd, HIGH);
  digitalWrite(_bwd, LOW);
  analogWrite(_pwm, slow_down_pwm);
}


