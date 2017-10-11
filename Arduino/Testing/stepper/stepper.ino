#include <Wire.h>
#include <Adafruit_MotorShield.h>
//#include "utility/Adafruit_PWMServoDriver.h"

void setup() {
  Adafruit_MotorShield AFMS = Adafruit_MotorShield(); 
  //getStepper(steps, port#) steps is how many steps per rev. the motor has.
  //port# - 1 if using m1&m2. 2 if using m3&m4
  Adafruit_StepperMotor *myMotor = AFMS.getStepper(48, 2); 

  Adafruit_StepperMotor setSpeed(60) //rpm
}

void loop() {
  // step(#steps, direction, steptype)

  Adafruit_StepperMotor step(10, FORWARD, SINGLE);
  delay(1000);
  Adafruit_StepperMotor release();
  delay(1000);
  

}
