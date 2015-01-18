#ifndef Durometer_h
#define Durometer_h

#include <Arduino.h>
#include "AccelStepper.h"

//Pins
int m1DirPin = 4;
int m1StepPin = 5;
//int upButtonPin = 10;
//int DownButtonPin = 11;
int eStopPinTop = 3;
int eStopPinBottom = 2;
int ledPin = 13;

//Debug (change to stop printing to the serial port)
#define PRINT_SERIAL 0

//Constants relating to movement
int maxSpeed = 1600;
int motorSpeed = 1600;
int motorAccel = 10000;
int revolutions = 10;
int stepsPerR = 3200;
int debounceTime = 300;
long goalPos = revolutions*stepsPerR*5;
long lastPress = millis();

AccelStepper stepper1(1,m1StepPin, m1DirPin);

void moveStopTop(){
  if (millis() - lastPress > debounceTime)
    {
      lastPress = millis();
      stepper1.stop();
      stepper1.setCurrentPosition(-2000);
      stepper1.moveTo(0);
      if(PRINT_SERIAL)
	Serial.println("E STOP TOP");
    }
}

void moveStopBottom(){
  if (millis() - lastPress > debounceTime)
    {
      lastPress = millis();
      digitalWrite(ledPin, HIGH);
//      stepper1.stop();
//      stepper1.move(2000);
//      if(PRINT_SERIAL)
//	Serial.println("E STOP BOTTOM");
    }
}

void goUp() {
  if (millis() - lastPress > debounceTime)
    {
   lastPress = millis();
  //     stepper1.moveTo(goalPos);
  //     if(PRINT_SERIAL)
  // 	{
  // 	  Serial.print("Goal: ");
  // 	  Serial.print(goalPos);
  // 	  Serial.println(" DOWN");
  // 	} 
    }
}


#endif
