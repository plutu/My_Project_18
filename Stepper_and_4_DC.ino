/*Combine a stepper with four DC motors
 * 
 */

//using the stepper's lil green board, plug the motor directly into the board
#include <StepperAK.h>
#include <AFMotor.h>


AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

#define pin1  9//these are the Arduino pins that we use to activate coils 1-4 of the stepper motor
#define pin2  10
#define pin3  13
#define pin4  2

#define delaytime 10   //delay time in ms to control the stepper motor delaytime.
                      //Our tests showed that 8 is about the fastest that can yield reliable operation w/o missing steps


void setup() {

  Serial.begin(9600);

// initialize the stepper's pins as output:
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT); 
  pinMode(pin3, OUTPUT); 
  pinMode(pin4, OUTPUT);

// set dc motor speed
  /*motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);*/

  
}

void loop() {

  Serial.println("forward");
  // forwards!
  
  motor1.run(FORWARD);
  motor3.run(FORWARD);

  delay(5000);      
  motor1.setSpeed(255);
  motor3.setSpeed(255);
  delay(5000);      
  motor1.setSpeed(0);
  motor3.setSpeed(0);
  delay(1000);

  //backwards!
  Serial.println("reverse");
  motor1.run(BACKWARD);
  motor3.run(BACKWARD);

  delay(5000);      
  motor1.setSpeed(255);
  motor3.setSpeed(255);
  delay(5000);      
  motor1.setSpeed(0);
  motor3.setSpeed(0);
  delay(1000);

  //portward
  motor2.run(FORWARD);
  motor4.run(FORWARD);
  delay(5000);      
  motor2.setSpeed(255);
  motor4.setSpeed(255);
  delay(5000);      
  motor2.setSpeed(0);
  motor4.setSpeed(0);
  delay(1000);

  //starboard
  motor2.run(BACKWARD);
  motor4.run(BACKWARD);
  delay(5000);      
  motor2.setSpeed(255);
  motor4.setSpeed(255);
  delay(5000);      
  motor2.setSpeed(0);
  motor4.setSpeed(0);
  delay(1000);


  //TURNING
  Serial.println("turn");
  motor1.run(FORWARD);
  motor3.run(BACKWARD);
  motor1.setSpeed(255);
  motor3.setSpeed(255);
  delay(5000);      
  motor1.setSpeed(0);
  motor3.setSpeed(0);
  delay(1000);


  //open and close door
  Serial.println("Stepper forward");
  int numberOfSteps = 96;
  step_OFF();         //turning all coils off
  while(numberOfSteps>0){
    forward();        //going forward
    numberOfSteps -- ;//counting down the number of steps
    //delay(100);
    Serial.println(numberOfSteps);
  }
  delay(2000);

/***********
 * So right now there's a bug where the first stepper loop runs really fast, and the second runs really slowly. Why?
 */

  Serial.println("Stepper backward");
  step_OFF();         //turning all coils off
  numberOfSteps = 96;
  while(numberOfSteps>0){
    forward();       //going backward
    numberOfSteps -- ;//counting down the number of steps
    //delay(100);
    Serial.println(numberOfSteps);

  delay(2000);

}
}
