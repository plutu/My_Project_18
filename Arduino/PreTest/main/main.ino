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
                        //Our (StepperAK's) tests showed that 8 is about the fastest that can yield reliable operation w/o missing steps
  //should I use #define instead of declaring integers here?
  int sidewaystime = 3000; //how long does it take to reach the other side? (test this)
  int howfarwevecome = 0;
  int pausetime = 100; //this is how long we wait in between ultrasonic measurements
  int linewidth = 10; //in cm, this is how far we advance per line
  int linesdone = 0;
  int numberofstepstoopendoor = 90; //need to test this experimentally
  int collect_time = 50; //the time it takes to move forward enough to collect a magnet
  int motor_speed = 100; //between 0 and 255
  int wheel_speed = 50; //in cm/s, to be experimentally measured if possible?? This will change when we change motor_speed
  int linetime = linewidth/wheel_speed;
  bool has_mag = false;
  
void setup() {
  // put your setup code here, to run once:
  
 
}

void loop() {
  linesdone+=1
  strip(FORWARD);//left first, then right
  strip(BACKWARD); //make sure that we end up on the right hand edge, so that we don't get stuck around the corner.
  if (has_mag = true){
    backtobase(linesdone);
    dump(); //dump should include spinning, opening door, reversing, closing door, then spinning again
    /*GENIUS: we can make the reverse part of dump exactly linewidth, which will mean that when we go back to the frontlines
    we'll be one line further forward */
    dc_move(motor1, motor3, FORWARD, linesdone*linetime);
  }
  else if (get_distance() > linewidth){
    dc_move(motor1, motor3, FORWARD, linetime);
  }
  else{
    dc_move(motor1, motor3, BACKWARD, linetime*2)
  }
}

