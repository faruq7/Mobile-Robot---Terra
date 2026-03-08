#include "HardwareSerial.h"
#include "Arduino.h"
#include "Ultrasonic_Test.h"

// Define Constructor
Ultrasonic_Test::Ultrasonic_Test(){
  pinMode(Trig,OUTPUT);
  pinMode(Echo, INPUT);
}


//Define Functions

//get_distance - Triggers the sensor and Calculates the distance between object and sensor
float Ultrasonic_Test::get_distance(){
  //Trigger Ultrasonic TOF Sensor
  digitalWrite(Trig,HIGH);
  delayMicroseconds(1000);
  digitalWrite(Trig,LOW);

  // Calculate distance based on pulse 
  float duration = pulseIn(Echo , HIGH);
  distance = (duration/2) / 28.5;

  return distance;
}

// Debug function - displays all valuable data
void Ultrasonic_Test::debug(){
  Serial.println(distance);

}


