//Motor users D8-13
#define TP 4      //Trig_pin
#define EP 7      //Echo_pin
#define SERVO1_SIGNAL 3
#define ON_OFF_PIN 2
#define __PROTO_DEBUG__ 0

 //PWM
 //3, 5, 6, 9, 10, and 11
 //*  Arduino analog input 5 - I2C SCL
 //*  Arduino analog input 4 - I2C SDA


#include <Arduino.h>
#include <Servo.h>
#include <Wire.h>

#include "RangeFinder.h"
#include "MotorDriver.h"
#include "SimpleTimer.h"
#include "ThreeDCompass.h"

#include "Data.h"
#include "Motivator.h"
#include "ProtoMotivator.h"

ProtoMotivator motivator;
Servo frontServo;
bool run;

/////////////////////////////////////////////////
/// Setup
////////////////////////////////////////////////
void setup() 
{
  //Setup serial
  Serial.begin(9600);      // init serial 9600

  Serial.println("*************************************");
  Serial.println("***************Startup***************");
  Serial.println("*************************************");

  pinMode(ON_OFF_PIN, INPUT);
  run = true;
  
  //timer
  Serial.println("Init timer...");
  simpleTimer.init();

  //compass
  compass.init();

  //Configure the motor A to control the wheel at the left side.
  //Configure the motor B to control the wheel at the right side.
  Serial.println("Init motor driver...");
  motordriver.init();
  motordriver.setSpeed(255,MOTORA);
  motordriver.setSpeed(255,MOTORB);
  
  //configure rangefinder
  Serial.println("Init rangefinder...");
  rangeFinder.init(TP, EP);
  frontServo.attach(SERVO1_SIGNAL);
  data.FrontServo = &frontServo;
}

/////////////////////////////////////////////////
/// Main loop tick.
////////////////////////////////////////////////
void loop()
{
#if __PROTO_DEBUG__
  Serial.println("*** Tick Start");
#endif
  
  if (!run && digitalRead(ON_OFF_PIN))
    run = true;

  //Timer update
  simpleTimer.update();

  //Motivate
  if (run)
    motivator.motivate();


#if __PROTO_DEBUG__
  Serial.println("--- Tick End");
#endif
}
