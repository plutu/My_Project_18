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
  dc_move(motor1,motor3,BACKWARD,10000); 

}
#include <StepperAK.h>
#include <AFMotor.h>

  AF_DCMotor motor1(1);//forward/backward
  AF_DCMotor motor2(2);//sideways
  AF_DCMotor motor3(3);//forward/backward
  AF_DCMotor motor4(4);//sideways

  //stepper pins
  #define pin1  9//these are the Arduino pins that we use to activate coils 1-4 of the stepper motor
  #define pin2  10
  #define pin3  13
  #define pin4  2
  
  #define delaytime 10   //delay time in ms to control the stepper motor delaytime.
                        //Our tests showed that 8 is about the fastest that can yield reliable operation w/o missing steps

  int sidewaystime = 3000; //how long does it take to reach the other side? (test this)
  int howfarwevecome = 0;
  int pausetime = 100; //this is how long we wait in between ultrasonic measurements
  int linewidth = 300; //in ms, this is how far we advance per line
  int linesdone = 0
  int numberofstepstoopendoor = 90 //need to test this experimentally
void setup() {
  // put your setup code here, to run once:
  
 
}

void loop() {
  linesdone+=1
  strip(FORWARD);
  strip(BACKWARD); //make sure that we end up on the right hand edge, so that we don't get stuck around the corner.
  backtobase(linesdone);
  dump(); //dump should include spinning, opening door, reversing, closing door, then spinning again
  /*GENIUS: we can make the reverse part of dump exactly linewidth, which will mean that when we go back to the frontlines
  we'll be one line further forward */
  dc_move(motor1, motor3, FORWARD, linesdone*linewidth)
  
}

