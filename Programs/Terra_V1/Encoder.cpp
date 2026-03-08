#include "WString.h"
#include "HardwareSerial.h"
#include "Arduino.h"
#include "Encoder.h"

//volatile long Encoder::EncoderCount_A1 = 0;
Encoder* Encoder::instance0 = nullptr;
Encoder* Encoder::instance1 = nullptr;

// Define Constructor
Encoder::Encoder(int a, int b){
  channel_a = a;
  channel_b = b;

}

//Define Functions

//Starts the interrupt function
void Encoder::begin(){
  Serial.println("Encoder : " + String(channel_a) + String(channel_b));
  pinMode(channel_a, INPUT_PULLUP);
  pinMode(channel_b, INPUT_PULLUP);
  
  if (!instance0) {
    instance0 = this;
    attachInterrupt(digitalPinToInterrupt(channel_a), isr0, RISING);
  }
  else if (!instance1) {
    instance1 = this;
    attachInterrupt(digitalPinToInterrupt(channel_a), isr1, RISING);
  }
  
}

void Encoder::isr0() {
    if (instance0) instance0->handleISR();
}

void Encoder::isr1() {
    if (instance1) instance1->handleISR();
}


//Calls the Interrupt to increment Encoder
void Encoder::handleISR(){
  if( digitalRead(channel_a) ){ 
    EncoderCount_A1++;
  }
  else{
    EncoderCount_A1--;
  }
}



long Encoder::Get_Pulses() {
  return EncoderCount_A1;
}

long Encoder::Get_Revs() {
  return EncoderCount_A1 / PPR;
}


void Encoder::getCount() {
    noInterrupts();
    long val = EncoderCount_A1;
    interrupts();
    Serial.println("Encoder" + String(channel_a) +" : " + String(val));
}

void Encoder::Reset_Counter(){
  noInterrupts();
  EncoderCount_A1 = 0;
  Serial.println("Resetting");
  interrupts();
}


void Encoder::debug(){
  Serial.print(String(channel_a) +" Pulses: ");
  Serial.print(Get_Pulses());
  Serial.print(" Revs: ");
  Serial.println(Get_Revs());
}