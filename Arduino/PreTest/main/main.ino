#include <StepperAK.h>
#include <AFMotor.h>

  AF_DCMotor motor1(1);
  AF_DCMotor motor2(2);
  AF_DCMotor motor3(3);
  AF_DCMotor motor4(4);

  //stepper pins
  #define pin1  9//these are the Arduino pins that we use to activate coils 1-4 of the stepper motor
  #define pin2  10
  #define pin3  13
  #define pin4  2
  
  #define delaytime 10   //delay time in ms to control the stepper motor delaytime.
                        //Our tests showed that 8 is about the fastest that can yield reliable operation w/o missing steps


void setup() {
  // put your setup code here, to run once:
  
  //hopefully, these two do the same thing! 
  dc_move(motor1,motor3,FORWARD,2000); 
  
  delay(5000);
  
  dc_go(motor1,motor3,FORWARD);
  delay(2000);
  dc_stop(motor1,motor3);
}

void loop() {
  // put your main code here, to run repeatedly:

}
