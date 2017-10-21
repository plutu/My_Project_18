#include <StepperAK.h>
#include <AFMotor.h>
#include <Wire.h> //I2C Arduino Library

#define address 0x1E //0011110b, I2C 7bit address of HMC5883


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
  int numberofstepstoopendoor = 50; //need to test this experimentally
  int collect_time = 50; //the time it takes to move forward enough to collect a magnet
  int spin_180_time = 200; // time it takes to do a 180 --> again, measure experimentally
  int motor_speed = 150; //between 0 and 255
  int wheel_speed = 50; //in cm/s, to be experimentally measured if possible?? This will change when we change motor_speed
  int linetime = linewidth/wheel_speed;
  bool has_mag = false;


  const int trigPin = A2; //Is trigpin what sends out the signal?
  const int echoPin = A1;//and echopin what receives it?
void setup() {
  //ultrasonic setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

 //Initialize Serial and I2C communications for magno
  Wire.begin();
  
  //Put the HMC5883 IC into the correct operating mode
  Wire.beginTransmission(address); //open communication with HMC5883
  Wire.write(0x02); //select mode register
  Wire.write(0x00); //continuous measurement mode
  Wire.endTransmission();

  //Pre-test --- hold up a piece of paper to block the ultrasonic sensor, then press reset button
  if (get_distance() <5){
    pretest();
  }
}

void loop() {

 
  linesdone+=1;
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
    dc_move(motor1, motor3, BACKWARD, linetime*2);
  }
}

